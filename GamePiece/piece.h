#ifndef PIECE_H
#define PIECE_H
#include <QPoint>
#include <QColor>

class Piece
{
public:
    Piece(QPoint position , QColor color);
    ~Piece();
    QPoint getPosition();
    void setPosition(QPoint position);

private:
    QPoint position;
    QColor color;
};

#endif // PIECE_H
