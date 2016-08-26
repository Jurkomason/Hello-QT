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

INCLUDEPATH += C:\\tools\\opencv\\bin\\include




debug{

LIBS += -LC:\\opencv310\\opencv\\opencv_bin\\bin\
    libopencv_calib3d310d\
    libopencv_core310\
    libopencv_core310d\
    libopencv_features2d310d\
    libopencv_flann310d\
    libopencv_imgcodecs310\
    libopencv_imgproc310\
    libopencv_imgcodecs310d\
    libopencv_imgproc310d\
    libopencv_ml310d\
    libopencv_objdetect310d\
    libopencv_highgui310d\
    libopencv_photo310d\
    libopencv_stitching310d\
}release{
LIBS += -LC:\\opencv310\\opencv\\opencv_bin\\bin\
    libopencv_core310\
    libopencv_imgcodecs310\
    libopencv_imgproc310\
}

