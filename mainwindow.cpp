#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdio.h>
#include<iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>       // std::string
#include <fstream>
#include <qfiledialog.h>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    roiactivado=false;
    ui->axialbutton->setEnabled(false);
    ui->bisfherebutton->setEnabled(false);
    ui->bisphere3dbutton->setEnabled(false);
    ui->cornealbutton->setEnabled(false);
    ui->heigth3dbutton->setEnabled(false);
    ui->gridbutton->setEnabled(false);
    ui->heigthbutton->setEnabled(false);
    ui->sourcebutton->setEnabled(false);
    ui->sourcecolorbutton->setEnabled(false);
    ui->tangencialbutton->setEnabled(false);
    ui->tangentanglesbutton->setEnabled(false);
    ui->tangent3dbutton->setEnabled(false);
    ui->refractivebutton->setEnabled(false);
    ui->progressBar->setVisible(false);
    ui->newcenter->setVisible(false);
    ui->newcenter->setEnabled(false);
    ui->horizontalSlider->setVisible(false);
    ui->verticalSlider->setVisible(false);
    ui->stopbutton->setVisible(false);
    ui->stopbutton->setEnabled(false);
    ui->exportbutton->setVisible(false);
    ui->exportbutton->setEnabled(false);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionXml_Data_2_triggered()
{
    double progreso=0;
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString fileNamexml = QFileDialog::getOpenFileName(this,
        tr("Select xml File"), "C:/", tr("XML files (*.xml)"));
    rutaxmlimportado=fileNamexml;
    ui->progressBar->setVisible(true);
    if(rutaxmlimportado!=NULL){
        //ui->axialbutton->setEnabled(true);
        //ui->bisfherebutton->setEnabled(true);
        //ui->bisphere3dbutton->setEnabled(true);
        ui->cornealbutton->setEnabled(true);
        //ui->heigth3dbutton->setEnabled(true);
        //ui->gridbutton->setEnabled(true);
        progreso=progreso+3.13;
        ui->progressBar->setValue(progreso);
        //ui->tangencialbutton->setEnabled(true);
        //ui->tangentanglesbutton->setEnabled(true);
        //ui->tangent3dbutton->setEnabled(true);
        //ui->refractivebutton->setEnabled(true);
        ui->heigthbutton->setEnabled(true);

    }
    QDomDocument xmlBOM;
    QFile f(rutaxmlimportado);
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    if (!f.open(QIODevice::ReadOnly ))
    {
        std::cerr << "Error while loading file" << std::endl;
    }
    xmlBOM.setContent(&f);
    f.close();
    QDomElement root=xmlBOM.documentElement();
    //Patient
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QDomElement Patient=root.firstChild().toElement();
    QString patientid=Patient.attribute("Id");
    QString patientfamilyname=Patient.attribute("FamilyName");
    QString patientgivenname=Patient.attribute("GivenName");
    QString patientdisplayname=Patient.attribute("DisplayName");
    //Measurement
    QDomElement Measurement=Patient.nextSibling().toElement();
    QString measurementeye=Measurement.attribute("Eye");
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString measurementdate=Measurement.attribute("Date");
    QString measurementsequence=Measurement.attribute("Sequence");
    //Parameters(Measurement)
    QDomElement Parameters=Measurement.firstChild().toElement();
    //Dimensions(Measurement-Parameters)
    QDomElement Dimensions=Parameters.firstChild().toElement();
    QString dimensionsroi=Dimensions.attribute("ROI");
    QString dimensionssize=Dimensions.attribute("Size");
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    //Apex(Measurement-parameters-Dimension)
    QDomElement Apex=Dimensions.firstChild().toElement();
    QString apexroi=Apex.attribute("ROI");
    QString apeximage=Apex.attribute("Image");
    //Refractive(Measurement-Parameters)
    QDomElement Refractive=Dimensions.nextSibling().toElement();
    QString refractiveastigmatism=Refractive.attribute("Astigmatism");
    QString refractiveaxis=Refractive.attribute("Axis");
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString refractivesphere=Refractive.attribute("Sphere");
    //K(Measurement-parameters)
    QDomElement K=Refractive.nextSibling().toElement();
    QString kastigmatism=K.attribute("Astigmatism");
    QString kangle=K.attribute("Angle");
    QString kqbar=K.attribute("Qbar");
    //flat(Measurement-parameter-k)
    QDomElement Flat=K.firstChild().toElement();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString flatradius=Flat.attribute("Radius");
    QString flatpower=Flat.attribute("Power");
    QString flatangle=Flat.attribute("Angle");
    QString flatq=Flat.attribute("Q");
    //Steep(measurement-parameter-k)
    QDomElement Steep=Flat.nextSibling().toElement();
    QString steepradius=Steep.attribute("Radius");
    QString steeppower=Steep.attribute("Power");
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString steepangle=Steep.attribute("Angle");
    QString steepq=Steep.attribute("Q");
    //SimK(measurement-parameters)
    QDomElement Simk=K.nextSibling().toElement();
    QString simkastigmatism=Simk.attribute("Astigmatism");
    QString simkangle=Simk.attribute("Angle");
    //simkflat
    QDomElement Simkflat=Simk.firstChild().toElement();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString simkflatradius=Simkflat.attribute("Radius");
    QString simkflatpower=Simkflat.attribute("Power");
    QString simkflatangle=Simkflat.attribute("Angle");
    //simksteep
    QDomElement Simksteep=Simkflat.nextSibling().toElement();
    QString simksteepradius=Simksteep.attribute("Radius");
    QString simksteeppower=Simksteep.attribute("Power");
    QString simksteepangle=Simksteep.attribute("Angle");
    //Spherefit
    QDomElement SphereFit=Simk.nextSibling().toElement();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString spherefitradius=SphereFit.attribute("Radius");
    QString spherefitx=SphereFit.attribute("X");
    QString spherefity=SphereFit.attribute("Y");
    //BisphereFit
    QDomElement BisphereFit=SphereFit.nextSibling().toElement();
    QString bispherefitedge=BisphereFit.attribute("Edge");
    QString bispherefitlimbus=BisphereFit.attribute("Limbus");
    QString bispherefitinner=BisphereFit.attribute("Inner");
    QString bispherefitouter=BisphereFit.attribute("Outer");
    //Cornea
    QDomElement Cornea=BisphereFit.nextSibling().toElement();
    QString cornearadius=Cornea.attribute("Radius");
    //Iris
    QDomElement Iris=Cornea.nextSibling().toElement();
    QString irishvid=Iris.attribute("HVID");
    //Pupil
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QDomElement Pupil=Iris.nextSibling().toElement();
    QString pupilradius=Pupil.attribute("Radius");
    QString pupilx=Pupil.attribute("X");
    QString pupily=Pupil.attribute("Y");
    //Palpealaberture
    QDomElement PalpebralAperture=Pupil.nextSibling().toElement();
    //palpealaperturecornea
    QDomElement PalpebralApertureCornea=PalpebralAperture.firstChild().toElement();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString PalpebralApertureCorneaup=PalpebralApertureCornea.attribute("Up");
    QString PalpebralApertureCorneadown=PalpebralApertureCornea.attribute("Down");
    //palpebralaperturepupil
    QDomElement PalpebralAperturePupil=PalpebralApertureCornea.nextSibling().toElement();
    QString PalpebralAperturePupilup=PalpebralAperturePupil.attribute("Up");
    QString PalpebralAperturePupildown=PalpebralAperturePupil.attribute("Down");
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    //Keratoconus
    QDomElement Keratoconus=PalpebralAperture.nextSibling().toElement();
    //KPI
    QString KPI=Keratoconus.attribute("KPI");
    //Device
    QDomElement Device=Parameters.nextSibling().toElement();
    //CameraInfo
    QDomElement CameraInfo=Device.firstChild().toElement();
    QString camk=CameraInfo.attribute("xmlns:xsd");
    //Recorder
    QDomElement Recorder=CameraInfo.firstChild().toElement();
    QString recorderdata=Recorder.firstChild().toText().data();
    //FramesPersample
    QDomElement FramesPerSample=Recorder.nextSibling().toElement();
    QString framespersampledata=FramesPerSample.firstChild().toText().data();
    //Gain
    QDomElement Gain=FramesPerSample.nextSibling().toElement();
    QString gaindata=Gain.firstChild().toText().data();
    //Exposure
    QDomElement Exposure=Gain.nextSibling().toElement();
    QString exposuredata=Exposure.firstChild().toText().data();
    cout<<exposuredata.toStdString();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);

    //Height
    QDomElement Height=Device.nextSibling().toElement();
    //Range
    QDomElement Range=Height.firstChild().toElement();
    //X
    QDomElement RangeX=Range.firstChild().toElement();
    QString rangexmin=RangeX.attribute("Min");
    Heightxmin=rangexmin.toDouble();
    QString rangexmax=RangeX.attribute("Max");
    Heightxmax=rangexmax.toDouble();
    QString rangexstep=RangeX.attribute("Step");
    Heightxstep=rangexstep.toDouble();
    QString rangexcount=RangeX.attribute("Count");
    Heightx=rangexcount.toDouble();

    //Y
    QDomElement RangeY=RangeX.nextSibling().toElement();
    QString rangeymin=RangeY.attribute("Min");
    Heightymin=rangeymin.toDouble();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString rangeymax=RangeY.attribute("Max");
    Heightymax=rangeymax.toDouble();
    QString rangeystep=RangeY.attribute("Step");
    Heightystep=rangeystep.toDouble();
    QString rangeycount=RangeY.attribute("Count");
    Heighty=rangeycount.toDouble();

    //Z
    QDomElement RangeZ=RangeY.nextSibling().toElement();
    QString rangezmin=RangeZ.attribute("Min");
    Heightzmin=rangezmin.toDouble();
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    QString rangezmax=RangeZ.attribute("Max");
    Heightzmax=rangezmax.toDouble();
    float zmax=rangezmax.toFloat();
    float zmin=rangezmin.toFloat();
    //Data
    QDomElement HeightData=Range.nextSibling().toElement();
    QString names=HeightData.firstChild().toText().data();
    Size size(Heightx,Heightx);
    stringstream nofail(names.toStdString());
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
    double temp;
    int i=0;
    int j=0;
    Mat Heightimage=Mat(size, CV_64FC1);
    imagenpuntos=Mat(size, CV_64FC1);
    zminencontrado=9999999;
    zmaxencontrado=-99999;
    int cont=0;
    progreso=progreso+3.13;
    ui->progressBar->setValue(progreso);
   while (nofail>>temp || !nofail.eof() ){
       QApplication::processEvents();
       if(j<Heightx-1){
           if (nofail.fail()){
               nofail.clear();
               std::string garbage;
               nofail>>garbage;
               Heightimage.at<double>(j, i)=-7;
               i++;
               cont++;
               continue;
           }
           Heightimage.at<double>(j, i)=temp;
           cont++;
           if(temp<zminencontrado){
               zminencontrado=temp;
           }
           if(temp>zmaxencontrado){
               zmaxencontrado=temp;
           }
           i++;
       }
       if(j==Heightx-1){
           j++;
           i=0;
           cont++;
       }
       progreso=progreso+0.0000258;
       ui->progressBar->setValue(progreso);
     }
   Mat roiheight(Heightimage, Rect(0,0,Heightx,Heighty));
   Heightimage=roiheight;


   Heightimage.convertTo(Heightimageglobal,CV_8U,255.0/(zmax-zmin),-255.0*(zmin)/(zmax-zmin));

   //Heightimageglobal=roiheight;

   cv::cvtColor(Heightimageglobal, Heightimageglobal, CV_GRAY2RGB);
   imwrite("C:\\Ejemplo2\\prueba01.png",Heightimageglobal);
   imagenpuntos=Heightimageglobal;
   imwrite("C:\\Ejemplo2\\prueba011.png",imagenpuntos);
