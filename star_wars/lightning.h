#ifndef LIGHTNING_H
#define LIGHTNING_H
#include <QPainter>

class Lightning
{
public:
    Lightning();
    Lightning(int x,int y);

    void LightningDraw(QPainter *painter, QImage Lightning);
    void LightningBorn(int x);
    void LightningMove();

    QList <Lightning> lightnings;

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x;
    int y=700;
};
#endif // LIGHTNING_H
