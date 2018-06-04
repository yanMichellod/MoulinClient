#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "View/view.h"
#include <QString>
#include <QMap>
#include <QPoint>

class Data;

class GameView : public View
{
    Q_OBJECT
public:
    GameView(int x, int y, int width, int heigth, QString title);
    ~GameView();
    void initRelation(Data* d);

private:
    void createPosition();
    void drawGameBoard(QPainter* painter);
    void drawPiece(QPainter* painter);
    QMap<int,QPoint> position ;
    Data* data;

    // View interface
public:
    QString getData();

protected:
    void changed();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void gameUpdated();
};

#endif // GAMEVIEW_H
