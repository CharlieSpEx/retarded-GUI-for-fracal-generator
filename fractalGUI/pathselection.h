#ifndef PATHSELECTION_H
#define PATHSELECTION_H

#include <QDialog>

namespace Ui {
class pathselection;
}

class pathselection : public QDialog
{
    Q_OBJECT

public:
    explicit pathselection(QWidget *parent = nullptr);
    ~pathselection();
    QString path, name;
    QImage image;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pathselection *ui;
};

#endif // PATHSELECTION_H
