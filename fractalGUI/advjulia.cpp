#include "advjulia.h"
#include "ui_advjulia.h"
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include "advjulia.h"

#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QGraphicsView>

#include <QFileDialog>



advJulia::advJulia(QWidget *parent, long double dX, long double dY, long double X,long double Y, double zR, double zI) :
    QDialog(parent),
    ui(new Ui::advJulia)
{
    ui->setupUi(this);
    this->dX = dX;
    this->dY = dY;
    this->X = X;
    this->Y = Y;
    this->zR = zR;
    this->zI = zI;

    ui->maxXLineEdit->setText(QString::number(X, 'g', 7));
    ui->maxYLineEdit->setText(QString::number(Y, 'g', 7));
    ui->minXLineEdit->setText(QString::number(dX, 'g', 4));

    ui->lineEdit->setText(QString::number(zI));
    ui->reLineEdit->setText(QString::number(zR));


}

bool advJulia::extendedRenderCheckBoxValidation(){

    // funkcja sprawdza poprawność wpisanych danych dla extended render

    if(ui->extendedRenderCheckBox->isChecked()){
        bool valid = false;
        if(ui->horisontalRes->text().toDouble() <= 0.0){
        ui->horisontalRes->setText("incorrect value");}
        else{
            valid = true;
        }

        if(ui->verticalRes->text().toDouble() <= 0.0){
        ui->verticalRes->setText("incorrect value");
        valid = false;
        }else{
            valid = true;
        }
        if (valid){
         this->sizeX = ui->verticalRes->text().toInt();
         this->sizeY = ui->horisontalRes->text().toInt();
        }
        return valid;}
    else{
        sizeX = 697;
        sizeY = 697;
        return true;
    }



}

bool advJulia::nCheckBoxValidation(){

    // funkcja sprawdzająca czy nCheckBox czyli popraność wpisanych danych
    // dla stopnia iterowanej funkcji ( int N )

    if(ui->nFunctionCheckBox->isChecked()){
        if(ui->lineEdit_2->text().toInt() <= 2){
            ui->lineEdit_2->setText("incorrect value");
            return false;
        }else{
        this->N = ui->lineEdit_2->text().toInt();
        return true;
    }}else{
        N = 0;
        return true;
    }
}

bool advJulia::checkBoxValidation(){

    // funkcja sprawdzająca czy w przypadki zaznaczenie checkBoxów do edycji parametrów,
    // zostały wprowadzone odpowiednie parametry

    bool valid = false;

    valid = (nCheckBoxValidation()&&extendedRenderCheckBoxValidation());


    if (valid == false){
        return valid;
    }

    if (ui->checkBox->isChecked()){
        double failVal = 0.0;
    if(ui->minXLineEdit->text().toDouble() != failVal) {
        this->dX=ui->minXLineEdit->text().toDouble();
        qDebug() << QString::number(dX, 'g', 10) << endl;

        if(ui->maxXLineEdit->text().toDouble() != failVal){
            this->X=ui->maxXLineEdit->text().toDouble();

            if(ui->maxYLineEdit->text().toDouble() != failVal){
                this->Y=ui->maxYLineEdit->text().toDouble();
                valid = true;
            }else{
                ui->maxYLineEdit->setText("incorrect value");
                valid = false;

            }
        }else{
            ui->maxXLineEdit->setText("incorrect value");
            valid = false;

    }
    }else{
        ui->minXLineEdit->setText("incorrect value");
        valid = false;
    }
    }else valid = true;
    return valid;



}

void advJulia::verifyNeeded(){

    // Sprawdzanie czy wartości wpisane w wymaganych polach są odpowiednie,
    // jeśli nie, to ustala je na domyślne
    //
    // Re(c) i Im(c)
    if(ui->lineEdit->text().toDouble() == 0.0){
        ui->lineEdit->setText(QString::number(0.0));
    }
    else if(ui->lineEdit->text().toDouble() >= 1.0){
        ui->lineEdit->setText(QString::number(1.0));
    }
    else if(ui->lineEdit->text().toDouble() <= -1.0){
        ui->lineEdit->setText(QString::number(-1.0));
    }
    if(ui->reLineEdit->text().toDouble() == 0.0){
        ui->reLineEdit->setText(QString::number(0.0));
    }
    else if(ui->reLineEdit->text().toDouble() >= 1.0){
        ui->reLineEdit->setText(QString::number(1.0));
    }
    else if(ui->reLineEdit->text().toDouble() <= -1.0){
        ui->reLineEdit->setText(QString::number(-1.0));
    }

    // max iterations i escape range
    if(ui->maxIterationsLineEdit->text().toInt() <= 0){
        ui->maxIterationsLineEdit->setText(QString::number(10));
    }
    if(ui->maxIterationsLineEdit_2->text().toDouble()<= 0){
        ui->maxIterationsLineEdit_2->setText(QString::number(2));
    }

}

