#include "bird.h"

Bird::Bird(QPoint center)
{
    this->center = center;
}
void Bird::drawBird(QPainter *painter, QBrush brush)
{
    painter->setBrush(brush);
    painter->drawEllipse(this->center, this->radius, this->radius);
}
