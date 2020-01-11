#include "drawwindow.h"
#include "ui_drawwindow.h"

drawWindow::drawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawWindow)
{
    ui->setupUi(this);
}

drawWindow::~drawWindow()
{
    delete ui;
}
