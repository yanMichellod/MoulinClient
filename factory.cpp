#include "factory.h"
#include "QString"
#include "View/setupview.h"
#include "View/waitingview.h"
#include "View/inputview.h"
#include "data.h"
#include "Control/controller.h"
#include "serverconnection.h"


Factory::Factory()
{
    sv = new SetupView(50,50,200,200,"setup");
    sv->setVisible(false);
    wv = new WaitingView(50,50,250,250,"waiting");
    wv->setVisible(false);
    iv = new InputView(50,800,300,200,"input");
<<<<<<< HEAD
    iv->setVisible(true);
=======
    iv->setVisible(false);
>>>>>>> d6447075ae57a28cea3387f4de72e7734cbfa54f
    dt = new Data();
    c = new Controller();

}

Factory::~Factory()
{
    delete sv;
    delete wv;
    delete iv;
    delete dt;
    delete c;
}

void Factory::build()
{
    dt->subscribe(sv);
    dt->subscribe(wv);
    dt->subscribe(iv);
    c->initRelation(dt);
    connect(sv,SIGNAL(ipEntered()),dt,SLOT(ipSet()));
    connect(dt,SIGNAL(ipEntered()),c,SLOT(ipSet()));
    connect(ServerConnection::getInstance(),SIGNAL(connectedToServer()),c, SLOT(connectedToServer()));
    connect(ServerConnection::getInstance(),SIGNAL(positionOfGamer()),c,SLOT(positionOfGamer()));
    connect(ServerConnection::getInstance(),SIGNAL(gamebegin()),c,SLOT(gamebegin()));
    connect(iv,SIGNAL(commandEntered()),dt,SLOT(commandEntered()));
    connect(dt,SIGNAL(commandToControl()),c,SLOT(commandEntered()));
}

void Factory::start()
{
    c->startBehaviour();
}
