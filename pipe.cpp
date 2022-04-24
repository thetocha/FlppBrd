#include "pipe.h"

Pipe::Pipe(QPoint gap_center){
    heigher.setX(gap_center.x()-25);
    heigher.setY(0);
    heigher.setWidth(70);
    heigher.setHeight(gap_center.y()-70);

    lower.setX(gap_center.x()-25);
    lower.setY(gap_center.y() + 70);
    lower.setWidth(70);
    lower.setHeight(1000);
}

void Pipe::drawPipe(QPainter *painter,QImage image_l,  QImage image_u)
{
//    painter->drawRect(this->lower);
//    painter->drawRect(this->heigher);
//    painter->fillRect(this->lower, brush_l);
//    painter->fillRect(this->heigher, brush_u);

    painter->drawImage(this->lower,image_l);
    painter->drawImage(this->heigher, image_u);
}