//CornealHeight
   QDomElement CornealHeight=Height.nextSibling().toElement();
   QDomElement Cornealrange=CornealHeight.firstChild().toElement();
   QDomElement cornealrangex=Cornealrange.firstChild().toElement();
   QString cornealrangexmin=cornealrangex.attribute("Min");
   QString cornealrangexmax=cornealrangex.attribute("Max");
   QString cornealrangexstep=cornealrangex.attribute("Step");
   QString cornealrangexcount=cornealrangex.attribute("Count");
   cornealheightx=cornealrangexcount.toDouble();
   QDomElement cornealrangey=cornealrangex.nextSibling().toElement();
   QString cornealrangeymin=cornealrangey.attribute("Min");
   QString cornealrangeymax=cornealrangey.attribute("Max");
   QString cornealrangeystep=cornealrangey.attribute("Step");
   QString cornealrangeycount=cornealrangey.attribute("Count");
   cornealheighty=cornealrangeycount.toDouble();
   QDomElement cornealrangez=cornealrangey.nextSibling().toElement();
   QString cornealrangezmin=cornealrangez.attribute("Min");
   QString cornealrangezmax=cornealrangez.attribute("Max");
 //CornealData
   QDomElement CornealData=Cornealrange.nextSibling().toElement();
   QString name=CornealData.firstChild().toText().data();
           Size size2(cornealheightx+1,cornealheighty+1);
           Mat cornealheightimage=Mat(size2, CV_64FC1);
           double max=-999;
           double min=999;
           std::stringstream stream(name.toStdString());
           int pixels = 1;
           int garbages=1;
           double temp2;
           int k=0;
           int l=0;
           while (stream>>temp2 || !stream.eof()){
               if(k<cornealheightx-1){
                   if (stream.fail()){
                       stream.clear();
                       std::string garbage;
                       stream>>garbage;
                       cornealheightimage.at<double>(l, k)=0;
                       garbages++;
                       k++;
                       continue;
                   }
                   pixels++;
                   cornealheightimage.at<double>(l, k)=temp2;
                   if(max<=temp2){
                       max=temp2;
                   }
                   if(min>=temp2){
                       min=temp2;
                   }
                   k++;
               }
               if(k==cornealheighty-1){
                   l++;
                   k=0;
               }
               progreso=progreso+0.000104;
               ui->progressBar->setValue(progreso);
           }

           cornealheightimage.convertTo(Cornealheightimageglobal,CV_8U,255.0/(max-min),-255.0*(min)/(max-min));
           cv::cvtColor(Cornealheightimageglobal, Cornealheightimageglobal, CV_GRAY2RGB);
            imwrite("C:\\Ejemplo2\\prueba02.png",Cornealheightimageglobal);
   QDomElement TangentialCurvature=CornealHeight.nextSibling().toElement();
   QDomElement tangentialrange=TangentialCurvature.firstChild().toElement();
   QDomElement tangentialrangex=tangentialrange.firstChild().toElement();
   QString tangentialrangexmin=tangentialrangex.attribute("Min");
   QString tangentialrangexmax=tangentialrangex.attribute("Max");
   QString tangentialrangexstep=tangentialrangex.attribute("Step");
   QString tangentialrangexcount=tangentialrangex.attribute("Count");
   tangentialheightx=tangentialrangexcount.toDouble();
   QDomElement tangentialrangey=tangentialrangex.nextSibling().toElement();
   QString tangentialrangeymin=tangentialrangex.attribute("Min");
   QString tangentialrangeymax=tangentialrangex.attribute("Max");
   QString tangentialrangeystep=tangentialrangex.attribute("Step");
   QString tangentialrangeycount=tangentialrangex.attribute("Count");
   tangentialheighty=tangentialrangeycount.toDouble();
   QDomElement tangentialrangez=tangentialrangey.nextSibling().toElement();
   QString tangentialrangezmin=tangentialrangez.attribute("Min");
   QString tangentialrangezmax=tangentialrangez.attribute("Max");
   QDomElement tangentialdata=tangentialrange.nextSibling().toElement();

   QString tangentialname=tangentialdata.firstChild().toText().data();;
   Size tangentialsize(tangentialheightx,tangentialheighty);
   Mat dst3=Mat(tangentialsize, CV_64FC1);
   double max2=-999;
   double min2=999;
   std::stringstream stream2(tangentialname.toStdString());

   double temp3;
   i=0;
   j=0;
   while (stream2>>temp3 || !stream2.eof()){
       if(j<tangentialheightx-1){
           if (stream2.fail()){
               stream2.clear();
               std::string garbage;
               stream2>>garbage;
               dst3.at<double>(j, i)=0;
               i++;
               continue;
           }
           dst3.at<double>(j, i)=temp3;
           if(max<=temp3){
               max=temp3;
           }
           if(min>=temp3){
               min=temp3;
           }
           i++;
       }
       if(j==tangentialheighty-1){
           j++;
           i=0;
       }
       progreso=progreso+0.000105;
       ui->progressBar->setValue(progreso);

   }
   dst3.convertTo(tangentialimageglobal,CV_8U,255.0/(max2-min2),-255.0*(min2)/(max2-min2));
   cv::cvtColor(tangentialimageglobal, tangentialimageglobal, CV_GRAY2RGB);
   imwrite("C:\\Ejemplo2\\prueba03.png",tangentialimageglobal);
   roiactivado=true; //verifica que si se pueda hacer el roi
   ui->stopbutton->setEnabled(true);
   ui->newcenter->setEnabled(true);
   ui->exportbutton->setEnabled(true);

   ui->progressBar->setValue(100);
   ui->progressBar->setVisible(0);
}




