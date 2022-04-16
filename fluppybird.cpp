#include "fluppybird.h"
#include "ui_fluppybird.h"

#include "pipe.h"

#include <vector>
#include <QPoint>
#include <random>
#include <QPainter>
#include <QBrush>
#include <QRect>
#include <QTimer>
#include <QImage>

FluppyBird::FluppyBird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FluppyBird)
{
    ui->setupUi(this);

    std::random_device rdGen;
    std::mt19937 gen(rdGen());
    std::uniform_int_distribution<> dis0_15(50, this->height() - 50);

    int distance = -50;

    for(int i=0; i < 4; ++i )
    {
        QPoint point(this->width() + distance,dis0_15(gen));
        points.push_back(point);
        distance += 300;
    }

    QTimer* ptimer = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(movePipes()));
    ptimer->start(25);

}

void FluppyBird::movePipes(){
    std::random_device rdGen;
    std::mt19937 gen1(rdGen());
    std::uniform_int_distribution<> dis0_15(50, this->height() - 50);
    for(int i=0; i < points.size(); ++i )
    {
        points[i].setX(points[i].x() + speed);
        if(points[i].x() + 35 <= 0)
        {
            points[i].setX(this->width() + 400);
            points[i].setY(dis0_15(gen1));
        }
    }

   this->update();
}




void FluppyBird::paintEvent(QPaintEvent *event){
      Pipe pipe1(this->points[0]);
      Pipe pipe2(this->points[1]);
      Pipe pipe3(this->points[2]);
      Pipe pipe4(this->points[3]);

      QPainter painter(this);
      QImage bckg(":/new/prefix1/2346_Flappy_Bird_res/bg1.png", "PNG");
      QBrush brushBack(bckg);
      QImage lower_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_lower.png","PNG");
      QBrush lowerB(lower_pipe);
      QImage uppper_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_upper.png", "PNG");
      QBrush upperB(uppper_pipe);

      painter.fillRect(0,0,this->width(), this->height(),brushBack);
      pipe1.drawPipe(&painter, lowerB, upperB);
      pipe2.drawPipe(&painter, lowerB, upperB);
      pipe3.drawPipe(&painter, lowerB, upperB);
      pipe4.drawPipe(&painter, lowerB, upperB);

}

FluppyBird::~FluppyBird()
{
    delete ui;
}
