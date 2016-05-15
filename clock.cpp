#include "clock.h"

clock::clock()
{
    time = 30;
    setPlainText(QString("Time :"+QString::number(time)));
    setFont(QFont("Arial",14));
    /*timer1 = new QTimer(this);
    QObject::connect(timer1 , SIGNAL(timeout()) , this , SLOT(count(int)));
    timer1->start(1000);*/

}

void clock::count()
{
   time--;
   setPlainText(QString("Time :"+QString::number(time)));
   setFont(QFont("Arial",14));
   if(time == 0)
   {
     timer1->stop();

   }
}
void clock::passtimer(QTimer *timer)
{
    timer1 = timer;
}

void clock::appear(int time)
{
    setPlainText(QString("Time :"+QString::number(time)));
    setFont(QFont("Arial",14));
}
