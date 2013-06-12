#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog123.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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