void MainWindow::on_actionGray_Color_triggered()
{
    QString fileNamegray = QFileDialog::getOpenFileName(this,
        tr("Select Gray Image"), "C:/", tr("Image Files (*.png *.jpg *.bmp)"));
    rutaimagengrisimportada=fileNamegray;
    if(rutaimagengrisimportada!=NULL){
        ui->sourcebutton->setEnabled(true);
    }
}



void MainWindow::on_actionColor_Image_triggered()
{
    QString fileNamecolor = QFileDialog::getOpenFileName(this,
        tr("Select Color Image"), "C:/", tr("Image Files (*.png *.jpg *.bmp)"));
    rutaimagencolorimportada=fileNamecolor;
    if(rutaimagencolorimportada!=NULL){
        ui->sourcecolorbutton->setEnabled(true);
    }
}

void MainWindow::on_actionXml_Data_triggered()
{

}
void MainWindow::on_actionImport_triggered()
{

}

void MainWindow::on_heigthbutton_clicked()
{
    QImage image2(Heightimageglobal.data, Heightimageglobal.cols, Heightimageglobal.rows, QImage::Format_RGB888);
    QPixmap pix2( QPixmap::fromImage(image2));
    ui->Labelmuestraimagenes->setPixmap(pix2);
    ui->Labelmuestraimagenes->setScaledContents(true);
    ui->Labelmuestraimagenes->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
     ui->newcenter->setVisible(false);
     ui->horizontalSlider->setVisible(false);
     ui->verticalSlider->setVisible(false);
      ui->stopbutton->setVisible(false);
      ui->exportbutton->setVisible(false);


}

