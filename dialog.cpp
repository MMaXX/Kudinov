#include<QDebug>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QtGui>
#include "dialog.h"
#include "ui_dialog.h"
#include "dialog1.h"
#include "Tree.h"


Dialog::Dialog(QWidget *parent, Node* _r) :
    QDialog(parent),
    r(_r),
    ui(new Ui::Dialog)
{
         ui->setupUi(this);

         pGraphArea =ui->graphicsView;
         scene = new QGraphicsScene;
         pGraphArea->setScene(scene);
         qDebug()<<scene;
         scene->setSceneRect(0,0,512,512);



}

Dialog::~Dialog()
{
    delete ui;
}


int number;
//Node* r=NULL;

void Dialog::on_pushButton_clicked()
{

    if (number>0){
        Data* d;
        d=(Data*)malloc(sizeof(Data));
        d->x=ui->lineEdit->text().toInt();
        d->y=ui->lineEdit_2->text().toInt();
        d->string="123";
        Info* inf;
        inf=(Info*)malloc(sizeof(Info));
        inf->x=ui->lineEdit->text().toInt();
        inf->y=ui->lineEdit_2->text().toInt();
        inf->string="123";
        add(&r,inf,d);
       // qDebug()<<r->xmid<<r->ymid;

        QPen pen(Qt::black);
        QBrush br(Qt::black);
        qDebug()<<"rxmid rymid"<<r->xmid<<r->ymid;
        /*
        if (ui->checkBox->isChecked()){
        if (inf->x < r->xmid && inf->y < r->ymid){
            scene->addRect(r->xmin,r->ymin,r->xmid - r->xmin,r->ymid - r->ymin,pen,br);

        }

        if (inf->x < r->xmid && inf->y > r->ymid){
            scene->addRect(r->xmin,r->ymid,r->xmid - r->xmin,r->ymax - r->ymid,pen,br);

        }
        if (inf->x > r->xmid && inf->y < r->ymid){
            scene->addRect(r->xmid,r->ymin,r->xmax - r->xmid,r->ymid - r->ymin,pen,br);

        }
        if (inf->x > r->xmid && inf->y > r->ymid){
            scene->addRect(r->xmid,r->ymid,r->xmax - r->xmid,r->ymax - r->ymid,pen,br);

        }
        }
        */
      //  SetPoint(r,100,100);
       Print(r,0);
      // SetLine(0,0,200,230);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
    else{
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
    }
    if (number==1){
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
    }
    number=number-1;
   // ui->pushButton->setText(ui->lineEdit->text());
    //ui->label->setText(ui->lineEdit_2->text());


//ui->label
    //ui->lineEdit_2->text()=ui->label.text();
}

void Dialog::SetLine(int x1,int y1,int x2, int y2)
{
    scene->addLine(x1,y1,x2,y2);
}

int Dialog::GetDatX(Node* n, int x)
{
    int res;
    if (x<n->xmid)
        res=n->xmid-1;
    if (x>n->xmid)
        res=n->xmid+1;
    qDebug()<<"GetDatX"<<res;
        return res;
}
int Dialog::GetDatY(Node* n, int y)
{
    int res;
    if (y<n->ymid)
        res=n->ymid-1;
    if (y>n->ymid)
        res=n->ymid+1;
    qDebug()<<"GetDatY"<<res;
        return res;
}

Node* Dialog::CreateRoot(Node* root) //создание рута
{
    qDebug()<<"CreateRoot Start";
    Data* dat0;
    dat0=(Data*)malloc(sizeof(Data));
    dat0->x=256;
    dat0->y=256;
    dat0->string="123";
    Info* inf0;
    inf0=(Info*)malloc(sizeof(Info));
    inf0->x=256;
    inf0->y=256;
    inf0->string="123";
    add(&root,inf0,dat0);
    return root;
    qDebug()<<"root v CreateRoot"<<root;
    qDebug()<<"CreateRoot Fin";
}

Node* Dialog::Choice(Node* n, int x, int y) //переход к 1 из 4 ветвей(потомков)
{
    if (x<n->xmid && y<n->ymid)
        return n->branch[0];
    if (x<n->xmid && y>n->ymid)
        return n->branch[1];
    if (x>n->xmid && y<n->ymid)
        return n->branch[2];
    if (x>n->xmid && y>n->ymid)
        return n->branch[3];
}

void Dialog::SetPoint(Node* p,int x, int y, int size)
{
    Data* dat1;
    dat1=(Data*)malloc(sizeof(Data));
    Info* inf1;
    inf1=(Info*)malloc(sizeof(Info));
    while ((p->xmax-p->xmin)>size)
    {
        if (p->branch[0]&&p->branch[1]&&p->branch[2]&&p->branch[3])
        {
            p=Choice(p,x,y);
        }
        else
        {
            dat1->string="123";
            dat1->x=GetDatX(p,x);
            dat1->y=GetDatY(p,y);

            inf1->string="123";
            inf1->x=GetDatX(p,x);
            inf1->y=GetDatY(p,y);

            while (p->xmax!=512) //возврат к  руту
            {
             p=p->parent;
            }
            add(&p,inf1,dat1);

            while (p->info[0]->x != inf1->x)
            {
                p=Choice(p,inf1->x,inf1->y);
            }

            dat1->x=p->xmid;
            dat1->y=p->ymid;
            inf1->x=p->xmid;
            inf1->y=p->xmid;

            while (p->xmax!=512) //возврат к руту
            {
             p=p->parent;
            }
            add(&p,inf1,dat1);


        }
    }
    dat1->x=x;
    dat1->y=y;
    inf1->x=x;
    inf1->y=y;

    while (p->xmax!=512) //возврат к руту
    {
     p=p->parent;
    }
    add(&p,inf1,dat1);

    Print(p,0);



    /*
    qDebug()<<"SetPoint Start";
    p=CreateRoot(p);
    Node* node=NULL;
    node=p;
    Data* dat1;
    dat1=(Data*)malloc(sizeof(Data));
    dat1->string="123";
    Info* inf1;
    inf1=(Info*)malloc(sizeof(Info));
    inf1->string="123";
    qDebug()<<"p v SetPoint"<<p;
    while ((node->xmax-node->xmin) > size)
    {
        qDebug()<<"p->xmax"<<node->xmax;
        qDebug()<<"p->xmin"<<node->xmin;
    dat1->x=GetDatX(node,x);
    dat1->y=GetDatY(node,y);
    inf1->x=GetDatX(node,x);
    inf1->y=GetDatY(node,y);
    add(&p,inf1,dat1);
    node=Choice(node,inf1->x,inf1->y);
    Print(p,0);
    }*/


}

void Dialog::Print(Node *t, int l)
{

    int i=l;
    if(t) {
        while(--i>= 0)
           // printf("                     ");
         //  ui->textEdit->setText("             ");
        qDebug()<<"         % \r";

        for(i=0;i<t->count;++i)
            if(t->info[i]){
               qDebug()<<"x y"<<t->info[i]->x<<t->info[i]->y;
               qDebug()<<"xmid ymid"<<t->xmid<<t->ymid;

               QPen pen(Qt::black);
               QBrush br(Qt::black);








              if (t->branch[0]&&t->branch[1]&&t->branch[2]&&t->branch[3]){

                  //qDebug()<<"xxx yyy"<<t->info[i]->x<<t->info[i]->y;
                  //qDebug()<<"xmid ymid"<<t->xmid<<t->ymid;

                /*  if (ui->checkBox->isChecked()){
                  if (t->info[i]->x < t->xmid && t->info[i]->y < t->ymid){
                      scene->addRect(t->xmin,t->ymin,t->xmid - t->xmin,t->ymid - t->ymin,pen,br);

                  }

                  if (t->info[i]->x < t->xmid && t->info[i]->y > t->ymid){
                      scene->addRect(t->xmin,t->ymid,t->xmid - t->xmin,t->ymax - t->ymid,pen,br);

                  }
                  if (t->info[i]->x > t->xmid && t->info[i]->y < t->ymid){
                      scene->addRect(t->xmid,t->ymin,t->xmax - t->xmid,t->ymid - t->ymin,pen,br);

                  }
                  if (t->info[i]->x > t->xmid && t->info[i]->y > t->ymid){
                      scene->addRect(t->xmid,t->ymid,t->xmax - t->xmid,t->ymax - t->ymid,pen,br);

                  }
                  }
                  */

               scene->addLine(t->xmid,t->ymin,t->xmid,t->ymax);
               scene->addLine(t->xmin,t->ymid,t->xmax,t->ymid);
               //scene->addEllipse(100,100,5,5,pen,br);

               /*  QBrush br(Qt::blue);
                  QPen pen(Qt::blue);
                 // br.setColor(Qt::blue);
                  scene->addRect(0,0,50,50,pen,br);
                  */

               qDebug()<<t->branch[0]->xmid<<t->branch[0]->ymid;
               qDebug()<<t->branch[1]->xmid<<t->branch[1]->ymid;
               qDebug()<<t->branch[2]->xmid<<t->branch[2]->ymid;
               qDebug()<<t->branch[3]->xmid<<t->branch[3]->ymid;

               }
            }




        if (t->count==0)
           printf("------------");
            qDebug()<<"-----------";
        //printf("\n\n\n");
        qDebug()<<"\n\n\n";



        Print(t->branch[0],l+1);
        Print(t->branch[1],l+1);
        Print(t->branch[2],l+1);
        Print(t->branch[3],l+1);


    }
}

void Dialog::on_Dialog_accepted()
{
   // i=(ui->lineEdit_3->text()).toInt();
}

void Dialog::on_lineEdit_3_editingFinished()
{
    number=((ui->lineEdit_3->text()).toInt());

/*
    QGraphicsView *pGraphArea = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene;
    pGraphArea->setScene(scene);
    scene->setSceneRect(0,0,600,600);

    scene->addLine(0,300,600,300);
    scene->addLine(300,0,300,600);*/


}

void Dialog::on_pushButton_2_clicked()
{
  //  Dialog1 *D = new Dialog1;
    //D->show();

   // Print(r,0);
}

void Dialog::on_pushButton_3_clicked()
{
    qDebug()<<"Clicked";
    qDebug()<<"r v pushButtonClicked"<<r;
    SetPoint(r,100,100,8);
}
