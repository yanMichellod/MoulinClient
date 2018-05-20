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
    data = nullptr;
}

Controller::~Controller()
{
    delete data;
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

bool Controller::processEvent(XFEvent *p1)
{
    bool retVal = false;

    //State machine begin
    qDebug() << p1->getID();
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
        }
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

            break;
        }
        case ST_INGAME:{

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

            break;
        }
        case ST_INGAME:{

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

