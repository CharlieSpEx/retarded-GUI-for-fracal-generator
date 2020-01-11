#include "juliaset.h"
#include "ui_juliaset.h"
#include "math.h"
#include <string>
#include <QScrollBar>
#include <QDebug>
#include "fractaldraw.h"


double oMap(int x, int W, double minR, double maxR){
    double range = maxR - minR;
    return x*(range/W)+minR;
}

juliaSet::juliaSet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::juliaSet)
{
    ui->setupUi(this);
    on_drawButton_clicked();
}



juliaSet::~juliaSet()
{
    delete ui;
}

void juliaSet::on_drawButton_clicked()
{

    zoom = pow(1.5,ui->zSlider->value());
    max_iter = ui->nDagreeslider->value();

    dX = 4.0/zoom;
    dY = 4.0/zoom;

    double x =ui->xSlider->value();
    minX= x/1000;
    maxX =minX+dX;
    double y = ui->ySlider->value();
    minY = y/1000;
    maxY = minY+dY;




    ui->ySliderLabel->setText("Y: "+ QString::number(minY+dY/(zoom*2), 'g',5));
    ui->zSliderLabel->setText("X: "+ QString::number(minX+dX/(zoom*2), 'g',5));


    double tR = ui->cReSlider->value();
    double tI = ui->cImSlider->value();
    cR = tR/10000;
    cI = tI/10000;

    ui->reC->setText("Re(c): "+ QString::number(cR, 'g', 5));
    ui->imC->setText("Im(c): "+ QString::number(cI, 'g', 5));

    int type = juliaSet::ui->cPattern->value();

    fractalDraw Wrr(type, sizeX, sizeY, cR, cI, max_iter, minX, maxX, minY, maxY);
    Wrr.draw();

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(Wrr.image));

    ui->graphicsView->setScene(graphic);
    this->image = Wrr.image;
}

void juliaSet::on_ySlider_valueChanged(int value)
{
    on_drawButton_clicked();
}

void juliaSet::on_xSlider_valueChanged(int value)
{
        on_drawButton_clicked();

}

void juliaSet::on_cReSlider_valueChanged(int value)
{
    on_drawButton_clicked();

}

void juliaSet::on_cImSlider_valueChanged(int value)
{
    on_drawButton_clicked();

}

void juliaSet::on_zSlider_valueChanged(int value)
{
    on_drawButton_clicked();
    ui->zoomLabel->setText("Zoom: x"+QString::number(value));
}

void juliaSet::on_nDagreeslider_valueChanged(int value)
{
    ui->nDagreeLabel->setText("Max iterations: " + QString::number(value));
    if(value < 200){
        on_drawButton_clicked();
    }
}

void juliaSet::on_drawButton_2_clicked()
{
    on_drawButton_clicked();
    QGraphicsScene *graphic = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(graphic,this);
    QString fileName = "juliaSet.png";
    QPainter painter(&image);
    view->render(&painter);
    image.save(fileName);
}

void juliaSet::grabMouse(){
}

void juliaSet::mausePressEvent(QGraphicsSceneMouseEvent *scene)
{

}

void juliaSet::on_pushButton_clicked()
{
    long double cenX = (maxX-minX)/2 + minX;
    long double cenY = (maxY-minY)/2 + minY;

    aJulia = new advJulia(this,dX, dY, cenX, cenY,cR, cI);

    aJulia->show();

    this->close();


}

