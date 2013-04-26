#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include "StdAfx.h"
#include<time.h>
#include<iostream>
#include"Tree.h"


using namespace std;
int sav,minx,y;
char* st;
/*
struct Node //описание узла
{
    int key;
    Node *right,*left;
};

typedef Node *KNode;
const int n=23;//количество элементов в сгенерированной последовательности

KNode maketree(int mass[],int from,int n)//функция создания дерева
{
    KNode tree;
    if(n==0) return NULL;
    int nr,nl;
    tree=new Node;
    tree->key=mass[from];
    from++;
    nl=n/2;
    nr=n-nl-1;
    tree->left=maketree(mass,from,nl);
    tree->right=maketree(mass,from,nr);
    return tree;
}

void print_tree(Node *p,int level){
        if(p){
                print_tree(p->left,level+1);           //Перемещение по левым поддеревьям
                for(int i=0;i<level;i++)cout<<"   ";

                cout<<p->key<<"\n";                      //вывод значений дерева
              print_tree(p->right,level+1);          //Перемещение по правым поддеревьям
     }
}

void PrintTree (KNode tree, int r)//функция вывода дерева где r-уровень
{
    if(tree->right!=NULL)
        PrintTree(tree->right,++r);
    for (int i=0;i<(4*r);i++)
        printf("  ");
    printf("%d\n",tree->key);
    if(tree->left!=NULL)
    PrintTree(tree->left,++r);
    --r;
}

int _tmain(int argc, _TCHAR* argv[])
{
    srand(time(NULL));
    int mass[n];
    for(int i=0;i<n;i++)
        mass[i]=0;
    for(int i=0;i<n;i++)
        mass[i]=((rand()%9)+1)*1000+rand()%100;
    /*for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(mass[i]=mass[j])
            {
                mass[j]=((rand()%9)+1)*1000+rand()%100;
                j=i+1;
            }*/
/*
    printf("Initial sequence\n");
    for(int i=0;i<n;i++)
        printf("%d ",mass[i]);
    printf("\n");
    KNode Tree;
    Tree=maketree(mass,0,n);
    //PrintTree(Tree,0);
    print_tree(Tree,0);
    int a;
    scanf("%d",&a);
    return 0;
}
*/
/*---------------------------------------
struct Info{
    int x;
    int y;
    char *string;
};
struct Data{
    int x;
    int y;
    char *string;
    Data* next;
};

int sav,minx,y;
char* st;


struct Node{
    //int inf, x, y;
    int xmax;
    int xmin;
    int ymax;
    int ymin;
    float ymid,xmid;
    int count;
    int depth[4];
    Info *info[data_size];
    struct Node *branch[4],*parent;
};

char* string_input();
void add_input(Info*);
int add(Node**,Info*,Data*);
void depth(Node*);
Node *search(Node*,Info*);
Node* choice_branch(Node*,Info*);
void sort(Node*);
int func_choice(Node**,int);
void printTree(Node, int);
//Node* search_bound(Node*, Node*);
Node *search1(Node*,Info*);
*/





//Node* first();
//void add(Node*,int);
//void print_tree(Node*,int);

/*void Adding(){
   // int a;
    //a=Dialog::ui->lineEdit_3->text().toInt();
    Node* root, *deepest, *s, *f;
    root=NULL;
    int i;
    setlocale(LC_ALL, "Russian");
    int choice=1,result;


    //	choice=getchoice();//выбор действия
    while (a!=0) {
        result=func_choice(&root, choice);//вызов выбранной функции.
        a--;
    }
}
*/
/*
int main()
{

    int a=0;
   // a=(Dialog::ui->lineEdit_3->text()).toInt();
    Node* root, *deepest, *s, *f;
    root=NULL;
    int i;
    setlocale(LC_ALL, "Russian");
    int choice=1,result;


    //	choice=getchoice();//выбор действия
    while (a!=0) {
        result=func_choice(&root, choice);//вызов выбранной функции.
        a--;
    }
    Info* in=0;
    Info* in2=0;
    in=(Info*)malloc(sizeof(Info));
    in->x=100;
    in->y=350;
    in2=(Info*)malloc(sizeof(Info));
    in2->x=400;
    in2->y=400;
    //printf("(%d)", root);
    s=search(root,in);
    f=search(root,in2);
//	deepest=search_bound(s,f);



    //cout<< "Поиск элемента с координатами 400, 400"<< endl;
    //deepest=search1(root,in2);
    //cout<<"Указатель на квадрат:"<<endl;
    //printf("(%d)  ", deepest);
//	s=searchb(deepest,root);
    //printf("(%d)", s);
//	while (deepest!=root){
//		deepest= deepest->parent;
//	}
    //printf("(%d)  ", deepest);
    //f=search1(deepest,in2);
    //s=searchb(deepest, root, in);
    //printf("(%d)  ", f);

    //	if (result!=-1)
        //	func1[choice](result);
        //else("\nПри выполнении действия с таблицей произошла ошибка.\n");


    //while(choice!=0);

    //getch();
    //return 0;




    //Node* root=first();
    //cout << root->xmax << endl;
    //cout << root->xmid << endl;
    //cout << root->ymid << endl;
    */
    /*Node* root=first();
    cout << root->inf <<endl;
    cout << root->xmax <<endl;
    cout << root->xmin <<endl;
    cout << root->ymax <<endl;
    cout << root->ymin <<endl;
    add(root,0);
    cout << root->inf <<endl;
    cout << root->xmax <<endl;
    cout << root->xmin <<endl;
    cout << root->ymax <<endl;
    cout << root->ymin <<endl;
    print_tree(root,0);*/

    //cout << (root) << endl;



