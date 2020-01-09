#include "fractalgui.h"
#include "ui_fractalgui.h"

fractalGUI::fractalGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fractalGUI)
{
    ui->setupUi(this);
}

fractalGUI::~fractalGUI()
{
    delete ui;
}



void fractalGUI::on_juliaButton_clicked()
{
    jSet = new juliaSet(this);
    jSet->show();
}

void fractalGUI::on_mandelButton_clicked()
{
    mSet = new mandelbrotSet(this);
    mSet->show();
}

void fractalGUI::on_newtButton_clicked()
{
    nFractal = new newtonFractal(this);
    nFractal->show();
}

void fractalGUI::on_sierpButton_clicked()
{
    sTriangle = new sierpinskiTriangle(this);
    sTriangle->show();
}

void fractalGUI::on_kochButton_clicked()
{
    kSnow = new kochSnowflake(this);
    kSnow->show();
}
