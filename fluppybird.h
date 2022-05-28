#ifndef FLUPPYBIRD_H
#define FLUPPYBIRD_H

#include <QMainWindow>

#include "pipe.h"
#include "bird.h"

#include <vector>
#include <QPoint>
#include <random>
#include <QPainter>
#include <QBrush>
#include <QRect>
#include <QTimer>
#include <QImage>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class FluppyBird; }
QT_END_NAMESPACE

class FluppyBird : public QMainWindow
{
    Q_OBJECT

public:
    FluppyBird(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    bool Intersections(int number);
    void IncreaseCounter();
    void StopTheGame();
    ~FluppyBird();

public slots:
    void moveObjects();
    void StartTheGame();
    void RestartTheGame();
    void OpenSettings();
    void CloseSettings();
    void BirdDefault();
    void PipeDefault();
    void BirdChange();
    void PipeChange();

private:
    Ui::FluppyBird *ui;
    QTimer* main_timer = new QTimer(this);
    QTimer* starting_timer = new QTimer(this);
    Pipe* Pipes[3];
    Bird bird = Bird(300,400);
    QPoint bird_center;
    bool isDead;
    int pipe_speed;
    int bird_speed;
    int counter;
};
#endif // FLUPPYBIRD_H
