#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout<<"Hola";



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Hola Mundo");


}
