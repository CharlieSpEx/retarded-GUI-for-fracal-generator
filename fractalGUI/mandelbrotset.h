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

    //void on_textEdit_copyAvailable(bool b);

    void on_zoomSlider_valueChanged(int value);

    //void on_zoomSlider_sliderMoved(int position);

    void on_nDagree_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_xSlider_valueChanged(int value);

    void on_pushButton_3_clicked();

private:
    Ui::mandelbrotSet *ui;
};


#endif // MANDELBROTSET_H
