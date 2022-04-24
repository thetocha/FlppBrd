#ifndef FLUPPYBIRD_H
#define FLUPPYBIRD_H

#include <QMainWindow>

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
    ~FluppyBird();

public slots:
    void moveObjects();

private:
    Ui::FluppyBird *ui;
    std::vector<QPoint> points;
    QPoint bird_center;
    const int pipe_speed = -4;
    int bird_speed = 0;
};
#endif // FLUPPYBIRD_H