//cout << "конец" << endl;
//cin >> a;
//return 0;
//}



void printTree(Node *t, int l)
 {
    int i=l;
    if(t) {
        while(--i>= 0)
            printf("                     ");

        for(i=0;i<t->count;++i)
            if(t->info[i]){
                printf("(%d, %d)  ", t->info[i]->x,t->info[i]->y);
                printf("(%d)  ", t);
            }




        if (t->count==0)
            printf("------------");
        printf("\n\n\n");




        printTree(t->branch[0],l+1);
        printTree(t->branch[1],l+1);
        printTree(t->branch[2],l+1);
        printTree(t->branch[3],l+1);


    }
}


int func_choice(Node** root,int result)
{


    int i=0;

    //if (result==0)
    //	result=end(root);
     if (result==1){
       // result=add(root);
        //printTree(*root,0);
     }
    ///////////////// printTree(*root,0);


//	 else if (result==4)
//	{
//		printTree(*root,0);
//		result=0;
//	}
    //else if (result==2)
    //	result=searching(*root);
//	else if (result==3)
    //	result=Delete(root);
    //else if (result==4)
//	{
        //printTree(*root,0);
//		result=0;
//	}
//	else if (result==5)
        //result=random_output(*root);
//	else if (result==6)
//	{
        //direct_out(*root);
    //	result=0;
//	}
    //else if (result==7)
    //	result=table_load(root);
//	else
//	return -1;


    return result;
}


char* string_input()
    {
        char *string, *buffer, chr=0;
    int result,length=0;
        string=(char*)malloc(1);
        string[0]='\0';

        buffer=(char*)malloc(11);

    fflush(stdin);


do

   {
        result=scanf("%10[^\n]%c", buffer,&chr);

        switch(result)
        {

        case-1:
            scanf("%*c");
            break;
        case 0:
            scanf("%*c");
            break;
        case 2:
            if (chr=='\n')
            result=0;
            else
                ungetc(chr,stdin);

            length+=strlen(buffer);
            string=(char*)realloc(string,length+1);
            strcat(string,buffer);
        }

}while(result>0);
free(buffer);

        return string;
    }


void add_input(Info* data)
 {
    char* string;
    int key1,key2,in1,in2;
    printf("\n введите строку\n");
    string=string_input();

    do
    {
    printf("\n введите координату х:  ");
    in1=scanf("%d",&key1);
    if(in1!=1)
        printf("\n ошибочные данные\n");
    fflush(stdin);
    }while(in1!=1);

    do
    {
    printf("\n введите координату у:  ");
    in2=scanf("%d",&key2);
    if(in2!=1)
        printf("\n ошибочные данные\n");
    fflush(stdin);
    }while(in2!=1);

    data->x=key1;
    data->y=key2;
    data->string=string;
}



