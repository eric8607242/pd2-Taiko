#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QTimer>
#include <QKeyEvent>
#include <QObject>
#include <QSound>
#include "buttom.h"
#include "slot.h"
#include "clock.h"
#include "score.h"
class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void Init();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void gene();
    void gameInit();
    void initTimer();
    void bgRecover();
    void bgChange();
    void bgChange1();
    void timeout();
    void gameend();
    Btn *btnstart;
    Btn *btnback;
    Btn *btncheck;
    Btn *btnrestart;
    Btn *btnexit;
    slot *btndrum;
    slot *btndrum1;
    clock *cl;
    clock *cl2;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QSound *bgmdr;
    QSound *bg;
    score *sco;
    int *timecheck;
    int btn_w;
    int btn_h;
    int check_w;
    int check_h;
    int restart_w;
    int restart_h;
    int exit_w;
    int exit_h;
    int back_w;
    int back_h;
    int screenMode;
    int timetime;
    int si;
    QList<int> ran;
    QList<slot *> object;



public slots:
    void countslot();
};

#endif // SCENE_H
