#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,20,780,600);
    settingBg();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg()
{
    QImage bg;
    bg.load(":/pics/picture/1266831023419.jpg");
    bg = bg.scaled(800,640); // you can also change here
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init();
}
