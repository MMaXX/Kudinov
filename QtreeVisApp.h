#ifndef QTREEVISAPP_H
#define QTREEVISAPP_H
/*!\file заголовочный файл приложения*/
#include <QtGui>
#include "QtreeMainWin.h"
/*!\class Класс приложения*/
class QtreeVisApp: public QApplication
{
  Q_OBJECT
 public:
QtreeVisApp(int argc, char* argv[])
    :QApplication(argc,argv)
{
  mwd=new QtreeMainWin;
  exec();
}
 private:
  QtreeMainWin* mwd;
};
#endif // QTREEVISAPP_H
