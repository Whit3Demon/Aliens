#include "cannon.h"
Cannon::Cannon()
{

}

int Cannon::getX() const
{
    return x;
}

void Cannon::setX(int value)
{
    x = value;
}


void Cannon::CannonDraw(QPainter *painter, QImage gun)
{
    painter->drawImage(x+39,y,gun);
}

int Cannon::getY() const
{
    return y;
}

void Cannon::setY(int value)
{
    y = value;
}
