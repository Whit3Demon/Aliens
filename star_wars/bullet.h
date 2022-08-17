#ifndef BULLET_H
#define BULLET_H
#include <QPainter>

class Bullet {
public:
    Bullet();

    void BulletCreate(int x);

    void BulletDraw(QPainter *painter, QImage bullet);

    void BulletOut();

    int getY() const;
    void setY(int value);

    int getX() const;
    void setX(int value);

    bool getExist() const;
    void setExist(bool value);

private:
    int x;
    int y=-100;
    bool exist = false;
};

#endif // BULLET_H
