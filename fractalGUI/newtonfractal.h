#ifndef NEWTONFRACTAL_H
#define NEWTONFRACTAL_H

#include <QMainWindow>


namespace Ui {
class newtonFractal;
}

class newtonFractal : public QMainWindow
{
    Q_OBJECT

public:
    explicit newtonFractal(QWidget *parent = nullptr);
    ~newtonFractal();

private:
    Ui::newtonFractal *ui;
};

#endif // NEWTONFRACTAL_H
