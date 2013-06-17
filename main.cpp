
#include <QtGui/QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication apl(argc, argv);
    MainWindow *MW =new MainWindow;
    MW->show();
  /*  WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    */return apl.exec();
}
