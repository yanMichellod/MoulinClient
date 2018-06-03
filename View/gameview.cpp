#include "gameview.h"
#include <data.h>
#include "QPainter"
#include <QString>

GameView::GameView(int x, int y, int width, int heigth, QString title)
    : View(x,y,width,heigth,title)
{
    createPosition();
}

GameView::~GameView()
{
}

void GameView::createPosition()
{
    position[0] = QPoint(50,200);
    position[1] = QPoint(150,300);
    position[2] = QPoint(250,400);
    position[3] = QPoint(350,200);
    position[4] = QPoint(350,300);
    position[5] = QPoint(350,400);
    position[6] = QPoint(650,200);
    position[7] = QPoint(550,300);
    position[8] = QPoint(450,400);
    position[9] = QPoint(650,500);
    position[10] = QPoint(550,500);
    position[11] = QPoint(450,500);
    position[12] = QPoint(650,800);
    position[13] = QPoint(550,700);
    position[14] = QPoint(450,600);
    position[15] = QPoint(350,800);
    position[16] = QPoint(350,700);
    position[17] = QPoint(350,600);
    position[18] = QPoint(50,800);
    position[19] = QPoint(150,700);
    position[20] = QPoint(250,600);
    position[21] = QPoint(50,500);
    position[22] = QPoint(150,500);
    position[23] = QPoint(250,500);
}


void GameView::drawGameBoard(QPainter* painter)
{
    // draw corner of the gameboard
    for(int i = 0 ; i < MaxPosition ; i++ ){
        painter->setBrush(Qt::black);
        painter->drawEllipse(position[i],10,10);
    }
    // draw lines of the gameboard
    painter->drawLine(position[0],position[3]);
    painter->drawLine(position[0],position[21]);
    painter->drawLine(position[1],position[4]);
    painter->drawLine(position[1],position[22]);
    painter->drawLine(position[2],position[5]);
    painter->drawLine(position[2],position[23]);
    painter->drawLine(position[3],position[6]);
    painter->drawLine(position[3],position[4]);
    painter->drawLine(position[4],position[5]);
    painter->drawLine(position[4],position[7]);
    painter->drawLine(position[5],position[8]);
    painter->drawLine(position[6],position[9]);
    painter->drawLine(position[7],position[10]);
    painter->drawLine(position[8],position[11]);
    painter->drawLine(position[9],position[10]);
    painter->drawLine(position[9],position[12]);
    painter->drawLine(position[10],position[11]);
    painter->drawLine(position[10],position[13]);
    painter->drawLine(position[11],position[14]);
    painter->drawLine(position[12],position[15]);
    painter->drawLine(position[13],position[16]);
    painter->drawLine(position[14],position[17]);
    painter->drawLine(position[15],position[16]);
    painter->drawLine(position[15],position[18]);
    painter->drawLine(position[16],position[17]);
    painter->drawLine(position[16],position[19]);
    painter->drawLine(position[17],position[20]);
    painter->drawLine(position[18],position[21]);
    painter->drawLine(position[19],position[22]);
    painter->drawLine(position[20],position[23]);
    painter->drawLine(position[21],position[22]);
    painter->drawLine(position[22],position[23]);

    // draw number of the gameboard
    for(int i = 0; i < MaxPosition ; i++){
        painter->drawText(position[i].x()-25,position[i].y()-25,QString::number(i));
    }
}

QString GameView::getData()
{

}

void GameView::changed()
{

}

void GameView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    drawGameBoard(&painter);
}
