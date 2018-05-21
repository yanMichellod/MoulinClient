#include "factory.h"
#include "QString"
#include "View/setupview.h"
#include "View/waitingview.h"
#include "data.h"
#include "Control/controller.h"
#include "serverconnection.h"

Factory::Factory()
{
    sv = new SetupView(50,50,200,200,"setup");
    wv = new WaitingView(50,50,250,250,"waiting");
    dt = new Data();
    c = new Controller();

}

Factory::~Factory()
{
    delete sv;
    delete wv;
    delete dt;
    delete c;
}

void Factory::build()
{
    dt->subscribe(sv);
    dt->subscribe(wv);
    c->initRelation(dt);
    connect(sv,SIGNAL(ipEntered()),dt,SLOT(ipSet()));
    connect(dt,SIGNAL(ipEntered()),c,SLOT(ipSet()));
    connect(ServerConnection::getInstance(),SIGNAL(connectedToServer()),c, SLOT(connectedToServer()));
}

void Factory::start()
{
    c->startBehaviour();
}
