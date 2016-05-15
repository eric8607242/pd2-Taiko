#include "score.h"

score::score()
{
    sc = 0;
    check = 40;
    setPlainText(QString("Score :"+QString::number(sc)));
    setFont(QFont("Arial",14));
}
void score::prscor()
{
    sc= sc+10;
    check--;
    setPlainText(QString("Score :"+QString::number(sc)));
    setFont(QFont("Arial",14));
}
void score::result()
{
     setPlainText(QString("Score :"+QString::number(sc)));
     setFont(QFont("Arial",28));
}
