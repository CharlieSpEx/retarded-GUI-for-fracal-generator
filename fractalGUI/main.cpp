#include "fractalgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fractalGUI w;
    w.show();
    return a.exec();
}
