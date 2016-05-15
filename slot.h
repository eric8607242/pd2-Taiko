#ifndef SLOT_H
#define SLOT_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

class slot : public QGraphicsPixmapItem
{
public:
    slot();
    int x_speed;
    // For scene boundary

    void advance(int phase);
    void setX_speed(int speed);
};

#endif // SLOT_H
