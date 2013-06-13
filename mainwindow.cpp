#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog123.h"
#include "Tree.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent, Node* _r) :
    QMainWindow(parent),
    r(_r),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionCreate_map_triggered()
{
    Dialog123 *Dial = new Dialog123;
    Dial->show();
}



void MainWindow::on_actionLoad_map_triggered()  // ??????? загрузка карты из файла
{
    QString temp1, temp2;
    QFile file("c://test.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out(&file);
    while (!out.atEnd()){
    out >> temp1;
    out >> temp2;
    add(&r,temp1.toInt(),temp2.toInt(),8,1);
    }
    file.close();
    Dialog123 *Dial = new Dialog123;
    Dial->show();
}
