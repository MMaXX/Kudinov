#include<QDebug>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QtGui>
#include "Dialog123.h"
#include "ui_Dialog123.h"
#include "Tree.h"
#include "math.h"
#include <cmath>
#include <iostream>

#define roundf(x) floor(x+0.5f)


Dialog123::Dialog123(QWidget *parent, Node* _r) :
    QDialog(parent),
    r(_r),
    ui(new Ui::Dialog123)
{
         ui->setupUi(this);

         pGraphArea =ui->graphicsView;
         scene = new QGraphicsScene;
         pGraphArea->setScene(scene);
         qDebug()<<scene;
         scene->setSceneRect(0,0,512,512);



}

Dialog123::~Dialog123()
{
    delete ui;
}

/* data needed to draw one node of a tree */
struct draw_context{
    QGraphicsScene *scene;
    QBrush *brush_black;
    QBrush *brush_white;};

/* function for tree drawing*/
void draw_tree_func(Node *p, void *parameter){
    draw_context *context = (draw_context *) parameter;
    if(p->state > 0.5 && p->state <= 1)
        context->scene->addRect(p->xmin,p->ymin,p->xmax - p->xmin,p->ymax - p->ymin,QPen(QColor(0,0,0,0)), *context->brush_white);
    else
        if(p->state >= 0)
            context->scene->addRect(p->xmin,p->ymin,p->xmax - p->xmin,p->ymax - p->ymin,QPen(QColor(0,0,0,0)), *context->brush_black);
    }

/* drawing tree using iterator */
void draw_tree(Node *p, QGraphicsScene *scene){
    /* create context for drawing */
    draw_context cnt;
    cnt.scene=scene;
    cnt.brush_black = new QBrush(Qt::black);
    cnt.brush_white = new QBrush(Qt::white);
    iterate_tree(p, &cnt, &draw_tree_func);
    delete cnt.brush_black;
    delete cnt.brush_white;}


int number;

void Dialog123::on_pushButton_clicked(){

    /* insert data in tree */
    add(&r,ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt(),8,1);
    qDebug()<<"Tree is:";
    print_tree(r);
    qDebug()<<"-------";
    /* redraw tree */
    //QPen pen(Qt::black);
    QBrush br_grey(QColor(128,128,128));

    /* draw grey rectangle in full map size*/
    scene->clear();
    scene->addRect(0,0,512,512,QPen(),br_grey);
    draw_tree(r,scene);
}

void Dialog123::SetLine(int x1,int y1,int x2, int y2)
{
    scene->addLine(x1,y1,x2,y2);
}

/*
int Dialog123::GetDatX(Node* n, int x)
{
    int res;
    if (x<n->xmid)
        res=n->xmid-1;
    if (x>n->xmid)
        res=n->xmid+1;
    qDebug()<<"GetDatX"<<res;
        return res;
}
int Dialog123::GetDatY(Node* n, int y)
{
    int res;
    if (y<n->ymid)
        res=n->ymid-1;
    if (y>n->ymid)
        res=n->ymid+1;
    qDebug()<<"GetDatY"<<res;
        return res;
}
*/

void Dialog123::SetPoint(int x, int y, int size){
    add(&r,x,y,size,1);

}

void Dialog123::Add_Line(int x1, int y1, int x2, int y2, int size){
    float xfin,yfin;

          int dx = (x2 - x1 >= 0 ? size : -size);
          int dy = (y2 - y1 >= 0 ? size : -size);

          int lengthX = abs(x2 - x1);
          int lengthY = abs(y2 - y1);

          int length = std::max(lengthX, lengthY);

          if (length == 0)
          {
                //SetPixel(hdc, x1, y1, 0);
          }

          if (lengthY <= lengthX)
          {
                // Начальные значения
                int x = x1;
                float y = y1;
                float m;

                // Основной цикл
                length++;

                while(length>=0)

                {
                    m=roundf(y);
                    add(&r,x,(roundf(y/size)*size),size,1);
                    xfin=x;
                    yfin=roundf(y/size)*size;
                      x += dx;
                      y += dy * float(lengthY) / lengthX;
                      length=length-size;
                }
                add(&r,xfin,yfin,size,0); //последний черный квадрат

          }
          else
          {
                // Начальные значения
                float x = x1;
                int y = y1;

                // Основной цикл
                length++;
                while(length>=0)
                {
                      add(&r,(roundf(x/size)*size),y,size,1);
                      xfin=roundf(x/size)*size;
                      yfin=y;
                      x += dx * float(lengthX) / lengthY;
                      y += dy;
                      length=length-size;
                }
                add(&r,xfin,yfin,size,0); //последний черный квадрат/

          }
}
void Dialog123::Add_Surround(float sig_r,float x_r,float y_r,float r,float sig_f,float x_f,float y_f,float f){
    float x,y;
    x=(1/(sig_r * sqrt(6.28)))*exp(-((x_r-r)*(x_r-r))/(2*sig_r*sig_r))*cos((1/(sig_f * sqrt(6.28)))*exp(-((x_f-f)*(x_f-f))/(2*sig_f*sig_f)));
    y=(1/(sig_r * sqrt(6.28)))*exp(-((y_r-r)*(y_r-r))/(2*sig_r*sig_r))*cos((1/(sig_f * sqrt(6.28)))*exp(-((y_f-f)*(y_f-f))/(2*sig_f*sig_f)));
    qDebug()<<"Surround x"<<x;
    qDebug()<<"Surround y"<<y;
}




/*
    QGraphicsView *pGraphArea = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene;
    pGraphArea->setScene(scene);
    scene->setSceneRect(0,0,600,600);

    scene->addLine(0,300,600,300);
    scene->addLine(300,0,300,600);*/






void Dialog123::on_pushButton_2_clicked()
{
    qDebug()<<"Clicked";


    qDebug()<<"r v pushButtonClicked"<<r;
 //   SetPoint(100,100,8);

    Add_Surround(0.7,0.1,0.1,0,0.7,0.1,0.1,0);
  Add_Line(ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt(),ui->lineEdit_5->text().toInt(),ui->lineEdit_6->text().toInt(),8);
    QBrush br_grey(QColor(128,128,128));

    /* draw grey rectangle in full map size*/
    scene->clear();
    scene->addRect(0,0,512,512,QPen(),br_grey);
    draw_tree(r,scene);
}

