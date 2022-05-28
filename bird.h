#ifndef BIRD_H
#define BIRD_H

#include <QPoint>
#include <QBrush>
#include <QPainter>


class Bird
{
public:
    Bird(int x, int y);
    void drawBird(QPainter *painter, QImage image);
    int x();
    int y();
    void setX(int newX);
    void setY(int newY);
public:
    QPoint center;
    const int radius = 30;
};

#endif // BIRD_H
