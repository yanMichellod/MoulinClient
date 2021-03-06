#include "setupview.h"


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

    le = new QLineEdit("153.109.7.46",this);
    le->setGeometry(10,30,150,20);
    le->setVisible(true);
    le->setEnabled(true);

    port = new QLabel("Port number : 3333",this);
    port->setGeometry(10,70,150,10);
    port->setVisible(true);
}

void SetupView::onCommandEntered()
{
    data = le->text();
    le->clear();
    emit ipEntered();
}

void SetupView::changed()
{

}

QString SetupView::getData()
{
    return data;
}
