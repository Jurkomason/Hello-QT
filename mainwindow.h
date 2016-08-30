#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXml>
#include <QFile>
#include<stdio.h>
#include<iostream>
#include <QtXml>
#include <QCoreApplication>
#include<QFileSystemModel>
#include<QtCore>
#include<QtGui>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionImport_triggered();

    void on_actionXml_Data_triggered();

    void on_actionGray_Color_triggered();

    void on_actionColor_Image_triggered();

    void on_actionXml_Data_2_triggered();

    void on_heigthbutton_clicked();

    void on_cornealbutton_clicked();

    void on_sourcebutton_clicked();

    void on_newcenter_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_verticalSlider_valueChanged(int value);

    void on_stopbutton_clicked();

    void on_exportbutton_clicked();

    void on_Generatebutton_clicked();

private:
    Ui::MainWindow *ui;
    bool on;
    bool roiactivado;
    QString rutaimagencolorimportada;
    QString rutaimagengrisimportada;
    QString rutaxmlimportado;
    QString rutagrisexport;
    QString rutapuntos;
    double escalax;
    double escalay;
    double escalaz;
    double Heightx;
    double Heighty;
    double Heightxmin;
    double Heightxmax;
    double Heightxstep;
    double Heightymin;
    double Heightymax;
    double Heightystep;
    double Heightzmin;
    double Heightzmax;
    double zminencontrado;
    double zmaxencontrado;
    double cornealheightx;
    double cornealheighty;
    double tangentialheightx;
    double tangentialheighty;
    double xp;
    double yp;
    int a;
    int b;
    Mat Heightimageglobal;
    Mat Cornealheightimageglobal;
    Mat tangentialimageglobal;
    Mat eyepolar;
    Mat linearpolarnulo;
    Mat imagenpuntos;
    Mat nulosblancoynegro;
};

#endif // MAINWINDOW_H
