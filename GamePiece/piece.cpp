#include "piece.h"


Piece::Piece(QPoint position, QColor color)
{
    this->position = position;
    this->color = color;
}

Piece::~Piece()
{
}

QPoint Piece::getPosition()
{
    return position;
}

void Piece::setPosition(QPoint position)
{
    this->position = position;
}
