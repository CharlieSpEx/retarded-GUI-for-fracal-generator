#ifndef ADVJULIA_H
#define ADVJULIA_H

#include <QDialog>
#include "fractaldraw.h"
//#include "fractalgui.h"
//#include "juliaset.h"

namespace Ui {
class advJulia;
}

class advJulia : public QDialog//, juliaSet
{
    Q_OBJECT

public:
    explicit advJulia(QWidget *parent = nullptr, long double dX = 1, long double dY = 1, long double X = 2,long double Y = 2, double zR = 0, double zI = 0);
    ~advJulia();
    int N, max_iter;
    int sizeX = 697;
    int sizeY = 697;
    long double dX, dY, X, Y;
    double zR, zI, R, minX, maxX, minY, maxY;
    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);
    //Ui::advJulia *ui;
    bool drawButtonStatus= false;



private slots:
    bool checkBoxValidation();

    bool nCheckBoxValidation();

    void on_drawButton_clicked();

    void on_nFunctionCheckBox_stateChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_extendedRenderCheckBox_stateChanged(int arg1);

    void verifyNeeded();

private:
    Ui::advJulia *ui;
};

#endif // ADVJULIA_H
