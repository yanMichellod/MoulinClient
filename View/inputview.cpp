#include "inputview.h"



InputView::InputView(int x, int y, int width, int heigth, QString title)
          : View(x,y,width,heigth,title)
{
    setupUI();
    connect(le,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
}

InputView::~InputView()
{
    delete info;
    delete le;
    delete example;
}

void InputView::setupUI()
{
    info = new QLabel("Enter Command :",this);
    info->setGeometry(10,10,200,30);
    info->setVisible(true);

    le = new QLineEdit("place on 6",this);
    le->setGeometry(10,40,200,30);
    le->setVisible(true);

    example = new QLabel("Example : place on 3 , move 6 to 7 , eat 15",this);
    example->setGeometry(10,70,200,30);
    example->setVisible(true);
}

void InputView::onCommandEntered()
{
    data = le->text();
    le->clear();
    emit commandEntered();
}

QString InputView::getData()
{
    return data;
}

void InputView::changed()
{

}

