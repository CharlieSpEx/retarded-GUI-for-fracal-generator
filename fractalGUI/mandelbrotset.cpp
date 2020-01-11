#include "mandelbrotset.h"
#include "ui_mandelbrotset.h"
#include "math.h"
#include <string>
#include <QScrollBar>
#include <QDebug>
#include <pathselection.h>
#include <QMessageBox>


double MfractalDraw::map(int x, int W, double minR, double maxR){
    double range = maxR - minR;
    return x*(range/W)+minR;
}

int MfractalDraw::findM(double cr, double ci, int max_iter){
    int i =0;
    double zr = 0.0, zi = 0.0;
    while(i<max_iter && zr*zr+zi*zi < 4.0){
        double temp = zr*zr -zi*zi +cr;
        zi =2*zr*zi +ci;
        zr = temp;
        i++;
    }
    return i;
}

mandelbrotSet::mandelbrotSet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mandelbrotSet)
{
    ui->setupUi(this);
}

mandelbrotSet::~mandelbrotSet()
{
    delete ui;
}

void mandelbrotSet::on_pushButton_2_clicked()
{

    int zoom = pow(2,ui->zoomSlider->value());
    int max_iter = ui->nDagree->value();

    double dX = 4/zoom;
    double dY = 4/zoom;

    double x = ui->xSlider->value();
    double minX= x/(1000);
    double y = ui->ySlider->value();
    double maxX =minX+dX;
    double minY = y/(1000);
    double maxY = minY+dY;


    int type = ui->colorBox->value();
/*
    qDebug() << minX <<endl;
    qDebug() << maxX <<endl;
    qDebug() <<cX << endl;
    qDebug() << minY <<endl;
    qDebug() << maxY <<endl;
    qDebug() << cY <<endl;
*/


    ui->ySliderLabel->setText("Y: "+ QString::number(minY+dY/(zoom*2), 'g',10));
    ui->xSliderLabel->setText("X: "+ QString::number(minX+dX/(zoom*2), 'g',10));

    MfractalDraw manFrac(type, max_iter, sizeX, sizeY, maxX, minX, maxY, minY);
    manFrac.mDraw();

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(manFrac.image));

    ui->graphicsView->setScene(graphic);
    this->image = manFrac.image;
}

MfractalDraw::~MfractalDraw(){

}

void MfractalDraw::mDraw(){
    for (int l= -sizeX/2; l<sizeX/2; l++){
        for (int c= -sizeY/2; c<sizeY/2; c++){

            double cr = map(l, sizeX, minX, maxX);
            double ci = map(c, sizeY, minY, maxY);

            int iter = findM(cr,ci,max_iter);

            int r;
            int g;
            int b ;

            switch(type) {
                case 0:
                    r = (iter +cr*cr + ci*ci);
                    g = iter*iter%255;
                    b = (cr*cr+ci*ci)*(iter%255);
                break;
                case 1:
                    r = iter%255+cr*cr + ci*ci ;
                    g = iter*iter%255+cr*cr + ci*ci;
                    b = iter*iter*iter%255+cr*cr + ci*ci;
                break;
            case 2:
                    r = cr*ci*cr*ci+iter%255;
                    g = 0;//log(cr*iter);
                    b = 0;//map(ci* cr*3.14, sizeX, 0, 255) ;
                break;
            default:
                r = iter;
                g = iter*iter;
                b = iter*iter*iter;
                break;
            }
            if(iter==max_iter){
                r = 0;
                g = 0;
                b = 0;
            }
            image.setPixel(sizeX/2+l, sizeY/2+c, qRgb(r,g,b));
        }
        }
}

MfractalDraw::MfractalDraw(int  type, int max_iter, int sizeX, int sizeY, double maxX, double minX, double maxY, double minY){
    this->type = type;
    this->max_iter = max_iter;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
    image = QImage(sizeX, sizeY, QImage::Format_RGB32  );
}

void mandelbrotSet::on_zoomSlider_valueChanged(int value)
{
    ui->label_6->setText("Zoom: x"+QString::number(value));
    on_pushButton_2_clicked();
}

void mandelbrotSet::on_nDagree_valueChanged(int value)
{
    ui->label_5->setText("Max iterations: " + QString::number(value));
    if(value < 200){
        on_pushButton_2_clicked();
    }

}

void mandelbrotSet::on_ySlider_valueChanged(int value)
{
    on_pushButton_2_clicked();
}

void mandelbrotSet::on_horizontalSlider_valueChanged(int value)
{

}

void mandelbrotSet::on_xSlider_valueChanged(int value)
{
    on_pushButton_2_clicked();
}

void mandelbrotSet::on_pushButton_3_clicked()
{
    on_pushButton_2_clicked();
    /*
    QGraphicsScene *graphic = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(graphic,this);
    QString fileName = "mandelbrotSet.png";
    QPainter painter(&image);
    view->render(&painter);
    image.save(fileName);
    */
    pathselection *P;

    P = new pathselection;
    P->show();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setText(" Insert valid path, file will not be saved otherwise. ");
    msgBox.exec();
    P->image = this->image;
}
