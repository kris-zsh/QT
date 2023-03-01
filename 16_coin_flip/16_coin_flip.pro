#-------------------------------------------------
#
# Project created by QtCreator 2023-02-28T20:42:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 16_coin_flip
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypushbutton.cpp \
    chooselevelscene.cpp \
    playscene.cpp

HEADERS  += mainwindow.h \
    mypushbutton.h \
    chooselevelscene.h \
    playscene.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
