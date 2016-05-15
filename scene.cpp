#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}
void Scene::Init()
{
    // start
    btnstart = new Btn();
    QPixmap start;
    start.load(":/pics/picture/454.png");
    start = start.scaled(start.width()*1/3,start.height()*1/3,Qt::KeepAspectRatio);
    btn_h=start.height();
    btn_w=start.width();
    btnstart->setPixmap(start);
    btnstart->setPos(550,400);
    addItem(btnstart);

    btnexit = new Btn();
    QPixmap exit;
    exit.load(":/pics/picture/1235.png");
    exit = exit.scaled(exit.width()*1/3,exit.height()*1/3,Qt::KeepAspectRatio);
    exit_h=exit.height();
    exit_w=exit.width();
    btnexit->setPixmap(exit);
    btnexit->setPos(100,400);
    this->addItem(btnexit);
    for(int i = 0 ; i < 40 ; i++)
    {
        object.push_back(0);
        ran.push_back(0);
    }

}
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if( screenMode == 0)
    {
        cout<<"screenMode = 0"<<endl;
        if(event->scenePos().x() > btnstart->pos().x() && event->scenePos().x() <= btnstart->pos().x()+btn_w)
        {
            if(event->scenePos().y() > btnstart->pos().y() && event->scenePos().y() <= btnstart->pos().y()+btn_h)
            {
                timetime = 30;
                bgChange();
                gameInit();
                screenMode = 1;
            }
        }
        if(event->scenePos().x() > btnexit->pos().x() && event->scenePos().x() <= btnexit->pos().x()+exit_w)
        {
            if(event->scenePos().y() > btnexit->pos().y() && event->scenePos().y() <= btnexit->pos().y()+exit_h)
            {
                QApplication::exit();
            }
        }
    }
    if( screenMode == 1)
    {
        if(event->scenePos().x() > btnback->pos().x() && event->scenePos().x() <= btnback->pos().x()+back_w)
        {
            if(event->scenePos().y() > btnback->pos().y() && event->scenePos().y() <= btnback->pos().y()+back_h)
            {
                bgRecover();
                screenMode = 0;
            }
        }
    }
    if( screenMode == 2)
    {
        if(event->scenePos().x() > btnrestart->pos().x() && event->scenePos().x() <= btnrestart->pos().x()+restart_w)
        {
            if(event->scenePos().y() > btnrestart->pos().y() && event->scenePos().y() <= btnrestart->pos().y()+restart_h)
            {
                this->removeItem(sco);
                timetime = 30;
                bgChange1();
                gameInit();
                screenMode = 1;
            }
        }
        if(event->scenePos().x() > btnexit->pos().x() && event->scenePos().x() <= btnexit->pos().x()+exit_w)
        {
            if(event->scenePos().y() > btnexit->pos().y() && event->scenePos().y() <= btnexit->pos().y()+exit_h)
            {
                QApplication::exit();
            }
        }
    }
}
void Scene::keyPressEvent(QKeyEvent *event)
{

        for(int i = 0 ; i < object.size() ; i++)
        {
        //if(btncheck->pos().x() > object[i]->pos().x() && btncheck->pos().x() <= object[i]->pos().x()+check_w-20)

           /*if(btncheck->pos().y() > object[1]->pos().y() && btncheck->pos().y() <= object[1]->pos().y()+check_h)*/
                if( ran[i] == 1 )
                {
                    if( event->key() == Qt::Key_J  )
                    {
                        if(btncheck->pos().x()+check_w/2 > object[i]->pos().x() && btncheck->pos().x() <= object[i]->pos().x()+check_w/2)
                        {
                            this->removeItem(object[i]);
                            bgmdr = new QSound(":/pics/picture/middle_punch1.mp3");
                            bgmdr->play();
                            bgmdr->stop();
                            object.removeAt(i);
                            ran.removeAt(i);

                        }
                    }
                }
                else if( ran[i] == 2 )
                {
                    if( event->key() == Qt::Key_K )
                    {
                        if(btncheck->pos().x()+check_w/2 > object[i]->pos().x() && btncheck->pos().x() <= object[i]->pos().x()+check_w/2)
                        {
                            this->removeItem(object[i]);
                            bg = new QSound(":/pics/picture/knocking_a_wall.mp3");
                            bg->play();
                            bg->stop();
                            object.removeAt(i);
                            ran.removeAt(i);

                        }
                    }
                }
        }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_J || event->key() == Qt::Key_K)
    {
        if( sco->check - object.size() == 1 )
        {
            sco->prscor();
        }
    }
}

void Scene::gene()
{
    // random the seed
    qsrand(qrand());
    // rand a number : 0 ~ 5
    for(int i = 0 ; i < 40 ; i++)
    {
        int rand = qrand()%2+1;
        ran[i] = rand;
    }

    //cout<<(rightBound - leftBound) << number << endl;

}

void Scene::gameInit()
{


    gene();
    qsrand(qrand());
    for(int i=0 ; i < 40 ; i++)
    {
        int rand1 = qrand()%150+1;
        if( ran[i] == 1)
        {
            btndrum = new slot();
            object[i] = btndrum;
            QPixmap drum;
            drum.load(":/pics/picture/44546.png");
            drum = drum.scaled(drum.width()*3/10,drum.height()*3/10,Qt::KeepAspectRatio);
            btndrum->setPixmap(drum);
            btndrum->setPos(600+7*rand1+20*i*i+200*i+50,200);
            this->addItem(btndrum);
        }
        if( ran[i] == 2)
        {
            btndrum1 = new slot();
            object[i] = btndrum1;
            QPixmap drum1;
            drum1.load(":/pics/picture/2565.png");
            drum1 = drum1.scaled(drum1.width()*3/10,drum1.height()*3/10,Qt::KeepAspectRatio);
            btndrum1->setPixmap(drum1);
            btndrum1->setPos(600+5*rand1+37*i*i+200*i+50 ,200);
            this->addItem(btndrum1);
        }
    }
    sco = new score();
    sco->setPos(300,10);
    this->addItem(sco);
    timer = new QTimer(this);
    connect(timer , SIGNAL(timeout()) , this , SLOT(advance()));
    timer->start(10);
}
void Scene::initTimer()
{

}