void MainWindow::on_cornealbutton_clicked()
{
    QImage image2(Cornealheightimageglobal.data, Cornealheightimageglobal.cols, Cornealheightimageglobal.rows, QImage::Format_RGB888);
    QPixmap pix2( QPixmap::fromImage(image2));
    ui->Labelmuestraimagenes->setPixmap(pix2);
    ui->Labelmuestraimagenes->setScaledContents(true);
    ui->Labelmuestraimagenes->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
     ui->newcenter->setVisible(false);
     ui->horizontalSlider->setVisible(false);
     ui->verticalSlider->setVisible(false);
      ui->stopbutton->setVisible(false);
      ui->exportbutton->setVisible(false);



}

void MainWindow::on_sourcebutton_clicked()
{
    if(roiactivado==true){
        ui->stopbutton->setEnabled(true);
        ui->newcenter->setEnabled(true);
    }
    QPixmap pix(rutaimagengrisimportada);
    ui->Labelmuestraimagenes->setPixmap(pix);
    ui->Labelmuestraimagenes->setScaledContents(true);
    ui->Labelmuestraimagenes->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->newcenter->setVisible(true);
    //ui->exportbutton->setVisible(true);
    ui->horizontalSlider->setVisible(true);
    ui->verticalSlider->setVisible(true);
     ui->stopbutton->setVisible(true);
     ui->exportbutton->setVisible(true);


}