int add(Node** root,Info* in, Data* dat)
{
    int i,j;
    Info *info=new Info;
   // info=(Info*)malloc(sizeof(Info));
    info=in;
    Data *data=new Data;
    //data=(Data*)malloc(sizeof(Data));
    data=dat;

    Node *current=*root,*f;

   // add_input(info);


    if((f=search(current,info))==NULL)
    {
        if(current==NULL)
        {
            current=(Node*)malloc(sizeof(Node));
            current->xmax=512;
            current->xmin=0;
            current->ymin=0;
            current->ymax=512;
            current->xmid=((float)current->xmax+(float)current->xmin)/2;
            current->ymid=((float)current->ymax+(float)current->ymin)/2;
            current->count=0;


            current->parent=NULL;
            current->branch[0]=NULL;
            current->branch[1]=NULL;
            current->branch[2]=NULL;
            current->branch[3]=NULL;
            current->depth[0]=0;
            current->depth[1]=0;
            current->depth[2]=0;
            current->depth[3]=0;

            for (i=0;i<data_size;++i)
            {
                current->info[i]=NULL;

            }

            *root=current;
        }


        if(((info->x)>(current->xmax) || (info->x)<(current->xmin)) && ((info->y)>(current->ymax) || (info->y)<(current->ymin)))
            {
                cout<< "х и у не попадают"<< endl;
                free(info);
                return 2 ;//оба ключа не попадают
            }

        else if(((info->x)>(current->xmax))||((info->x)<(current->xmin)))
            {
                cout<< "х не попадает"<< endl;
                free(info);
                return 3;//х не попадает
            }
        else if(((info->y)>(current->ymax)) || ((info->y)<(current->ymin)))
            {
                cout<< "у не попадает"<< endl;
                free(info);
                return 4;//у не попадает
            }


    if(current!=NULL) while(current->count>=data_size)
    {
        if ((!current->branch[0])&&(!current->branch[1])&&(!current->branch[2])&&(!current->branch[3]))
            {
                current->branch[0]=(Node*)malloc(sizeof(Node));
                current->branch[0]->ymax=current->ymid;
                current->branch[0]->ymin=current->ymin;
                current->branch[0]->xmax=current->xmid;
                current->branch[0]->xmin=current->xmin;
                current->branch[0]->count=0;
                current->branch[0]->parent=current;
                current->branch[0]->xmid=((float)current->branch[0]->xmax+(float)current->branch[0]->xmin)/2;
                current->branch[0]->ymid=((float)current->branch[0]->ymax+(float)current->branch[0]->ymin)/2;///!!!

                current->branch[1]=(Node*)malloc(sizeof(Node));
                current->branch[1]->ymax=current->ymax;
                current->branch[1]->ymin=(int)current->ymid;
                current->branch[1]->xmax=current->branch[0]->xmax;
                current->branch[1]->xmin=current->branch[0]->xmin;
                current->branch[1]->count=0;
                current->branch[1]->parent=current;
                current->branch[1]->xmid=((float)current->branch[1]->xmax+(float)current->branch[1]->xmin)/2;
                current->branch[1]->ymid=((float)current->branch[1]->ymax+(float)current->branch[1]->ymin)/2;///!!!


                current->branch[2]=(Node*)malloc(sizeof(Node));
                current->branch[2]->ymax=(int)current->ymid;
                current->branch[2]->ymin=current->ymin;
                current->branch[2]->xmax=current->xmax;
                current->branch[2]->xmin=current->branch[0]->xmax;
                current->branch[2]->count=0;
                current->branch[2]->parent=current;
                current->branch[2]->xmid=((float)current->branch[2]->xmax+(float)current->branch[2]->xmin)/2;
                current->branch[2]->ymid=((float)current->branch[2]->ymax+(float)current->branch[2]->ymin)/2;///!!!


                current->branch[3]=(Node*)malloc(sizeof(Node));
                current->branch[3]->ymax=current->ymax;
                current->branch[3]->ymin=(int)current->ymid;
                current->branch[3]->xmax=current->xmax;
                current->branch[3]->xmin=current->branch[0]->xmax;
                current->branch[3]->count=0;
                current->branch[3]->parent=current;
                current->branch[3]->xmid=((float)current->branch[3]->xmax+(float)current->branch[3]->xmin)/2;
                current->branch[3]->ymid=((float)current->branch[3]->ymax+(float)current->branch[3]->ymin)/2;///!!!

                for (i=0;i<data_size;++i)
                {
                    current->branch[0]->info[i]=NULL;
                    current->branch[1]->info[i]=NULL;
                    current->branch[2]->info[i]=NULL;
                    current->branch[3]->info[i]=NULL;
                }

                for(j=0;j<4;++j)
                {
                    for(i=0;i<4;++i)
                        current->branch[j]->depth[i]=0;

                    current->branch[0]->branch[j]=NULL;
                    current->branch[1]->branch[j]=NULL;
                    current->branch[2]->branch[j]=NULL;
                    current->branch[3]->branch[j]=NULL;
                }


        }
            current=choice_branch(current,info);
        }


        if(current->count<data_size)
        {
            if(current->count==0)
                depth(current);

            current->info[current->count]=(Info*)malloc(sizeof(Info));
            current->info[current->count]=info;
            ++current->count;
            sort(current);




            return 0;//все ок, добавлено
        }
    }
    else
    {
        cout<< "такой элемент уже есть"<< endl;
        free(info);
        return 1;//такой элемент уже есть
    }

}


