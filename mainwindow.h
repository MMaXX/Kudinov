#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    Node* r;
    
private slots:
    void on_actionCreate_map_triggered();

    void on_actionLoad_map_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
