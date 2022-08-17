#ifndef ALIENS_H
#define ALIENS_H

#include <QPainter>

class Aliens
{
public:
    Aliens();
    Aliens(int x, int y);

    void AlienBorn(int Level);
    void AlienDraw(QPainter *painter, QImage Aliens, int i);

    int getX() const{return x;}
    int getY() const{return y;}

    QList <Aliens> aliens;

private:
    int x, y;
};
#endif // ALIENS_H
