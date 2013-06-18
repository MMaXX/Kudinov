#include <cmath>
//#include <math.h>
#include <QDebug>
#include <QFile>
#include <QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tree.h"
#include <stdio.h>

#define PI 3.14159265359

#define MY_IP "192.168.208.184"
#define MY_PORT 6667

void toFile(char c){
    QFile file("c://test12.txt");
    file.open(QIODevice:: Append | QIODevice::Text); //запись в конец файла
    QTextStream out(&file);
    out << c;
    out << "\n";
}

void Server:: initSocket(){
    qDebug()<<"initSocket";
    toFile('5');


    udpSocket = new QUdpSocket(this);
    qDebug()<<"initSocket1";
    toFile('6');


    udpSocket->bind(QHostAddress(MY_IP), MY_PORT);
    qDebug()<<"initSocket2";
    toFile('7');

   // connect(udpSocket, SIGNAL(readyRead()),this, SLOT(readPendingDatagrams()));
    qDebug()<<"initSocket3";
    toFile('8');

    //QString temp1;
    int i=0;
    FILE* ff =  fopen("c://test123.txt","rt");
    //file.open(QIODevice::ReadOnly | QIODevice::Text);
    for(int i=0;i<360;i++){
        fscanf(ff,"%d",&arr[i]);
        arr[i]/=5;
        qDebug()<<arr[i];}
    fclose(ff);
}

void Server::readPendingDatagrams()
{
    qDebug()<<"before read 1211";
    toFile('9');

    while (udpSocket->hasPendingDatagrams())  {
        qDebug()<<"before read";
        toFile('q');

       //char datagram;
       //datagram.resize(udpSocket->pendingDatagramSize());
       QHostAddress sender;
       quint16 senderPort;
       qDebug()<<"before read";
       toFile('b');

       udpSocket->readDatagram((char*)arr, 361*sizeof(short),&sender, &senderPort);
       toFile('a');




       qDebug()<<"after read";
       /*for (int i = 0; i < datagram.size()/2; i++){
           arr[i]=short(datagram[2*i])<<8 + datagram[2*i+1];
       }*/
      // processTheDatagram(datagram);
   }
}

void ReceiverObject::doWork(){

    qDebug()<<"doWork1";
    toFile('w');


    Server* s1 = new Server;
    ranges=s1->arr;
    s1->initSocket();
    while(1){}
    /*int sockfd,n,len;
    struct sockaddr_in servaddr,cliaddr;
    // create socket object
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==INVALID_SOCKET){
        qDebug()<<"Socket isn't valid";
        return;}
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(MY_IP);
    servaddr.sin_port=htons(MY_PORT);
    int r1 = bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(r1 == SOCKET_ERROR){
        qDebug()<<"Bind error";
        return;}
    while(1){
        n = recvfrom(sockfd,(char*)ranges,361*sizeof(short),0,(struct sockaddr *)&cliaddr,&len);}
*/
}

MainWindow::MainWindow(QWidget *parent, Node* _r) :
    QMainWindow(parent),
    r(_r),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pGraphArea =ui->graphicsView;
    scene = new QGraphicsScene;
    pGraphArea->setScene(scene);
	ui->lineEdit_diff->setText("0");
    scene->setSceneRect(0,0,512,512);
	scene->clear();
    scene->addRect(0,0,512,512,QPen(),QBrush(QColor(127,127,127)));
    rf_data=NULL;
    /* start data receiver thread */
    qDebug()<<"before read 1";
    toFile('1');

    rf_data = new ReceiverObject;
    rf_data->ranges=NULL;
    qDebug()<<"before read 2";
    toFile('2');

    QThread *workerThread = new QThread(this);
    qDebug()<<"before read 3";
    toFile('3');

    connect(workerThread, SIGNAL(started()), rf_data, SLOT(doWork()));
    qDebug()<<"before read 4";
    toFile('4');
   // connect(workerThread, SIGNAL(finished()), this, SLOT(destroyed()));
    rf_data->moveToThread(workerThread);

    // Starts an event loop, and emits workerThread->started()
    workerThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::Massiv(int xstart, int ystart,short mas[], int len){

    int xfin=0,yfin=0;
    int i=0;
    double f=0;
    qDebug()<<"Massiv";

    while(i<len){
        qDebug()<<"massiv1"<< "i"<< i;

        xfin=mas[i]*cos(f * PI/180)+xstart;
        qDebug()<<"massiv2";

        yfin=mas[i]*sin(f * PI/180)+ystart;
        Add_Line(xstart,ystart,xfin,yfin,4);
        i++;
        f=f+0.5;
    }
}

void MainWindow::on_actionCreate_map_triggered()
{
/*    Dialog123 *Dial = new Dialog123;
    Dial->show();
*/}



void MainWindow::on_actionLoad_map_triggered()  // ??????? загрузка карты из файла
{
 //   QString temp1, temp2;
 //   int i;
  //  QFile file("c://test123.txt");
  ////  file.open(QIODevice::ReadOnly | QIODevice::Text);
  //  QTextStream out(&file);
   // while (!out.atEnd() && i<360){
  //  out >> temp1;
   // arr[i]= int(temp1)/3;

  //  file.close();
 //   show();
}


/* data needed to draw one node of a tree */
struct draw_context{
    QGraphicsScene *scene;};

