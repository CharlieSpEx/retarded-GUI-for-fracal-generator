#include "newtonfractal.h"
#include "ui_newtonfractal.h"
#include "math.h"

double diff(int n, double X){
    double result=0;
    for (int i = 0; i<=n; i++){
        result += pow(X, i)*(i+1);
    }
}


newtonFractal::newtonFractal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newtonFractal)
{
    ui->setupUi(this);
}

newtonFractal::~newtonFractal()
{
    delete ui;
}