void Scene::bgChange()
{
    /* first , change background picture */
    QPixmap bg;
    bg.load(":/pics/picture/pic/img/bg.png");
    bg = bg.scaled(800,640);
    this->setBackgroundBrush(bg);

    btncheck = new Btn();
    QPixmap check;
    check.load(":/pics/picture/638535.png");
    check = check.scaled(check.width()*2/3,check.height()*2/3,Qt::KeepAspectRatio);
    btncheck->setPixmap(check);
    btncheck->setPos(50,187);
    check_w = check.width();
    check_h = check.height();
    this->addItem(btncheck);

    btnback = new Btn();
    QPixmap back;
    back.load(":/pics/picture/pic/img/normagauge_hard.png");
    back_h=back.height();
    back_w=back.width();
    btnback->setPixmap(back);
    btnback->setPos(10,10);
    this->addItem(btnback);

    cl = new clock();

    timecheck = &cl->time;
    cl->setPos(120,10);
    this->addItem(cl);
    cout<<*timecheck<<endl;
    timer1 = new QTimer(this);
    cl->passtimer(timer1);

    QObject::connect(timer1 , SIGNAL(timeout()) , this , SLOT(countslot()));
    timer1->start(1000);
    if(*timecheck == 0)
    {
        timer1->stop();
        cout<<*timecheck<<endl;
    }
    /* second , remove btn - start and change ball */

    this->removeItem(btnstart);
    this->removeItem(btnexit);

}
void Scene::bgRecover()
{
    // remove item here
    removeItem(sco);
    removeItem(btnback);
    removeItem(btncheck);
    si = object.size();
    for(int i = 0 ; i < si ; i++)
    {
        removeItem((object[i]));
    }
    object.clear();
    ran.clear();
    for(int i = 0 ; i < 40 ; i++)
    {
        object.push_back(0);
        ran.push_back(0);
    }
    removeItem(cl);
    timer1->stop();
    timer->stop();
    QImage bg;
    bg.load(":/pics/picture/1266831023419.jpg");
    bg = bg.scaled(800,640);
    this->setBackgroundBrush(bg);

    // add back initial page
    btnexit = new Btn();
    QPixmap exit;
    exit.load(":/pics/picture/1235.png");
    exit = exit.scaled(exit.width()*1/3,exit.height()*1/3,Qt::KeepAspectRatio);
    exit_h=exit.height();
    exit_w=exit.width();
    btnexit->setPixmap(exit);
    btnexit->setPos(100,400);
    this->addItem(btnexit);
    addItem(btnstart);
    /*QImage bg;
    bg.load(":/image/img/open.jpg");
    bg = bg.scaled(370,630);
    this->setBackgroundBrush(bg);*/
}
void Scene::gameend()
{
    removeItem(btnback);
    removeItem(btncheck);
    removeItem(sco);
    si = object.size();
    for(int i = 0 ; i < si; i++)
    {
        removeItem((object[i]));
    }
    object.clear();
    ran.clear();
    for(int i = 0 ; i < 40 ; i++)
    {
        object.push_back(0);
        ran.push_back(0);
    }
    removeItem(cl);
    timer1->stop();
    timer->stop();
    QImage bg1;
    bg1.load(":/pics/picture/3f183fd1_1315026896357.jpg");
    bg1 = bg1.scaled(800,700);
    this->setBackgroundBrush(bg1);

    btnrestart = new Btn();
    QPixmap restart;
    restart.load(":/pics/picture/454.png");
    restart = restart.scaled(restart.width()*1/4,restart.height()*1/4,Qt::KeepAspectRatio);
    restart_h=restart.height();
    restart_w=restart.width();
    btnrestart->setPixmap(restart);
    btnrestart->setPos(100,450);
    this->addItem(btnrestart);

    btnexit = new Btn();
    QPixmap exit;
    exit.load(":/pics/picture/1235.png");
    exit = exit.scaled(exit.width()*1/4,exit.height()*1/4,Qt::KeepAspectRatio);
    exit_h=exit.height();
    exit_w=exit.width();
    btnexit->setPixmap(exit);
    btnexit->setPos(300,450);
    this->addItem(btnexit);
    this->addItem(sco);
    sco->result();
    sco->setPos(300,150);

}

void Scene::countslot()
{
    timetime--;
    cl->appear(timetime);
    if(timetime == 0)
    {
        gameend();
        screenMode = 2;

    }
}

void Scene::bgChange1()
{
    /* first , change background picture */
    QPixmap bg;
    bg.load(":/pics/picture/pic/img/bg.png");
    bg = bg.scaled(800,640);
    this->setBackgroundBrush(bg);

    btncheck = new Btn();
    QPixmap check;
    check.load(":/pics/picture/638535.png");
    check = check.scaled(check.width()*2/3,check.height()*2/3,Qt::KeepAspectRatio);
    btncheck->setPixmap(check);
    btncheck->setPos(50,187);
    check_w = check.width();
    check_h = check.height();
    this->addItem(btncheck);

    btnback = new Btn();
    QPixmap back;
    back.load(":/pics/picture/pic/img/normagauge_hard.png");
    back_h=back.height();
    back_w=back.width();
    btnback->setPixmap(back);
    btnback->setPos(10,10);
    this->addItem(btnback);

    cl = new clock();

    timecheck = &cl->time;
    cl->setPos(120,10);
    this->addItem(cl);
    cout<<*timecheck<<endl;
    timer1 = new QTimer(this);
    cl->passtimer(timer1);

    QObject::connect(timer1 , SIGNAL(timeout()) , this , SLOT(countslot()));
    timer1->start(1000);
    if(*timecheck == 0)
    {
        timer1->stop();
    }
    /* second , remove btn - start and change ball */

    this->removeItem(btnexit);
    this->removeItem(btnrestart);

}