void MainWindow::on_newcenter_clicked()
{

    ui->horizontalSlider->setVisible(true);
    ui->verticalSlider->setVisible(true);
    int  w, h;
    //se debe hacer el split
    xp=233;
    yp=212;
    w=Heightx;
    h=Heighty;
    int ix, iy;
    //se debe hacer el split
    ix=634;
    iy=520;

    Mat image;
    Rect roi = Rect(xp, yp, w, h);

    QString rot=rutaimagengrisimportada;
    image = imread(rot.toStdString(), CV_LOAD_IMAGE_COLOR);



    ui->horizontalSlider->setValue(50);
    ui->verticalSlider->setValue(50);
    on=true;
    while(on==true){
        QApplication::processEvents();
        Mat image_roi = image(roi);
        Mat eyeTexture, eyeTexture2 , eyeTexture3 , eyeTexture4;
        float cx, cy;
        cx = ix - xp;
        cy = iy - yp;

        linearPolar(image_roi, eyeTexture, Point2f(cx, cy), w, cv::WARP_FILL_OUTLIERS);
        transpose(eyeTexture, eyeTexture2);
        flip(eyeTexture2, eyeTexture, -1);
        eyepolar=eyeTexture;

        linearPolar(nulosblancoynegro, eyeTexture3, Point2f(cx, cy), w, cv::WARP_FILL_OUTLIERS);
        transpose(eyeTexture3, eyeTexture4);
        flip(eyeTexture4, eyeTexture3, -1);
        linearpolarnulo=eyeTexture3;

        QImage image2(eyeTexture.data, eyeTexture.cols, eyeTexture.rows, QImage::Format_RGB888);
        ui->Labelmuestraimagenes->setPixmap( QPixmap::fromImage(image2));
        ui->Labelmuestraimagenes->setScaledContents(true);
        ui->Labelmuestraimagenes->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        yp=a;
        xp=b;
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //el 212 debe ser reemplazado por el valor obtenido del split
   if((ui->horizontalSlider->value())>=50){
       a=212+8*(ui->horizontalSlider->value()-50);
   }
    //el 212 debe ser reemplazado por el valor obtenido del split
   else{
       a=212+8*(ui->horizontalSlider->value()-50);
   }
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    if((ui->verticalSlider->value())>=50){
        //el 233 debe ser reemplazado por el valor obtenido del split
        b=233+8*(ui->verticalSlider->value()-50);
    }
    else{
         //el 233 debe ser reemplazado por el valor obtenido del split
        b=233+5*(ui->verticalSlider->value()-50);
    }
}

void MainWindow::on_stopbutton_clicked()
{
     on=false;
}

void MainWindow::on_exportbutton_clicked()
{
    on=false;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Save Gray Image"),
                                                "c:/",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    rutagrisexport=dir;
    QString temp=rutagrisexport + "/output.png";
    QString temp3=rutagrisexport + "/outputoriginal.png";
    Size size(1024,1024);
    Mat dst;//dst image
    cv::resize(eyepolar,dst,size);//resize image
    imwrite(temp.toStdString(),dst);
    imwrite(temp3.toStdString(),eyepolar);
}

void MainWindow::on_Generatebutton_clicked()
{
    QApplication::processEvents();
       double progreso=0;
       QString text;
       QString temp;
       QString temp2;
       QString temp3;
       QString temp4;
       QString temp5;
       QString temp6;
       QString temp7;
       QString temp8;
       QString temp9;
       QString temp10;
       QString temp11;
       QString temp15;
       QString temp16;
       QString temp17;
       QString dir = QFileDialog::getExistingDirectory(this, tr("Save Text Files"),
                                                   "c:/",
                                                   QFileDialog::ShowDirsOnly
                                                   | QFileDialog::DontResolveSymlinks);
       rutapuntos=dir;
       ui->progressBar->setVisible(true);
       temp=rutapuntos + "/points.txt";
       temp2=rutapuntos + "/triangles.obj";
       temp3=rutapuntos + "/Graysphere.obj";
       temp4=rutapuntos + "/color.mtl";
       temp5=rutapuntos + "/spheretexture.mtl";
       temp6=rutapuntos + "/eyetexture.mtl";
       temp7=rutapuntos + "/source.png";
       temp8=rutapuntos + "/Colorsphere.obj";
       temp9=rutapuntos + "/Pupil.obj";
       temp10=rutapuntos + "/outputcolor.png";
       temp15=rutapuntos + "/puntosransac.txt";
       temp16=rutapuntos + "/puntospupilaransac.txt";
       temp17=rutapuntos + "/iris.obj";
       progreso=round(2.52);
       ui->progressBar->setValue(progreso);
       temp11=rutapuntos + "/output.png";
       Mat image;


       ofstream fs4(temp4.toStdString());
       progreso=round(5.04);
        ui->progressBar->setValue(progreso);
       fs4<<"newmtl Material.001"<<endl;
       fs4<<"Ns 96.078431"<<endl;
       fs4<<"Ka 1.000000 1.000000 1.000000"<<endl;
       fs4<<"Kd 0.572578 0.601604 0.640000"<<endl;
       fs4<<"Ks 0.500000 0.500000 0.500000"<<endl;
       fs4<<"Ke 0.000000 0.000000 0.000000"<<endl;
       fs4<<"Ni 1.000000"<<endl;
       fs4<<"d 1.000000"<<endl;
       fs4<<"illum 2"<<endl;
       progreso=round(7.56);
        ui->progressBar->setValue(progreso);
       fs4<<"map_Kd  outputcolor.png"<<endl;
       fs4.close();
       ofstream fs5(temp5.toStdString());
       fs5<<"newmtl Material.001"<<endl;
       fs5<<"Ns 96.078431"<<endl;
       fs5<<"Ka 1.000000 1.000000 1.000000"<<endl;
       fs5<<"Kd 0.572578 0.601604 0.640000"<<endl;
       fs5<<"Ks 0.500000 0.500000 0.500000"<<endl;
       fs5<<"Ke 0.000000 0.000000 0.000000"<<endl;
       fs5<<"Ni 1.000000"<<endl;
       fs5<<"d 1.000000"<<endl;
       progreso=round(10.8);
        ui->progressBar->setValue(progreso);
       fs5<<"illum 2"<<endl;
       fs5<<"map_Kd  output.png"<<endl;
       fs5.close();
       ofstream fs6(temp6.toStdString());
       fs6<<"newmtl Material.001"<<endl;
       fs6<<"Ns 96.078431"<<endl;
       fs6<<"Ka 1.000000 1.000000 1.000000"<<endl;
       fs6<<"Kd 0.572578 0.601604 0.640000"<<endl;
       fs6<<"Ks 0.500000 0.500000 0.500000"<<endl;
       fs6<<"Ke 0.000000 0.000000 0.000000"<<endl;
       progreso=round(13.0);
        ui->progressBar->setValue(progreso);
       fs6<<"Ni 1.000000"<<endl;
       fs6<<"d 1.000000"<<endl;
       fs6<<"illum 2"<<endl;
       fs6<<"map_Kd  source.png"<<endl;
       fs6.close();
       ofstream fs(temp.toStdString());
       double xmindouble=Heightxmin;
       double ymindouble=Heightymin;
       double xmaxdouble=Heightxmax;
       double ymaxdouble=Heightymax;
       double zmaxdouble=Heightzmax;
       double zmindouble=Heightzmin;
       long double jreal=xmindouble;
       long double ireal=ymindouble;
       long double xstepdouble=float((Heightxstep));
       long double ystepdouble=float((Heightystep));
       fs.close();
       jreal=xmindouble;
       ireal=ymindouble;
       float xrealplus;
       float yrealplus;
       float zrealxplus;
       float zrealyplus;
       float zrealxyplus;
       float xreal;
       float yreal;
       float zreal;
       escalax=1;//0.0228841679697929;
       escalay=1;//0.022971152503996669;
       escalaz=1;//0.16132945239504759;
       int k=1;
       vector<String> puntos;
       int intHeightx=Heightx;
       int intHeighty=Heighty;
       int vertexindice [intHeightx][intHeighty];
       progreso=round(15.2);
        ui->progressBar->setValue(progreso);
       for(int y=0;y<652;y++){
           for(int x=0;x<772;x++){
               progreso=round(progreso+0.0003);
               QApplication::processEvents();
               vertexindice[x][y]=0;
               ui->progressBar->setValue(progreso);

           }
       }
       puntos.push_back("");
       ofstream fs2(temp2.toStdString());
        ofstream streamransac(temp15.toStdString());
       fs2<<"mtllib eyetexture.mtl"<<endl;
       for(int y=0;y<Heighty-1;y++){
           QApplication::processEvents();
           for(int x=0;x<Heightx-1;x++){
    QApplication::processEvents();
           progreso=(progreso+0.00005);
           xreal=(xmindouble+(xstepdouble*x))*escalax;
           yreal=(ymindouble+(ystepdouble*y))*escalay;
           zreal=((((zminencontrado-zmaxencontrado)/(zmindouble-zmaxdouble))*(imagenpuntos.at<double>(y,x)-zmindouble))+zminencontrado)*escalaz;
           zrealxplus=((((zminencontrado-zmaxencontrado)/(zmindouble-zmaxdouble))*(imagenpuntos.at<double>(y,x+1)-zmindouble))+zminencontrado)*escalaz;
           zrealyplus=((((zminencontrado-zmaxencontrado)/(zmindouble-zmaxdouble))*(imagenpuntos.at<double>(y+1,x)-zmindouble))+zminencontrado)*escalaz;
           zrealxyplus=((((zminencontrado-zmaxencontrado)/(zmindouble-zmaxdouble))*(imagenpuntos.at<double>(y+1,x+1)-zmindouble))+zminencontrado)*escalaz;

            xrealplus=(xmindouble+(xstepdouble*(x+1)))*escalax;
            yrealplus=(ymindouble+(ystepdouble*(y+1)))*escalay;
               ui->progressBar->setValue(progreso);
               if(vertexindice[x][y]==0 && imagenpuntos.at<double>(y,x)!=-7 ){
                   fs2<<"v "<<xreal<<" "<<yreal<<" "<<zreal<<endl;
                   streamransac<<xreal<<" "<<yreal<<" "<<zreal<<endl;
                   vertexindice[x][y]=k;
                   k++;
               }else{

               }

               if(vertexindice[x+1][y]==0 && imagenpuntos.at<double>(y,x+1)!=-7){
                   fs2<<"v "<<xrealplus<<" "<<yreal<<" "<<zrealxplus<<endl;
                   streamransac<<xrealplus<<" "<<yreal<<" "<<zrealxplus<<endl;
                   vertexindice[x+1][y]=k;
                   k++;

               }else{

               }

               if(vertexindice[x][y+1]==0 && imagenpuntos.at<double>(y+1,x)!=-7){
                   fs2<<"v "<<xreal<<" "<<yrealplus<<" "<<zrealyplus<<endl;
                   streamransac<<xreal<<" "<<yrealplus<<" "<<zrealyplus<<endl;
                   vertexindice[x][y+1]=k;
                   k++;

               }else{

               }
               if(vertexindice[x+1][y+1]==0 && imagenpuntos.at<double>(y+1,x+1)!=-7){
                   fs2<<"v "<<xrealplus<<" "<<yrealplus<<" "<<zrealxyplus<<endl;
                   streamransac<<xrealplus<<" "<<yrealplus<<" "<<zrealxyplus<<endl;
                   vertexindice[x+1][y+1]=k;
                   k++;

               }else{

               }

               if(vertexindice[x+1][y]==0 && imagenpuntos.at<double>(y,x+1)!=-7){
                   fs2<<"v "<<xrealplus<<" "<<yreal<<" "<<zrealxplus<<endl;
                   streamransac<<xrealplus<<" "<<yreal<<" "<<zrealxplus<<endl;
                   vertexindice[x+1][y]=k;
                   k++;

               }else{

               }

               if(vertexindice[x][y+1]==0 && imagenpuntos.at<double>(y+1,x)!=-7){
                   fs2<<"v "<<xreal<<" "<<yrealplus<<" "<<zrealyplus<<endl;
                   streamransac<<xreal<<" "<<yrealplus<<" "<<zrealyplus<<endl;
                   vertexindice[x][y+1]=k;
                   k++;

               }else{

               }
           }
       }
       for(int y=0;y<Heighty;y++){
   QApplication::processEvents();
           for(int x=0;x<Heightx-1;x++){
               QApplication::processEvents();
               progreso=(progreso+0.00005);
               ui->progressBar->setValue(progreso);
              if(imagenpuntos.at<double>(y,x)!=-7){
                  fs2<<"vt "<<(float(x)/float(Heightx))<<" "<<1.0-(float(y)/float(Heighty))<<endl;
                 // fs2<<"vt "<<float(x+1)/float(maxx)<<" "<<float(y)/float(maxy)<<endl;
                  //fs2<<"vt "<<float(x)/float(maxx)<<" "<<float(y+1)/float(maxy)<<endl;
                  //fs2<<"vt "<<float(x+1)/float(maxx)<<" "<<float(y+1)/float(maxy)<<endl;
                  //fs2<<"vt "<<float(x+1)/float(maxx)<<" "<<float(y)/float(maxy)<<endl;
                 //fs2<<"vt "<<float(x)/float(maxx)<<" "<<float(y+1)/float(maxy)<<endl;

              }
           }
   }
       int vertice=1;
       for(int y=0;y<Heighty-1;y++){
           for(int x=0;x<Heightx-1;x++){
                   QApplication::processEvents();
                   progreso=(progreso+0.00005);
                   ui->progressBar->setValue(progreso);
               if(vertexindice[x][y]!=0 && vertexindice[x+1][y]!=0 && vertexindice[x][y+1]!=0){

                   fs2<<"f "<<vertexindice[x][y]<<"/"<<vertexindice[x][y]<<" "<<vertexindice[x+1][y]<<"/"<<vertexindice[x+1][y]<<" "<<vertexindice[x][y+1]<<"/"<<vertexindice[x][y+1]<<endl;
               }
               if(vertexindice[x][y+1]!=0 && vertexindice[x+1][y]!=0 && vertexindice[x+1][y+1]!=0){
                      fs2<<"f "<<vertexindice[x][y+1]<<"/"<<vertexindice[x][y+1]<<" "<<vertexindice[x+1][y]<<"/"<<vertexindice[x+1][y]<<" "<<vertexindice[x+1][y+1]<<"/"<<vertexindice[x+1][y+1]<<endl;
               }
           }
   }
       fs2.close();

}
