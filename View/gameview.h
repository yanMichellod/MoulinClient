#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "View/view.h"
#include <QString>
#include <QMap>
#include <QPoint>

class GameView : public View
{
    Q_OBJECT
public:
    GameView(int x, int y, int width, int heigth, QString title);
    ~GameView();

private:
    void createPosition();
    void createPiece();
    void createGameBoard();
    QMap<int,QPoint> position ;

    // View interface
public:
    QString getData();

protected:
    void changed();
};

#endif // GAMEVIEW_H
