#include "aliens.h"
#include <QPainter>

Aliens::Aliens()
{

}

Aliens::Aliens(int x, int y)
    :x(x), y(y)
{

}

void Aliens::AlienBorn(int Level=1)
{
    for(int i=0 ; i<Level ; i++){
        for(int j=0 ; j<11; j++){
            aliens.append(Aliens(90*j+12,75*i+50));
        }
    }
}

void Aliens::AlienDraw(QPainter *painter, QImage Aliens, int i)
{
    painter->drawImage(aliens[i].getX(),aliens[i].getY(),Aliens);
}
