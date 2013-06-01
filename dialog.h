#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QtGui>
#include"Tree.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0, Node* r = NULL);
    ~Dialog();
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

    void on_lineEdit_3_editingFinished();

    void on_pushButton_2_clicked();

  //  void Print(Node*,int);

    void on_pushButton_3_clicked();

public:
    QGraphicsScene *scene;
    QGraphicsView *pGraphArea;
    Ui::Dialog *ui;
  // void Print(Node*,int);
};

#endif // DIALOG_H
