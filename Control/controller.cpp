#include "controller.h"
#include <XF/xfevent.h>
#include <XF/xf.h>
#include <QDebug>
#include <serverconnection.h>
#include "data.h"
#include <XF/ism.h>
#include "View/view.h"



Controller::Controller()
{
    state = ST_NONE;
    gamestate = ST_NONEGAME;
    data = nullptr;
}

Controller::~Controller()
{
}

void Controller::startBehaviour()
{
    XFEvent* ev = new XFEvent();
    ev->setID((int)EV_INIT);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);
}

void Controller::initRelation(Data *data)
{
    this->data = data;
}

bool Controller::callSubtracteInGameMachine(XFEvent *p1)
{
    bool retVal = false;

    //subtracte INGAME state machine begin
    INGAME_STATE oldstate = gamestate;

    // double switch pattern
    switch(gamestate){
    case ST_NONEGAME:{
        if (p1->getID() == EV_GAMEBEGIN){

            if(data->getPlayer() == 1){
                gamestate = ST_PLAYERPLAY;
            }
            else if(data->getPlayer() == 2){
                gamestate = ST_PLAYERWAIT;
            }
        }
        break;
    }
    case ST_PLAYERPLAY:{
        if(p1->getID() == EV_PLAYERPLAYED){
            if(data->isMoulin() == true){
                gamestate = ST_PLAYERPLAY;
            }
            else{
                gamestate = ST_PLAYERWAIT;
            }
        }
        break;
    }
    case ST_PLAYERWAIT:{
        if(p1->getID() == EV_CHANGEPLAYER){
            gamestate = ST_PLAYERPLAY;
        }
        break;
    }
    }
    if(oldstate != gamestate){
        retVal = true;
        //do action on exit
        switch(oldstate){
        case ST_PLAYERPLAY:{
            break;
        }
        case ST_PLAYERWAIT:{
            break;
        }
        }

        //do action in entry
        switch(gamestate){
        case ST_PLAYERPLAY:{
            data->enableWindow("input" , true);
            break;
        }
        case ST_PLAYERWAIT:{
            data->enableWindow("input" , false);
            break;
        }
        }

    }
    return retVal;
}

bool Controller::processEvent(XFEvent *p1)
{
    bool retVal = false;

    //State machine begin
    CLIENT_STATE oldstate = state;

    //Double switch pattern

    switch(state){
    case ST_NONE :{
        if (p1->getID() == EV_INIT){
            state = ST_SETSERVER;
        }
        break;

    }

    case ST_SETSERVER :{
        if (p1->getID() == EV_SERVERSET){
            state = ST_C0NNECTING;
        }
        break;
    }

    case ST_C0NNECTING :{
        if(p1->getID() == EV_ENDCONNECTION){
            if(ServerConnection::getInstance()->isConnected() == true){
                state = ST_WAITPLAYER;
            }
            else{
                state = ST_SETSERVER;
            }
        }
        break;
    }

    case ST_WAITPLAYER:{
        if(p1->getID() == EV_PLAYERFOUND){
            state = ST_INGAME;


            //begin the game
            XFEvent* ev = new XFEvent();
            ev->setID((int)EV_GAMEBEGIN);
            ev->setTarget(this);
            XF::getInstance().pushEvent(ev);

        }
        break;
    }
    case ST_INGAME : {
        if(p1->getID() == EV_GAMEOVER){
            state = ST_WAITPLAYER;
            break;
        }

        callSubtracteInGameMachine(p1);
        break;
    }
    }

    if(oldstate != state){
        retVal = true;

        //do action on exit
        switch(oldstate){

        case ST_SETSERVER: {

            break;
        }
        case ST_C0NNECTING:{
            data->setVisible("setup",false);

            break;
        }
        case ST_WAITPLAYER:{
            data->setVisible("waiting",false);

            break;
        }
        case ST_INGAME:{
            data->setVisible("input",false);

            break;
        }
        };

        //do action in entry
        switch(state){

        case ST_SETSERVER:{
            data->setVisible("setup",true);

            break;
        }
        case ST_C0NNECTING:{
            ServerConnection::getInstance()->connectToServer();

            break;
        }
        case ST_WAITPLAYER:{
            data->setVisible("waiting",true);

            break;
        }
        case ST_INGAME:{
            data->setVisible("input",true);
            break;
        }
        }
    }
    return retVal;
}

void Controller::ipSet()
{
    ServerConnection::getInstance()->setIPAdress((data->getView("setup"))->getData());
    XFEvent* ev = new XFEvent();
    ev->setID((int)EV_SERVERSET);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);
}

void Controller::connectedToServer()
{
    XFEvent* ev = new XFEvent();
    ev->setID((int)EV_ENDCONNECTION);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);
}

void Controller::positionOfGamer()
{
    if(ServerConnection::getInstance()->getMessage().contains("1")){
        data->setPlayer(1);
    }
    else if(ServerConnection::getInstance()->getMessage().contains("2")){
        data->setPlayer(2);
    }
}

void Controller::commandEntered()
{
    QString command = data->getView("input")->getData();
    // test different command
    // command place
    if (command.contains("place") == 0){
        bool placed = false;
        for(int i = MaxPosition ; i >= 0 ; i--){
            if(command.contains(i) == 0 && placed == false){
                data->setTocken(i,data->getPlayer());
                placed == true;
            }
        }
    }

    // command move
    else if(command.contains("move") == 0){

    }
    else if(command.contains("eat") == 0){

    }
    QByteArray msg;
    int* tocken = data->getTocken();

    // create message
    for(int i = 0 ; i < MaxPosition ; i++){
        msg.append(tocken[i]);
    }

    ServerConnection::getInstance()->send(msg);

    // player played
    XFEvent* ev = new XFEvent();
    ev->setID((int)EV_PLAYERPLAYED);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);
}

void Controller::gamebegin()
{
    XFEvent* ev = new XFEvent();
    ev->setID((int)EV_PLAYERFOUND);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);
}

