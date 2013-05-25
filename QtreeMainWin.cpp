#include <QtGui>
#include"QtreeMainWin.h"
#include<QPushButton>
#include"dialog.h"
QtreeMainWin::QtreeMainWin(QWidget *pwgt):QMainWindow(pwgt)
{
  /*создаем меню*/
  QMenu *mnFile=new QMenu(tr("&File"));
  mnFile->addAction(tr("&Open image"),this,SLOT(slOpenImage()));
  /*при добавлении пункта меню сразу указываем обработчик события нажатия*/
  mnFile->addAction(tr("&Save result"),this,SLOT(slSaveImage()));
  mnFile->addAction(tr("&New Tree"),this,SLOT(slNewTree()));
  menuBar()->addMenu(mnFile);
  
  /*создаем базовые элементы управления*/
  QScrollArea *areaSrcImage=new QScrollArea;
  areaSrcImage->resize(300,300);/* TODO: выставить нормальные размеры областей просмотра*/
  QScrollArea *areaResImage=new QScrollArea;
  areaResImage->resize(300,300);
  wdSrcImage=new QWidget;
  wdSrcImage->resize(250,250);
  wdResImage=new QWidget;
  wdResImage->resize(250,250);
  areaSrcImage->setWidget(wdSrcImage);
  areaResImage->setWidget(wdResImage);
      /*устанавливаем перехватчик событий (чтобы рисовать на вложенном в главное окно виджете;
      * можно и сделать новый виджет для отрисовки рисунка*/
      wdSrcImage->installEventFilter( this );
      wdResImage->installEventFilter( this );

  /*попытка написать отображение области распознавания*/
      wdResImage->setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(wdResImage,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slMark(QPoint)));

  /* кнопка запуска распознавания*/
  QPushButton *btn=new QPushButton;
  btn->setText(tr("Button1"));
  //QObject::connect(btn,SIGNAL(clicked()),this,SLOT(slRecognizePattern()));/*обрабатываем событие нажатия кнопки*/

  /*кнопка запуска анализа*/
  QPushButton *btna=new QPushButton;

  btna->setText(tr("Button2"));
  //QObject::connect(btna,SIGNAL(clicked()),this,SLOT(slAnalize()));/*обрабатываем событие нажатия кнопки*/

  /*поле для индикации результатов анализа*/
  lbl1=new QLabel;
  lbl1->setText(tr("||||"));

  /* ползунок */
  QSlider *sld=new QSlider(Qt::Vertical);
  sld->setRange(0,100);
  sld->setPageStep(1);
  sld->setValue(70);
  //QObject::connect(sld,SIGNAL(valueChanged(int)),this,SLOT(slChangeBorder(int)));/*событие движения ползунка*/

  /* сброс флага события распознавания*/


  /*создаем объекты автоматического размещения*/
  QHBoxLayout *lt1=new QHBoxLayout;
  lt1->setMargin(10);
  lt1->setSpacing(10);
  QVBoxLayout *lt2=new QVBoxLayout;
  lt2->setMargin(10);
  lt2->setSpacing(10);

  /*размещаем виджеты в авторазмещениях*/
  lt2->addWidget(btn);
  lt2->addWidget(btna);
  lt2->addWidget(sld);
  lt2->addWidget(lbl1);
  lt1->addWidget(areaSrcImage);
  lt1->addLayout(lt2);
  lt1->addWidget(areaResImage);

  /*задаем центральный виджет для главного окна*/
  QWidget *ptm=new QWidget;
  ptm->setLayout(lt1);
  setCentralWidget(ptm);
  show();
}

void QtreeMainWin::slMark(QPoint mpoint)
{
    mark(&srcImg,mpoint.x(),mpoint.y());
    wdSrcImage->update();
    mark(&dstImg,mpoint.x(),mpoint.y());
    wdResImage->update();
}

