#include "pipe.h"

Pipe::Pipe(QPoint gap_center)
{
    this->gap_center = gap_center;

    heigher.setX(this->gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(this->gap_center.y()-65);

    lower.setX(this->gap_center.x()-25);
    lower.setY(this->gap_center.y() + 65);
    lower.setWidth(70);
    lower.setHeight(1000);
}

Pipe::Pipe(int x, int y)
{
    gap_center.setX(x);
    gap_center.setY(y);

    heigher.setX(this->gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(this->gap_center.y()-65);

    lower.setX(this->gap_center.x()-25);
    lower.setY(this->gap_center.y() + 65);
    lower.setWidth(70);
    lower.setHeight(1000);
}

int Pipe::x()
{
    return gap_center.x();
}

int Pipe::y()
{
    return gap_center.y();
}

void Pipe::setX(int newX)
{
    gap_center.setX(newX);

    heigher.setX(this->gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(this->gap_center.y()-65);

    lower.setX(this->gap_center.x()-25);
    lower.setY(this->gap_center.y() + 65);
    lower.setWidth(70);
    lower.setHeight(1000);
}

void Pipe::setY(int newY)
{
    gap_center.setY(newY);

    heigher.setX(this->gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(this->gap_center.y()-65);

    lower.setX(this->gap_center.x()-25);
    lower.setY(this->gap_center.y() + 65);
    lower.setWidth(70);
    lower.setHeight(1000);
}

void Pipe::drawPipe(QPainter *painter,QImage image_l,  QImage image_u)
{
    painter->drawImage(this->lower,image_l);
    painter->drawImage(this->heigher, image_u);
}
