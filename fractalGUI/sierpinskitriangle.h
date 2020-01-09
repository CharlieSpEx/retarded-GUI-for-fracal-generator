#ifndef SIERPINSKITRIANGLE_H
#define SIERPINSKITRIANGLE_H

#include <QMainWindow>

namespace Ui {
class sierpinskiTriangle;
}

class sierpinskiTriangle : public QMainWindow
{
    Q_OBJECT

public:
    explicit sierpinskiTriangle(QWidget *parent = nullptr);
    ~sierpinskiTriangle();

private:
    Ui::sierpinskiTriangle *ui;
};

#endif // SIERPINSKITRIANGLE_H
