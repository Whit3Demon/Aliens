#include "bullet.h"

Bullet::Bullet()
{

}

void Bullet::BulletCreate(int x)
{
    exist=true;
    this->x=x+75;
    y=730;
}

void Bullet::BulletDraw(QPainter *painter,QImage bullet )
{
    painter->drawImage(x,y,bullet);
}

void Bullet::BulletOut()
{
    y-=45;
    if(y<=-10)
        exist=false;
}
int Bullet::getY() const
{
    return y;
}

void Bullet::setY(int value)
{
    y = value;
}

int Bullet::getX() const
{

}

bool Bullet::getExist() const
{
    return exist;
}

void Bullet::setExist(bool value)
{
    exist = value;
}

