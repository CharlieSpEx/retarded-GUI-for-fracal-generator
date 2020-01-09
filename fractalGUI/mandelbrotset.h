#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <QMainWindow>

namespace Ui {
class mandelbrotSet;
}

class mandelbrotSet : public QMainWindow
{
    Q_OBJECT

public:
    explicit mandelbrotSet(QWidget *parent = nullptr);
    ~mandelbrotSet();
    int sizeX = 695;
    int sizeY = 695;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32  );
    //QGraphicsScene *graphic = new QGraphicsScene(this);

private slots:
    void on_pushButton_2_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_zoomSlider_valueChanged(int value);

    void on_zoomSlider_sliderMoved(int position);

    void on_nDagree_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_xSlider_valueChanged(int value);

    void on_pushButton_3_clicked();

private:
    Ui::mandelbrotSet *ui;
};

class MfractalDraw : public mandelbrotSet{

public:
    double  zR, zI, maxX, minX, maxY, minY;
    int sizeX, sizeY,max_iter, type;
    QImage image;
    void draw();
    double map(int x, int W, double minR, double maxR);
    int findM(double cr, double ci, int max_iter);
    MfractalDraw(int  type, int max_iter, int sizeX, int sizeY, double maxX, double minX, double maxY, double minY);
    ~MfractalDraw();
    void mDraw();
private:

};

#endif // MANDELBROTSET_H
