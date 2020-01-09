#include "kochsnowflake.h"
#include "ui_kochsnowflake.h"

kochSnowflake::kochSnowflake(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kochSnowflake)
{
    ui->setupUi(this);
}

kochSnowflake::~kochSnowflake()
{
    delete ui;
}
