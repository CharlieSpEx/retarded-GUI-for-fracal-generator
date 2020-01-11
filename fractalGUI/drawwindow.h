#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>

namespace Ui {
class drawWindow;
}

class drawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit drawWindow(QWidget *parent = nullptr);
    ~drawWindow();

private:
    Ui::drawWindow *ui;
};

#endif // DRAWWINDOW_H
