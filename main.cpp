
#include <QtGui/QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication apl(argc, argv);
    MainWindow *MW =new MainWindow;
    MW->show();
    return apl.exec();
}
