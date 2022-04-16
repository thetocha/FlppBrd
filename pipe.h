#ifndef PIPE_H
#define PIPE_H

#include <QRect>
#include <QPainter>
#include <QBrush>

class Pipe
{
public:
    Pipe(QPoint gap_center);
    void drawPipe(QPainter *painter,QBrush brush,  QBrush brush_u);

public:
    QRect heigher;
    QRect lower;

private:
    QPoint gap_center;

};

#endif // PIPE_H
