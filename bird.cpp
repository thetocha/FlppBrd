#include "bird.h"

Bird::Bird(int x, int y)
{
    center.setX(x);
    center.setY(y);
}
void Bird::drawBird(QPainter *painter, QImage image)
{
   // painter->setBrush(brush);
   // painter->drawEllipse(this->center, this->radius, this->radius);
    painter->drawImage(this->center,image);
}
int Bird::x(){
    return this->center.x();
}

int Bird::y(){
    return this->center.y();
}

void Bird::setX(int newX){
    this->center.setX(newX);
}

void Bird::setY(int newY){
    this->center.setY(newY);
}
