#ifndef Dialog123_H
#define Dialog123_H

#include <QDialog>
#include<QtGui>
#include"Tree.h"



namespace Ui {
class Dialog123;
}

class Dialog123 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog123(QWidget *parent = 0, Node* r = NULL);
    ~Dialog123();
  void SetLine(int,int,int,int);
  void SetPoint(int,int,int);
  void Add_Surround(float,float,float,float,float,float,float,float);
  void Add_Line(int, int, int, int, int);
  Node* Choice(Node*,int,int);
  //int GetDatX(Node*,int);
  //int GetDatY(Node*,int)
  Node* r;

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

  //  void Print(Node*,int);



public:
    QGraphicsScene *scene;
    QGraphicsView *pGraphArea;
    Ui::Dialog123 *ui;
  // void Print(Node*,int);
};

#endif // Dialog123_H
