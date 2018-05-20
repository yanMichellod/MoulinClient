#include "factory.h"
#include "QString"
#include "View/setupview.h"
#include "data.h"
#include "Control/controller.h"

Factory::Factory()
{
    sv = new SetupView(50,50,200,200,"setup");
    dt = new Data();
    c = new Controller();

}

Factory::~Factory()
{
    delete sv;
    delete dt;
    delete c;
}

void Factory::build()
{
    dt->subscribe(sv);
    c->initRelation(dt);
    connect(sv,SIGNAL(ipEntered()),dt,SLOT(ipSet()));
    connect(dt,SIGNAL(ipEntered()),c,SLOT(ipSet()));
}

void Factory::start()
{
    c->startBehaviour();
}
