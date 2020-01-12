#include "mandelbrotset.h"
#include "ui_mandelbrotset.h"
#include "math.h"
#include <string>
#include <QScrollBar>
#include <QDebug>
#include <pathselection.h>
#include <QMessageBox>
#include <fractaldraw.h>


mandelbrotSet::mandelbrotSet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mandelbrotSet)
{
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

mandelbrotSet::~mandelbrotSet()
{
    delete ui;
}

void mandelbrotSet::on_pushButton_2_clicked()
{

    int zoom = pow(1.5,ui->zoomSlider->value());
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
    manFrac.draw();

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(manFrac.image));

    ui->graphicsView->setScene(graphic);
    this->image = manFrac.image;
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

    pathselection *P;

    P = new pathselection;
    P->show();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setText(" Insert valid path, file will not be saved otherwise. ");
    msgBox.exec();
    P->image = this->image;
}
