#ifndef CANNON_H
#define CANNON_H
#include <QPainter>

class Cannon {
public:
    Cannon();

    int getX() const;
    void setX(int value);

    void CannonDraw(QPainter *painter, QImage gun);

    int getY() const;
    void setY(int value);

private:
    int x = 475;
    int y = 730;
    bool shoot=false;
};

#endif // CANNON_H
