#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "itkImage.h"
  

using namespace std;
using namespace cv;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout<<"Hola";
   Mat hola= imread("c/:hola");
   imwrite("hola.jpg",hola);
   /*
    typedef itk::Image< unsigned short, 3 > ImageType;
   
    ImageType::Pointer image = ImageType::New();
  
    std::cout << "ITK Hello World !" << std::endl;
	*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Hola Mundo");


}
