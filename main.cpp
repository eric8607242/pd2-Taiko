#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QDesktopWidget wid;
    int screenW=840;
    int screenH=700;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    w.setWindowTitle("TAIKO MASTER");
    w.setWindowIcon(QIcon(":/pics/picture/pic/img/mtaikoflower.png"));
    w.show();

    return a.exec();;
}