advJulia::~advJulia()
{
    delete ui;
}

void advJulia::on_drawButton_clicked()
{

        drawButtonStatus = true;
    if(checkBoxValidation() == false){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText(" Please input correct values! ");
        msgBox.exec();
    }else{
        verifyNeeded();

        // generowanie fractalu
         minX = X-dX/2;
         maxX = X+dX/2;
         minY = Y-dX/2;
         maxY = Y+dX/2;

        zR = ui->reLineEdit->text().toDouble();
        zI = ui->lineEdit->text().toDouble();
        R = ui->maxIterationsLineEdit_2->text().toDouble();
        max_iter = ui->maxIterationsLineEdit->text().toInt();

         int type = ui->spinBox->value();

          qDebug() <<"dX: "<< QString::number(dX, 'g', 4) << endl;
          qDebug() <<"cX: "<< QString::number(X, 'g', 4) << endl;
          qDebug() <<"cY: "<< QString::number(Y, 'g', 4) << endl;
          qDebug() <<"N: "<< N << endl;
          qDebug() <<"R: "<< R << endl;


        fractalDraw Wrr(type, sizeX, sizeY, zR, zI, max_iter,  minX, maxX, minY, maxY);
        if(N>0){
            Wrr.nDraw(N, R);
        }else{
            Wrr.draw();
        }
        this->image = Wrr.image;

        //  Otwieranie nowego okna z wykonanym fractalem

        QWidget *window = new QWidget;
        window->setWindowTitle("Advanced Julia's Set render");
        window->resize(sizeX+30, sizeY+30);

        QGridLayout *layout = new QGridLayout;
        QGraphicsScene *graphics = new QGraphicsScene;

        graphics->addPixmap(QPixmap::fromImage(image));

        QGraphicsView* view = new QGraphicsView(graphics,this);
        QPainter painter(&image);

        view->render(&painter);
        layout->addWidget(view, 0, 0);

        window->setLayout(layout);
        window->close();
        window->show();


    }
}

void advJulia::on_nFunctionCheckBox_stateChanged(int arg1)
{
    ui->lineEdit_2->setText("must be filled");
    if (arg1 == 1){
        if(ui->lineEdit_2->text().toInt() == 0){
            ui->lineEdit_2->setText("incorrect value");
        }else{
        this->N = ui->lineEdit_2->text().toInt();
        }
    }
    else{
        N = 0;
    }
    if (arg1 == 0){
        ui->lineEdit_2->setText("");
    }
}


void advJulia::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()){
        double failVal = 0.0;
    if(ui->minXLineEdit->text().toDouble() != failVal){
        this->dX=ui->minXLineEdit->text().toDouble();
    }else{
        ui->minXLineEdit->setText("must be filled");
    }
    if(ui->maxXLineEdit->text().toDouble() != failVal){
        this->X=ui->maxXLineEdit->text().toDouble();
    }else{
        ui->maxXLineEdit->setText("must be filled");
    }
    if(ui->maxYLineEdit->text().toDouble() != failVal){
        this->Y=ui->maxYLineEdit->text().toDouble();
    }else{
        ui->maxYLineEdit->setText("must be filled");
    }
}else{

        ui->minXLineEdit->setText("");
        ui->maxYLineEdit->setText("");
        ui->maxXLineEdit->setText("");
    }
}

void advJulia::on_extendedRenderCheckBox_stateChanged(int arg1)
{
    if(ui->horisontalRes->text().toDouble() == 0.0){
    ui->horisontalRes->setText("must be filled");}

    if(ui->verticalRes->text().toDouble() == 0.0){
    ui->verticalRes->setText("must be filled");}


}


void advJulia::on_pushButton_clicked()
{
    // zapisywanie do pliku
    QString path = "";

    pathselection *P;

    P = new pathselection;
    P->show();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setText(" Insert valid path, file will not be saved otherwise. ");
    msgBox.exec();
    P->image = this->image;


}
