#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T00:10:44
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tai
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    buttom.cpp \
    slot.cpp \
    clock.cpp \
    score.cpp

HEADERS  += mainwindow.h \
    scene.h \
    buttom.h \
    slot.h \
    clock.h \
    score.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc

