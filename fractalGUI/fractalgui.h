#ifndef FRACTALGUI_H
#define FRACTALGUI_H

#include <QMainWindow>
#include "juliaset.h"
#include "kochsnowflake.h"
#include "mandelbrotset.h"
#include "newtonfractal.h"
#include "sierpinskitriangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fractalGUI; }
QT_END_NAMESPACE

class fractalGUI : public QMainWindow
{
    Q_OBJECT

public:
    fractalGUI(QWidget *parent = nullptr);
    ~fractalGUI();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_kochButton_clicked();

    void on_juliaButton_clicked();

    void on_mandelButton_clicked();

    void on_newtButton_clicked();

    void on_sierpButton_clicked();

private:
    Ui::fractalGUI *ui;
    juliaSet *jSet;
    kochSnowflake *kSnow;
    mandelbrotSet *mSet;
    newtonFractal *nFractal;
    sierpinskiTriangle *sTriangle;

};
#endif // FRACTALGUI_H
