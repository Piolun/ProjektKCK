#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T14:51:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snek
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    Object.cpp \
    Color.cpp \
    figure.cpp \
    word.cpp \
    Order.cpp

HEADERS  += mainwindow.h \
    scene.h \
    drawable \
    Object.h \
    Color.h \
    figure.h \
    word.h \
    Order.h

FORMS    += mainwindow.ui

RESOURCES += \
