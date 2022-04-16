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
    ~FluppyBird();

public slots:
    void movePipes();

private:
    Ui::FluppyBird *ui;
    std::vector<QPoint> points;
    const int speed = -4;
};
#endif // FLUPPYBIRD_H
