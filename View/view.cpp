#include "view.h"

View::View(int x, int y, int width, int heigth, QString title)
{
    this->x = x;
    this->y = y;
    this->height = heigth;
    this->width = width;
    this->title = title;

    setupUI();
}

View::~View()
{

}

QString View::getTitle()
{
    return title;
}

void View::setupUI()
{
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(title);
    this->setVisible(true);
}
