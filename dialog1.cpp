#include "dialog1.h"
#include "ui_dialog1.h"
//#include "Tree.cpp"
//#include "dialog.cpp"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

/*
void Dialog1::Print(Node* t, int l)
{
    int i=l;
    if(t) {
        while(--i>= 0)
           // printf("                     ");
            ui->textEdit->setText("                  ");

        for(i=0;i<t->count;++i)
            if(t->info[i]){
              //  printf("(%d, %d)  ", t->info[i]->x,t->info[i]->y);
              //  printf("(%d)  ", t);
                ui->textEdit->setText("(%d, %d)  ", t->info[i]->x,t->info[i]->y);
                ui->textEdit->setText("(%d)  ", t);

            }




        if (t->count==0)
           // printf("------------");
        //printf("\n\n\n");
            ui->textEdit->setText("------------");
        ui->textEdit->setText("\n\n\n");






        Print(t->branch[0],l+1);
        Print(t->branch[1],l+1);
        Print(t->branch[2],l+1);
        Print(t->branch[3],l+1);


    }
}
*/
void Dialog1::on_pushButton_clicked()
{
    ui->textEdit->setText("123 \n 234");
   // Print(r,0);

}
