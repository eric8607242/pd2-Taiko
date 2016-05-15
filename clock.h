#ifndef CLOCK_H
#define CLOCK_H
#include <QTimer>
#include <QString>
#include <QGraphicsTextItem>
#include <QFont>


using namespace std;

class clock :public QGraphicsTextItem
{
    Q_OBJECT
public:
    clock();
    void passtimer(QTimer *timer);
    void appear(int time);
    QTimer *timer1;
    int time;
public slots:
    void count();
};

#endif // CLOCK_H
