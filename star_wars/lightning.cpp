#include "lightning.h"

Lightning::Lightning()
{

}

Lightning::Lightning(int x, int y)
    :x(x), y(y)
{

}

void Lightning::LightningDraw(QPainter *painter, QImage Lightning)
{
    for(int i=0 ; i<lightnings.size() ; i++)
        painter->drawImage(lightnings[i].getX(),lightnings[i].getY()+50,Lightning);
}

void Lightning::LightningBorn(int x)
{
    lightnings.append(Lightning(x,5));
}

void Lightning::LightningMove()
{

}


int Lightning::getX() const
{
    return x;
}

void Lightning::setX(int value)
{
    x = value;
}

int Lightning::getY() const
{
    return y;
}

void Lightning::setY(int value)
{
    y = value;
}