void sort(Node* current)
{
    char *saverch;
    int saverx,savery;
    int i,j;

    for(j=0;j<2;++j)
    {
        for(i=0;i<data_size-1;++i)
            if(current->info[i]!=NULL&&current->info[i+1]!=NULL)
                if(current->info[i]->x>current->info[i+1]->x)
                {
                    saverx=current->info[i]->x;
                    savery=current->info[i]->y;
                    saverch=current->info[i]->string;
                    current->info[i]->x=current->info[i+1]->x;
                    current->info[i]->y=current->info[i+1]->y;
                    current->info[i]->string=current->info[i+1]->string;
                    current->info[i+1]->x=saverx;
                    current->info[i+1]->y=savery;
                    current->info[i+1]->string=saverch;

            }
    }


}


void depth(Node* current)
{
    int i=0;

    Node* parent;

    current->depth[0]=0;
    current->depth[1]=0;
    current->depth[2]=0;
    current->depth[3]=0;

    parent=current->parent;

    while(parent!=NULL)
    {
        while(parent->branch[i]!=current)
            ++i;

        ++parent->depth[i];
        current=current->parent;
        parent=parent->parent;
        i=0;
    }

}

/*
Node* path( Node* root, Info* sinf, Node* fnod, Info* finf)
    {
        Node* cur,snod,nodb;
        snod=search(root, sinf);

        nodb=search(root, inf);
}
*/

    /*Node* search_bound(Node* node1, Node* node2)
{
    float i=0;
    while(node2!=NULL)
    {
        if ((((node1->xmin==node2->xmax)&&((node1->ymax==node2->ymax)||(node1->ymin==node2->ymin)))
            ||((node1->xmax==node2->xmin)&&((node1->ymax==node2->ymax)||(node1->ymin==node2->ymin))))
            ||(((node1->ymin==node2->ymax)&&((node1->xmax==node2->xmax)||(node1->xmin==node2->xmin)))
            ||((node1->ymax==node2->ymin)&&((node1->xmax==node2->xmax)||(node1->xmin==node2->xmin)))))
        {
            i= sqrt(((((int)node1->xmid)-((int)node2->xmid))^2) + ((((int)node1->ymid)-((int)node2->ymid))^2));
            cout<< "Расстояние до соседа"<< endl;
            cout<< i << endl;


            printf("(%d)  ", node2);

        }
    //	node=choice_branch(node2);

    }

    return node2;
}
*/
Node *search1(Node* node,Info* info)
{
    int i;

    while(node!=NULL)
    {

        for(i=0;i<node->count;i++)
        {
            if((node->info[i]!=NULL)&&(node->info[i]->x==info->x)&&(node->info[i]->y==info->y))
                return node;
        }
        node=choice_branch(node,info);

    }
    if (node==0)
        cout<< "Такого элемента не существует"<< endl;
    return node;

}


Node *search(Node* node,Info* info)
{
    int i;

    while(node!=NULL)
    {
        for(i=0;i<node->count;i++)
        {
            if((node->info[i]!=NULL)&&(node->info[i]->x==info->x)&&(node->info[i]->y==info->y))
                return node;
        }
        node=choice_branch(node,info);
    }
    //if (node==0)
    //	cout<< "Такого элемента не существует"<< endl;
    return node;

}
Node* choice_branch(Node*node,Info* info)
{
    if((((float)(info->x))<=(node->xmid))&&(((float)(info->y))<=(node->ymid)))
        return node->branch[0];
    if((((float)(info->x))<(node->xmid))&&(((float)(info->y))>(node->ymid)))
        return node->branch[1];
    if((((float)(info->x))>=(node->xmid))&&(((float)(info->y))>=(node->ymid)))
        return node->branch[3];
    if((((float)(info->x))>(node->xmid))&&(((float)(info->y))<(node->ymid)))
        return node->branch[2];

    return NULL;
}



