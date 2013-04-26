#ifndef QTREEMAINWIN_H
#define QTREEMAINWIN_H

/*! Файл главного окна приложения*/
#include <QtGui>

const int INPUT_LEN=64;
const int SIDE=6;
const int INPUT_S=8;
/* из исходного варианта */
#include <stdlib.h>
#include <list>
//#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
void mark(QImage* img, int si, int sj);
//операция пометки одной точки
void mark_s(QImage* img, int si, int sj,float recognized,float bdRec);

struct NeuPoint{int x;
    int y;};


class QtreeMainWin:public QMainWindow
{
Q_OBJECT
private:
    QLabel *lbl1;
  public:
  /* конструктор главного окна*/
    QtreeMainWin(QWidget *pwgt=NULL);
 protected:
  /*обработчик события рисования*/
    bool eventFilter( QObject * o, QEvent * e );
 private:
  QWidget *wdSrcImage;/*!< поле первого изображения*/
  QWidget *wdResImage;/*!< поле результирующего изображения*/
  QImage srcImg;/*исходное и результирующее изображения*/
  QImage dstImg;

public slots:
  void slOpenImage();
  void slBt();
  void slNewTree();
  void slSaveImage();
  void slMark(QPoint mpoint);

};
#endif // QTREEMAINWIN_H
