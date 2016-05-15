#include "slot.h"

slot::slot()
{
    x_speed = -1;
}

void slot::advance(int phase)
{
    // Do moving

    this->setPos(this->pos().x()+ x_speed , this->pos().y());
}

void slot::setX_speed(int speed)
{
    x_speed = -speed;
}
