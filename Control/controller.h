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
        EV_NONE, EV_INIT , EV_SERVERSET , EV_ENDCONNECTION ,EV_PLAYERFOUND
    };
    CLIENT_STATE state;

    Data* data;
    // ISM interface
public:
    bool processEvent(XFEvent *p1);

public slots:
    void ipSet();

};

#endif // CONTROLLER_H
