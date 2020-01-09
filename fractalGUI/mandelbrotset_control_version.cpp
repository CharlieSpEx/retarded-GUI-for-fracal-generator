#include "mandelbrotset.h"
#include "ui_mandelbrotset.h"
#include "math.h"
#include <string>
#include <QScrollBar>


double map(int x, int W, double minR, double maxR){
    double range = maxR - minR;
    return x*(range/W)+minR;
}

int findM(double cr, double ci, int max_iter){
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


bool event2 = false;

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
    int sizeX = 904;
    int sizeY = 904;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32  );



    double dX = 2.5;
    double dY = 2.5;

    double minX= ui->xSlider->value()/10;
    double maxX =minX+dX;
    double minY = ui->ySlideder->value()/10;
    double maxY = minY+dY;


    /*
    double minX= ui->xSlider->value()/10;
    double maxX = ui->lineEdit_2->text().toDouble();
    double minY = ui->minY->text().toDouble();
    double maxY = ui->maxY->text().toDouble();
     */

    int max_iter = ui->nDagree->value();
    //int zoom = ui->zSlider->value();
    int zoom = ui->zoomSlider->value();


    minX = map(minX, zoom, minX, maxX);
    maxX = map(maxX, zoom, minX, maxX);
    minY = map(minY, zoom, minY, maxY);
    maxY = map(maxY, zoom, minY, maxY);

    if(false){
       minY = ui->graphicsView->verticalScrollBar()->minimum();
       maxY = ui->graphicsView->verticalScrollBar()->maximum();
       minX = ui->graphicsView->horizontalScrollBar()->minimum();
        maxX = ui->graphicsView->horizontalScrollBar()->maximum();
        //ui->lineEdit_2->setText(QString::number(maxX = ui->graphicsView->horizontalScrollBar()->maximum()));
        // ui->minX->setText(QString::number(ui->graphicsView->horizontalScrollBar()->minimum()));
    }

    //ui->lineEdit_2->setText(QString::number(maxX));
    //ui->minX->setText(QString::number(minX));
    //ui->maxY->setText(QString::number(maxY));
    //ui->minY->setText(QString::number(minY));


    for (int l= -sizeX/2; l<sizeX/2; l++){
        for (int c= -sizeY/2; c<sizeY/2; c++){

            double cr = map(l, sizeX, minX, maxX);
            double ci = map(c, sizeY, minY, maxY);


            int iter = findM(cr,ci,max_iter);

            int r = iter%255;
            int g = (iter*iter)%255;
            int b = (iter*iter*iter)%255;
            if(iter==max_iter){
                r = 0;
                g = 0;
                b = 0;
            }
            image.setPixel(sizeX/2+l, sizeY/2+c, qRgb(r,g,b));
        }
        }

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);
}



void mandelbrotSet::on_zoomSlider_valueChanged(int value)
{
    ui->label_6->setText("Zoom: x"+QString::number(value));
}



void mandelbrotSet::on_nDagree_valueChanged(int value)
{
    ui->label_5->setText("Max iterations: " + QString::number(value));

}
