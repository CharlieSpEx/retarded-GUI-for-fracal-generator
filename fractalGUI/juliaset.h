#ifndef JULIASET_H
#define JULIASET_H

#include <QMainWindow>

namespace Ui {
class juliaSet;
}

class juliaSet : public QMainWindow
{
    Q_OBJECT

public:
    explicit juliaSet(QWidget *parent = nullptr);
    ~juliaSet();
    int sizeX = 697;
    int sizeY = 697;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32  );

private slots:
    void on_pushButton_2_clicked();

    void on_drawButton_clicked();

    void on_ySlider_valueChanged(int value);

    void on_xSlider_valueChanged(int value);

    void on_cReSlider_valueChanged(int value);

    void on_cImSlider_valueChanged(int value);

    void on_zSlider_valueChanged(int value);

    void on_nDagreeslider_valueChanged(int value);

    void on_drawButton_2_clicked();

private:
    Ui::juliaSet *ui;
};

class fractalDraw : public juliaSet{
public:
    double  zR, zI, maxX, minX, maxY, minY;
    int sizeX, sizeY,max_iter, type;
    QImage image;
    fractalDraw(int type, int sizeX, int sizeY, double zR, double zI, int max_iter, double minX, double maxX, double minY, double maxY);
    ~fractalDraw();
    int nFindM(double cr, double ci, int max_iter, double zR, double zI, int n, double r);
    int FindM(double cr, double ci, int max_iter, double zR, double zI);
    double Map(int x, int W, double minR, double maxR);
    void draw();
    //QGraphicsScene graphic;
private:

};

#endif // JULIASET_H