void QtreeMainWin::slOpenImage()
{
  QString fileName = QFileDialog::getOpenFileName(
                      this,
                      tr("Open Image"),
                      "C:\\QtreeApp\\Qtree",
                      tr("Image Files (*.bmp)")
                                                  );
  srcImg.load(fileName);
      wdSrcImage->update();
  //QMessageBox::information(0,"Info",QString::number(srcImg.size().width()));
}
bool QtreeMainWin::eventFilter( QObject * o, QEvent * e )
{
  if((o == wdSrcImage) && (e->type() == QEvent::Paint) && (!srcImg.isNull()))
  {
    wdSrcImage->resize(srcImg.size());
    QPainter pnt(wdSrcImage);
    pnt.setRenderHint(QPainter::Antialiasing, true);
    pnt.eraseRect(wdSrcImage->rect());
    pnt.setPen(QPen(Qt::black,20));
    pnt.drawImage(QPoint(0,0),srcImg);
    //pnt.drawLine(0,0,1000,1000);
    pnt.end();
    return true;
   }
  if((o == wdResImage) &&(e->type() == QEvent::Paint) && (!dstImg.isNull()))
  {
    wdResImage->resize(dstImg.size());
    QPainter rpnt(wdResImage);
    rpnt.drawImage(QPoint(0,0),dstImg);
    rpnt.end();
    return true;
}
      return false;
}
void QtreeMainWin::slSaveImage()
{
}

void QtreeMainWin::slNewTree()
{
    /*QWidget *window = new QWidget;
        window->resize(300, 300);

        QPushButton *quit = new QPushButton;
        quit->setParent(window);
        quit->setText("Push");
        //quit.setFont(QFont("Times", 12, QFont::Bold));
        quit->setGeometry(100, 100, 100, 100);
       // QObject::connect(&quit, SIGNAL(clicked()), this, SLOT(slBt()));
        window->show();
        */

    Dialog *Dial = new Dialog;
    Dial->show();

    /*QWidget* Form = new QWidget;
       Form->setAttribute(Qt::WA_DeleteOnClose, true);
      // QPushButton *bt=new QPushButton;
       QPushButton *bt("Push",&Form);

       //bt->setText(tr("Button"));
       bt->setGeometry(100,100,100,100);
       bt->show();
       QObject::connect(bt,SIGNAL(clicked()),this,SLOT(slBt()));
       Form->show();
       */

}
void QtreeMainWin::slBt()
{

}

//функция выделения распознанного фрагмента
void mark(QImage* img, int si, int sj)
{
    //отрисовка рамки
        for (int i=0; i<(SIDE*INPUT_S); i++)
        {
                /*(*img)(si+i,sj)->Green=150;
                (*img)(si+i,sj)->Red=0;
                (*img)(si+i,sj)->Blue=0;
                (*img)(si+i,sj+(SIDE*INPUT_S))->Green=150;
                (*img)(si+i,sj+(SIDE*INPUT_S))->Red=0;
                (*img)(si+i,sj+(SIDE*INPUT_S))->Blue=0;*/
                img->setPixel(si+i,sj,qRgb(150,0,0));
                img->setPixel(si+i,sj+(SIDE*INPUT_S),qRgb(150,0,0));
        }
        for (int j=0; j<(SIDE*INPUT_S); j++)
        {
                /*(*img)(si,sj+j)->Green=150;
                (*img)(si,sj+j)->Red=0;
                (*img)(si,sj+j)->Blue=0;
                (*img)(si+(SIDE*INPUT_S),sj+j)->Green=150;
                (*img)(si+(SIDE*INPUT_S),sj+j)->Red=0;
                (*img)(si+(SIDE*INPUT_S),sj+j)->Blue=0;	*/
                img->setPixel(si,sj+j,qRgb(150,0,0));
                img->setPixel(si+(SIDE*INPUT_S),sj+j,qRgb(150,0,0));
        }
}
