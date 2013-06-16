#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QGraphicsScene>
#include "Tree.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0, Node* r = NULL);
    ~MainWindow();
    void SetLine(int,int,int,int);
    void SetPoint(int,int,int);
    void Massiv(int,int,short mas[20]);
    void Add_Surround(int x, int y, double dx, double dy, int size);
    void Add_Line(int, int, int, int, int);
    Node* Choice(Node*,int,int);
    
private slots:
    void on_actionCreate_map_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_actionLoad_map_triggered();

private:
    Ui::MainWindow *ui;
	Node* r;
    QGraphicsScene *scene;
    QGraphicsView *pGraphArea;
};

#endif // MAINWINDOW_H
