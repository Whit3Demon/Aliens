#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QImage>
#include "cannon.h"
#include "bullet.h"
#include "aliens.h"
#include "lightning.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void update();
private:
    Ui::MainWindow *ui;
    QImage cannon_png = QImage(":/new/prefix1/star wars/cannon.png");
    QImage alien_png = QImage(":/new/prefix1/star wars/alien.png");
    QImage bullet_png = QImage(":/new/prefix1/star wars/bullet.png");
    QImage lightning_png = QImage(":/new/prefix1/star wars/lightning.png");
    int life = 5;
    int score = 0;
    int frequency = 1;
    Cannon cannon;
    Bullet bullet;
    Aliens a;
    Lightning light;
};
#endif // MAINWINDOW_H
