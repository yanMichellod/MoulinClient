#include "waitingview.h"



WaitingView::WaitingView(int x, int y, int width, int heigth, QString title)
    :View(x,y,width,heigth,title)
{
    setupUI();
}

WaitingView::~WaitingView()
{
    delete info;
}

void WaitingView::setupUI()
{
    info = new QLabel("Server Found\n\nWaiting a second player",this);
    info->setGeometry(10,10,200,200);
    info->setVisible(true);
}

QString WaitingView::getData()
{

}

void WaitingView::changed()
{

}
