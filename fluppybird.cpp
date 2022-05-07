#include "fluppybird.h"
#include "ui_fluppybird.h"

FluppyBird::FluppyBird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FluppyBird)
{
    ui->setupUi(this);

    bird_center.setX(400);
    bird_center.setY(300);

    std::random_device rdGen;
    std::mt19937 gen(rdGen());
    std::uniform_int_distribution<> dis0_15(70, this->height() - 80);

    int distance = -50;

    for(int i=0; i < 3; ++i )
    {
        QPoint point(this->width() + distance,dis0_15(gen));
        points.push_back(point);
        distance += 400;
    }

    QTimer* ptimer = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(moveObjects()));
    ptimer->start(25);

}

void FluppyBird::moveObjects()
{
    std::random_device rdGen;
    std::mt19937 gen1(rdGen());
    std::uniform_int_distribution<> dis0_15(70, this->height() - 80);

    for(int i=0; i < points.size(); ++i )
    {
        points[i].setX(points[i].x() + pipe_speed);
        if(points[i].x() + 35 <= 0)
        {
            points[i].setX(this->width() + 400);
            points[i].setY(dis0_15(gen1));
        }
    }


   this->bird_center.setY(this->bird_center.y() + bird_speed);
   bird_speed += 2;

   if(this->Intersections()){
       bird_speed = 5;
       pipe_speed = 0;
   }

   this->update();
}




void FluppyBird::paintEvent(QPaintEvent *event)
{
      Pipe pipe1(this->points[0]);
      Pipe pipe2(this->points[1]);
      Pipe pipe3(this->points[2]);

      QPainter painter(this);
      QImage bckg(":/new/prefix1/2346_Flappy_Bird_res/bckg1.png", "PNG");
      QBrush brushBack(bckg);
      QImage lower_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_low.png","PNG");
      QBrush lowerB(lower_pipe);
      QImage uppper_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_upp.png", "PNG");


      painter.fillRect(0,0,this->width(), this->height(),brushBack);
      pipe1.drawPipe(&painter, lower_pipe, uppper_pipe);
      pipe2.drawPipe(&painter, lower_pipe, uppper_pipe);
      pipe3.drawPipe(&painter, lower_pipe, uppper_pipe);


      Bird bird(this->bird_center);
      QImage birdIm(":/new/prefix1/2346_Flappy_Bird_res/bird.png", "PMG");
      QBrush birdB(birdIm);
      bird.drawBird(&painter, birdIm);

}

void FluppyBird::keyPressEvent(QKeyEvent *event)
{
     if(event->key() == Qt::Key_Space)
    {
        this->bird_speed = -10;
    }
}


bool FluppyBird::Intersections()
{
    if(bird_center.y()  >= this->height()){
        return true;
    }

    for(int i = 0; i < points.size(); ++i){
        if((bird_center.x() + 37 > points[i].x() - 35 && bird_center.x() + 37 <  points[i].x() + 45 ) &&
            (bird_center.y() < points[i].y() - 65  || bird_center.y() + 30 > points[i].y() + 65)){
                return true;
            }else{
                return false;
            }
    }

}

//    if(bird_center.x() + 37 > points[i].x() - 35 && bird_center.x() + 37 < points[i].x() + 35 ){
//        if(bird_center.y() > points[i].y() + 65  || bird_center.y() < points[i].y() - 12){
//            return true;
//        }else{
//            return false;
//        }
//    }else{
//        return false;
//    }
//}

//void FluppyBird::StopGame()
//{
//    if(this->Intersection()){
//        bird_speed = 5;
//        pipe_speed = 0;
//    }
//}




FluppyBird::~FluppyBird()
{
    delete ui;
}
