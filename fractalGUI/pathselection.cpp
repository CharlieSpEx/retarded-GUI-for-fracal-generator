#include "pathselection.h"
#include "ui_pathselection.h"

pathselection::pathselection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pathselection)
{
    ui->setupUi(this);
}

pathselection::~pathselection()
{
    delete ui;
}

void pathselection::on_pushButton_clicked()
{
    this->path = ui->lineEdit->text() + "\\";
    this->name = ui->lineEdit_2->text()+".jpg" ;
    this->close();
    image.save(path+ name, "PNG" ,100);
}

void pathselection::on_pushButton_2_clicked()
{
    this->path = "";
    this->close();
    image.save("RenderImage.jpg", "PNG", 100);

}
