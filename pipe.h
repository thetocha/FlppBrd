#ifndef PIPE_H
#define PIPE_H

#include <QRect>
#include <QPainter>
#include <QImage>
class Pipe
{
public:
    Pipe(QPoint gap_center);
    Pipe(int x, int y);
    int x();
    int y();
    void setX(int newX);
    void setY(int newY);
    void drawPipe(QPainter *painter,QImage image_l,  QImage image_u);

public:
    QRect heigher;
    QRect lower;

private:
    QPoint gap_center;

};

#endif // PIPE_H
