#ifndef PIPE_H
#define PIPE_H

#include <QRect>
#include <QPainter>
#include <QImage>>

class Pipe
{
public:
    Pipe(QPoint gap_center);
    void drawPipe(QPainter *painter,QImage image_l,  QImage image_u);

public:
    QRect heigher;
    QRect lower;

private:
    QPoint gap_center;

};

#endif // PIPE_H
