#include "pipe.h"

Pipe::Pipe(QPoint gap_center){
    heigher.setX(gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(gap_center.y()-65);

    lower.setX(gap_center.x()-25);
    lower.setY(gap_center.y() + 65);
    lower.setWidth(70);
    lower.setHeight(1000);
}

void Pipe::drawPipe(QPainter *painter,QImage image_l,  QImage image_u)
{
    painter->drawImage(this->lower,image_l);
    painter->drawImage(this->heigher, image_u);
}
