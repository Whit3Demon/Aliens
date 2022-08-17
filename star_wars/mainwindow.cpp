#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
        ui->setupUi(this);
        QTimer *timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->start(80);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
   this->setFixedSize(1000,800); // размер окна
   QPainter painter(this);


   QFont qfont("", 25);
   painter.setFont(qfont);    //интерфейс
   painter.drawText(950,0,100,100,1,QString::number(score));
   painter.drawText(120,0,100,100,1,QString::number(life));

   cannon.CannonDraw(&painter,cannon_png); //рождение пушки
   if(bullet.getY()>-100)
       bullet.BulletDraw(&painter,bullet_png); //рождение выстрелов пушки







   if(a.aliens.size()==0)
          a.AlienBorn(1);

   for(int i=0 ; i<11 ; i++)
   {                                         //рождение пришельцев
       a.AlienDraw(&painter,alien_png,i);

   }

//******************************************************************************
   light.LightningDraw(&painter, lightning_png);
   frequency--;
   if(frequency==0)
   {
       light.LightningBorn(arc4random() % 950); //откуда стреляют молнии
       frequency=arc4random() %20+5;       //частота стрельбы
   }
   //******************************************************************************
   for(int i=0 ; i<light.lightnings.size() ; i++)
   {
       light.lightnings[i].setY(light.lightnings[i].getY()+15); //скорость молнии
       if(light.lightnings[i].getY()>800)  //молния коснулась пола?
           light.lightnings.removeAt(i); //удалить молнию которая коснулась пола
   }


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

     if (event->key()==Qt::Key_Right)
      if (cannon.getX()<875) cannon.setX(cannon.getX()+25); // право

    if (event->key()==Qt::Key_Left)
      if (cannon.getX()>-25) cannon.setX(cannon.getX()-25); //лево

    if (event->key()==Qt::Key_Space)
      if (bullet.getExist()==false) bullet.BulletCreate(cannon.getX()); //огонь

}

void MainWindow::update()
{
//******************************************************************************
    for(int i=0;i<light.lightnings.size();i++)
    {
        if(light.lightnings[i].getY()>=655 && light.lightnings[i].getY()<=705 && light.lightnings[i].getX()-cannon.getX()<75 && light.lightnings[i].getX()-cannon.getX()>-75)
        {                                           //пробитие пушки

            light.lightnings.removeAt(i);
            life--;
        }

    }
//******************************************************************************



//******************************************************************************
    for(int i=1 ; i<11; i++)
    {
        if(bullet.getY()-a.aliens[i].getY()<=50 && bullet.getExist() && bullet.getX()-a.aliens[i].getX()<=35 && bullet.getX()-a.aliens[i].getX()>=-35)
        {
            // a.aliens.removeAt(i );                      //пробитие пришельцев
            bullet.setY(-100);
            bullet.setExist(false);
            score+=500;
        }
    }
//******************************************************************************
    if(life>0)
    {
        if(bullet.getY()>-100) //пуля ушла за границу?
            bullet.BulletOut();
    }
    else
         qApp->exit(); //Game Over
    repaint();
}



