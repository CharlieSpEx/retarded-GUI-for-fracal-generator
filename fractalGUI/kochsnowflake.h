#ifndef KOCHSNOWFLAKE_H
#define KOCHSNOWFLAKE_H

#include <QMainWindow>

namespace Ui {
class kochSnowflake;
}

class kochSnowflake : public QMainWindow
{
    Q_OBJECT

public:
    explicit kochSnowflake(QWidget *parent = nullptr);
    ~kochSnowflake();

private:
    Ui::kochSnowflake *ui;
};

#endif // KOCHSNOWFLAKE_H
