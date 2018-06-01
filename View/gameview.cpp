#include "gameview.h"


GameView::GameView(int x, int y, int width, int heigth, QString title)
    : View(x,y,width,heigth,title)
{
    createPosition();
    createPiece();
    createGameBoard();
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

void GameView::createPiece()
{

}

void GameView::createGameBoard()
{

}

QString GameView::getData()
{

}

void GameView::changed()
{

}
