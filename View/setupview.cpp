#include "setupview.h"
#include "serverconnection.h"
#include <XF/xfevent.h>
#include <XF/xf.h>

SetupView::SetupView(int x, int y, int width, int heigth, QString title)
          : View(x,y,width,heigth,title)
{
    setupUI();
    connect(le,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
}

SetupView::~SetupView()
{
    delete ip;
    delete le;
    delete port;
}

void SetupView::setupUI()
{
    ip = new QLabel("IP Adress :",this);
    ip->setGeometry(10,10,100,10);
    ip->setVisible(true);

    le = new QLineEdit("enter IP adress ...",this);
    le->setGeometry(10,30,100,20);
    le->setVisible(true);

    port = new QLabel("Port number : 3333",this);
    port->setGeometry(10,70,100,10);
    port->setVisible(true);
}

void SetupView::onCommandEntered()
{
    ServerConnection::getInstance()->setIPAdress(le->text());
    emit ipEntered();
}

void SetupView::changed()
{

}

void SetupView::initRelation(Data *d)
{
    data = d;
}
