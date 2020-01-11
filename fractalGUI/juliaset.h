#ifndef JULIASET_H
#define JULIASET_H

#include <QMainWindow>
#include <QGraphicsItem>
#include "advjulia.h"

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
    double minX, maxX, minY, maxY;
    double long cR, cI, dX, dY;
    int max_iter, zoom;

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

    void grabMouse();

    void mausePressEvent(QGraphicsSceneMouseEvent *scene);

    void on_pushButton_clicked();

private:
    Ui::juliaSet *ui;
    advJulia *aJulia;
};


#endif // JULIASET_H