/* function for tree drawing*/
void draw_tree_func(Node *p, void *parameter){
    draw_context *context = (draw_context *) parameter;
    if(p->state >= 0 && p->state <= 1){
        int color = p->state * 255;
        context->scene->addRect(p->xmin,p->ymin,p->xmax - p->xmin,p->ymax - p->ymin,
			QPen(QColor(0,0,0,0)), QBrush(QColor(color,color,color)));}}	
	
/* drawing tree using iterator */
void draw_tree(Node *p, QGraphicsScene *scene){
    /* create context for drawing */
    draw_context cnt;
    cnt.scene=scene;
    iterate_tree(p, &cnt, &draw_tree_func);}


int number;
int file_clear=1;

void MainWindow::on_pushButton_clicked(){

    short m[20];
    m[0]=300;
    m[1]=300;
    m[2]=300;
    m[3]=300;
    m[4]=300;
    m[5]=300;
    m[6]=300;
    m[7]=300;
    m[8]=300;
    m[9]=300;
    m[10]=300;
    m[11]=300;
    m[12]=300;
    m[13]=300;
    m[14]=300;
    m[15]=300;
    m[16]=300;
    m[17]=300;
    m[18]=300;
    m[19]=300;
    //Massiv(8,8,m);
    if(rf_data->ranges)
        Massiv(256,8,rf_data->ranges+1,360);
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

    /* сохранение в файл */
    QFile file_remove("c://test.txt");
    if (file_clear==1) file_remove.remove(); //удаление файла при каждом новом вводе
    file_clear++;
    QFile file("c://test.txt");
    file.open(QIODevice:: Append | QIODevice::Text); //запись в конец файла
    QTextStream out(&file);
    out << ui->lineEdit->text();
    out << " ";
    out << ui->lineEdit_2->text();
    out << "\n";

    file.close();
}

void MainWindow::SetLine(int x1,int y1,int x2, int y2)
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

void MainWindow::SetPoint(int x, int y, int size){
    add(&r,x,y,size,1);

}

#define roundf(x) floor(x+0.5f)

void MainWindow::Add_Line(int x1, int y1, int x2, int y2, int size){
    float xfin,yfin;

          int dx = (x2 - x1 >= 0 ? size : -size);
          int dy = (y2 - y1 >= 0 ? size : -size);

          int lengthX = abs(x2 - x1);
          int lengthY = abs(y2 - y1);

          int length = (lengthX> lengthY)?lengthX:lengthY;
		  
		  int area_size = ui->lineEdit_diff->text().toInt();
		  
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
                if(!area_size)
					add(&r,xfin,yfin,size,0); //последний черный квадрат
				else
                    Add_Surround(xfin,yfin,0.9,0.9,size);

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
                if(!area_size)
					add(&r,xfin,yfin,size,0); //последний черный квадрат
				else
                    Add_Surround(xfin,yfin,0.9,0.9,size);

          }
}


/* gauss distribution from 1 var. function with mean and deviation=diff in point x*/
const double gauss_disp_const = 1 / sqrt(2* 3.1415927);
double gauss_disp(double mean, double diff, double x){
	if (diff<=0)
		return 1;
	else
		return gauss_disp_const / diff * exp(-(x-mean)*(x-mean)/(2*diff*diff));}

/* add normally-distributed probability point 
 * (x,y) --- point position
 * dx,dy --- standard deviations of x and y (TODO: change to non-symmetric distribution)
 * area_size --- from lineEdit_diff
 * step --- now fixed, 1 only (TODO: change to parameter from form) */
void MainWindow::Add_Surround(int x, int y, double dx, double dy, int size){
    int i,j;
	const int step = 1;
	int area_size = ui->lineEdit_diff->text().toInt();
	/* for each point in square (x-area_size,y-area_size)---(x+area_size,y+area_size) --- TODO: create 8 times faster version*/
    for(i=x-area_size;i<=x+area_size;i=i+size)
        for(j=y-area_size;j<=y+area_size;j=j+size)
			/* if the point is in basic rectangle --- TODO: remake with non-fixed limits*/
			if(i>=0 && j>=0 && i<512 && j<512){
              add(&r,i,j,size,1-gauss_disp(x/size,dx,i/size)*gauss_disp(y/size,dy,j/size));
               // add(&r,i,j,size,(1-gauss_disp(x,dx,i))*(1-gauss_disp(y,dy,j)));
                qDebug()<<'('<<i<<','<<j<<") --- "<<(1-gauss_disp(x/size,dx,i/size)*gauss_disp(y/size,dy,j/size));}
               // qDebug()<<'('<<i<<','<<j<<") --- "<<1-gauss_disp(x,dx,i);}
}




/*
    QGraphicsView *pGraphArea = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene;
    pGraphArea->setScene(scene);
    scene->setSceneRect(0,0,600,600);

    scene->addLine(0,300,600,300);
    scene->addLine(300,0,300,600);*/






void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"Clicked";


    qDebug()<<"r v pushButtonClicked"<<r;
 //   SetPoint(100,100,8);

    //Add_Surround(4,256,256,5,4,256,256,5);
  Add_Line(ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt(),ui->lineEdit_6->text().toInt(),ui->lineEdit_5->text().toInt(),4);
    QBrush br_grey(QColor(128,128,128));

    /* draw grey rectangle in full map size*/
    scene->clear();
    scene->addRect(0,0,512,512,QPen(),br_grey);
    draw_tree(r,scene);
}





