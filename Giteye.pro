#-------------------------------------------------
#
# Project created by QtCreator 2016-08-21T18:36:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Giteye
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\tools\\opencv\\build\\include

release{
LIBS += -LC:\\tools\\opencv\\build\\x64\\vc14\\bin -lopencv_world310
}

