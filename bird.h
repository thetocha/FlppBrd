#ifndef BIRD_H
#define BIRD_H

#include <QPoint>
#include <QBrush>
#include <QPainter>


class Bird
{
public:
    Bird(QPoint center);
    void drawBird(QPainter *painter, QBrush brush);
public:
    QPoint center;
    const int radius = 30;
};

#endif // BIRD_H
