#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "XF/ism.h"

class Data;
class XFEvent;

class Controller: public QObject, public ISM
{
    Q_OBJECT
public:
    Controller();
    ~Controller();
    void startBehaviour();
    void initRelation(Data* data);

private:
    enum CLIENT_STATE{
        ST_NONE , ST_SETSERVER , ST_C0NNECTING , ST_WAITPLAYER , ST_INGAME
    };
    enum CLIENT_EVENT{
        EV_NONE, EV_INIT , EV_SERVERSET , EV_ENDCONNECTION , EV_PLAYERFOUND , EV_GAMEOVER
    };
    enum INGAME_STATE{
         ST_NONEGAME , ST_PLAYERPLAY , ST_PLAYERWAIT
    };
    enum INGAME_EVENT{
         EV_NONEGAME , EV_GAMEBEGIN , EV_PLAYERPLAYED , EV_CHANGEPLAYER , EV_REPLAY
    };

    CLIENT_STATE state;
    INGAME_STATE gamestate;


    Data* data;

    //call the INGAME state machine
    bool callSubtracteInGameMachine(XFEvent *p1);


    // ISM interface
public:
    bool processEvent(XFEvent *p1);

public slots:
    void ipSet();
    void connectedToServer();
    void positionOfGamer();
    void commandEntered();
    void gamebegin();
    void changingPlayer();
    void moulin();
    void replay();
    void gameUpdated();

};

#endif // CONTROLLER_H