/*
Node *first(){
Node *pv = new Node;
pv=(Node*)malloc(sizeof(Node));
//pv->info[0]->x=d;
//pv->info[0]->y=d+1;
pv->inf =0;
pv->xmax=600;
pv->xmin=0;
pv->ymax=600;
pv->ymin=0;
pv->xmid= ((float)pv->xmin+(float)pv->xmax)/2 + (float)pv->xmin;
pv->ymid= ((float)pv->ymin+(float)pv->ymax)/2 + (float)pv->ymin;
pv->branch[0]=0;
pv->branch[1]=0;
pv->branch[2]=0;
pv->branch[3]=0 ;
return pv;
}

void add(Node* nod, int j) {
    Node* cur=nod;
    cout << "vvedite inf" << endl;
    cin >> cur->inf;
    cout << "vvedite x" << endl;
    cin >> cur->x;
    cout << "vvedite y" << endl;
    cin >> cur->y;
    int i;
    if((((float)(cur->x))<=(nod->xmid))&&(((float)(cur->y))<=(nod->ymid))){
        nod->branch[0]= new Node;
        nod->branch[0]->xmax=nod->xmid;
        nod->branch[0]->xmin=nod->xmin;
        nod->branch[0]->ymax=nod->ymid;
        nod->branch[0]->ymin=nod->ymin;
        i=0;
        //cur=nod->branch[0];
    }
    if((((float)(cur->x))<(nod->xmid))&&(((float)(cur->y))>(nod->ymid))){
        nod->branch[1]= new Node;
        nod->branch[1]->xmax=nod->xmid;
        nod->branch[1]->xmin=nod->xmin;
        nod->branch[1]->ymax=nod->ymax;
        nod->branch[1]->ymin=nod->ymid;
        i=1;
        //cur=nod->branch[1];
    }
    if((((float)(cur->x))>=(nod->xmid))&&(((float)(cur->y))>=(nod->ymid))){
        nod->branch[2]= new Node;
        nod->branch[2]->xmax=nod->xmax;
        nod->branch[2]->xmin=nod->xmid;
        nod->branch[2]->ymax=nod->ymax;
        nod->branch[2]->ymin=nod->ymid;
        i=2;
        //cur=nod->branch[2];
    }
    if((((float)(cur->x))>(nod->xmid))&&(((float)(cur->y))<(nod->ymid))){
        nod->branch[3]= new Node;
        nod->branch[3]->xmax=nod->xmax;
        nod->branch[3]->xmin=nod->xmid;
        nod->branch[3]->ymax=nod->ymid;
        nod->branch[3]->ymin=nod->ymin;
        i=3;
        //cur=nod->branch[3];
    }
    nod->branch[i]->x=cur->x;
    nod->branch[i]->y=cur->y;
    nod->branch[i]->xmid= ((float)nod->branch[i]->xmin+(float)nod->branch[i]->xmax)/2;
    nod->branch[i]->ymid= ((float)nod->branch[i]->ymin+(float)nod->branch[i]->ymax)/2;
    cout << nod->branch[i] << endl;
    cout << nod->branch[i]->x << endl;
    cout << nod->branch[i]->y << endl;
    cout << nod->branch[i]->xmax << endl;
    cout << nod->branch[i]->xmin << endl;
    cout << nod->branch[i]->ymax << endl;
    cout << nod->branch[i]->ymin << endl;
    cout << nod->branch[i]->xmid << endl;
    cout << nod->branch[i]->ymid << endl;
    cout << "-----------"<<endl;
    cout << nod->x << endl;
    cout << nod->y << endl;
    cout << nod->xmax << endl;
    cout << nod->xmin << endl;
    cout << nod->ymax << endl;
    cout << nod->ymin << endl;
    cout << nod->xmid << endl;
    cout << nod->ymid << endl;
    cur=0;
    if (j!=3){
        j++;
    add(nod,j);
    }
    //return nod;
}

void print_tree(Node *p,int k){
        if(p){
                print_tree(p->branch[0],k+1);           //Перемещение по левым поддеревьям
                for(int i=0;i<k;i++)cout<<"   ";

                cout<<p->inf<<"\n";                      //вывод значений дерева
              print_tree(p->branch[1],k+1);          //Перемещение по правым поддеревьям
     }
}

*/

