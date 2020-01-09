#include "sierpinskitriangle.h"
#include "ui_sierpinskitriangle.h"

sierpinskiTriangle::sierpinskiTriangle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sierpinskiTriangle)
{
    ui->setupUi(this);
}

sierpinskiTriangle::~sierpinskiTriangle()
{
    delete ui;
}
