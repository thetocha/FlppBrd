#include "fluppybird.h"
#include "ui_fluppybird.h"

FluppyBird::FluppyBird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FluppyBird)
    , isDead(false)
    , pipe_speed(-4)
    , bird_speed(0)
    , counter(0)



{
    ui->setupUi(this);


    std::random_device rdGen;
    std::mt19937 gen(rdGen());
    std::uniform_int_distribution<> dis0_15(70, this->height() - 80);

    int distance = -50;


    for(int i=0; i < 3; ++i )
    {
        Pipes[i] =  new Pipe(this->width() + distance, dis0_15(gen));
        distance += 400;
    }

    connect(main_timer, SIGNAL(timeout()), SLOT(moveObjects()));
    connect(ui->StartButtom, SIGNAL(clicked()), SLOT(StartTheGame()));
    connect(ui->RestartButtom, SIGNAL(clicked()), SLOT(RestartTheGame()));
    connect(ui->SettingspushButton, SIGNAL(clicked()), SLOT(OpenSettings()));
    connect(ui->CloseButton, SIGNAL(clicked()), SLOT(CloseSettings()));
    connect(ui->birdDefaultButton, SIGNAL(clicked()), SLOT(BirdDefault()));
    connect(ui->pipeDefaultButton, SIGNAL(clicked()), SLOT(PipeDefault()));
    connect(ui->BirdspinBox, SIGNAL(valueChanged(int)), SLOT(BirdChange()));
    connect(ui->PipespinBox, SIGNAL(valueChanged(int)), SLOT(PipeChange()));



    ui->BirdspinBox->setValue(0);
    ui->PipespinBox->setValue(20);
    ui->BirdspinBox->setSuffix("%");
    ui->PipespinBox->setSuffix("%");
    ui->BirdspinBox->setMinimum(0);
    ui->BirdspinBox->setMaximum(100);
    ui->PipespinBox->setMinimum(5);
    ui->PipespinBox->setMaximum(100);
    ui->PipespinBox->setSingleStep(5);

    ui->RestartButtom->hide();
    ui->SettinggroupBox->hide();

}



void FluppyBird::StartTheGame()
{
    ui->StartButtom->hide();
    ui->SettingspushButton->hide();
    main_timer->start(25);
}


void FluppyBird::OpenSettings()
{
    ui->SettinggroupBox->show();
    ui->SettingspushButton->hide();
    ui->StartButtom->hide();
}

void FluppyBird::CloseSettings()
{
    ui->SettinggroupBox->hide();
    ui->SettingspushButton->show();
    ui->StartButtom->show();
}

void FluppyBird::BirdDefault()
{
    bird_speed = 0;
    ui->BirdspinBox->setValue(0);
}

void FluppyBird::PipeDefault()
{
    pipe_speed = -4;
    ui->PipespinBox->setValue(20);
}

void FluppyBird::BirdChange()
{
    bird_speed = ui->BirdspinBox->value();
}

void FluppyBird::PipeChange()
{
    pipe_speed = (-4*ui->PipespinBox->value())/20;
}



void FluppyBird::moveObjects()
{
    ui->centralwidget->grabKeyboard();
    std::random_device rdGen;
    std::mt19937 gen1(rdGen());
    std::uniform_int_distribution<> dis0_15(70, this->height() - 80);

    for(int i=0; i < 3 ; ++i )
    {
         Pipes[i]->setX(Pipes[i]->x() + pipe_speed);
         if(Pipes[i]->x() + 35 <= 0)
         {
             Pipes[i]->setX(this->width() + 400);
             Pipes[i]->setY(dis0_15(gen1));
         }
    }


   this->bird.setY(this->bird.y() + bird_speed);
   bird_speed += 2;

   IncreaseCounter();
   StopTheGame();
   this->update();
}




void FluppyBird::paintEvent(QPaintEvent *event)
{
      QPainter painter(this);
      QImage bckg(":/new/prefix1/2346_Flappy_Bird_res/bckg1.png", "PNG");
      QBrush brushBack(bckg);
      QImage lower_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_low.png","PNG");
      QImage upper_pipe(":/new/prefix1/2346_Flappy_Bird_res/spr_block_upp.png", "PNG");


      painter.fillRect(0,0,this->width(),this->height(),brushBack);

      for(int i = 0; i < 3; ++i )
      {
          Pipes[i]->drawPipe(&painter, lower_pipe, upper_pipe);
      }



      QImage birdIm(":/new/prefix1/2346_Flappy_Bird_res/bird.png", "PMG");
      bird.drawBird(&painter, birdIm);

      ui->LCDcounter->display(counter);

      if(isDead)
      {
          QFont font("Calibri", 20,QFont::DemiBold);
          painter.setFont(font);
          QString died("You die");
          painter.drawText(340,250,died);
          QString score("Your score is : ");
          painter.drawText(300,300,score);
          QString sc = QString::number(counter);
          painter.drawText(470, 300, sc);
      }

}

void FluppyBird::keyPressEvent(QKeyEvent *event)
{
     if(event->key() == Qt::Key_Space)
    {

        this->bird_speed = -10;
    }
}


bool FluppyBird::Intersections(int number)
{
    if(bird.y()  >= this->height()){
        return true;
    }

    if((bird.x() + 37 > Pipes[number]->x() - 35 && bird.x() + 37 <  Pipes[number]->x() + 75 ) &&
       (bird.y() < Pipes[number]->y() - 65  || bird.y() + 30 > Pipes[number]->y() + 65)){
          return true;
    }else{
          return false;
    }

    return false;
}

void FluppyBird::IncreaseCounter()
{
    for(int i = 0; i < 3; ++i){
        if(bird.x() + 37 >= Pipes[i]->x() && bird.x() + 37 <= Pipes[i]->x() + 3 ){
            ++counter;
        }
    }

}

void FluppyBird::StopTheGame()
{
    for(int i = 0; i < 3; ++i){
        if(this->Intersections(i)){
            bird_speed = 20;
            pipe_speed = 0;
            ui->RestartButtom->show();
            isDead = true;
        }
    }
}

void FluppyBird::RestartTheGame()
{
    std::random_device rdGen;
    std::mt19937 gen(rdGen());
    std::uniform_int_distribution<> dis0_15(70, this->height() - 80);

    int distance = -50;


    for(int i=0; i < 3; ++i )
    {
        Pipes[i] = new Pipe(this->width() + distance, dis0_15(gen));
        distance += 400;
    }


    bird_speed = 0;
    pipe_speed = -4;
    bird.setX(300);
    bird.setY(400);

    main_timer->stop();
    counter = 0;
    ui->RestartButtom->hide();
    ui->StartButtom->show();
    ui->SettingspushButton->show();
    isDead = false;

    this->update();

}


FluppyBird::~FluppyBird()
{
    delete ui;
}
