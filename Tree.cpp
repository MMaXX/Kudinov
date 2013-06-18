//#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
//#include "StdAfx.h"
#include<time.h>
#include<iostream>
#include"Tree.h"
#include<QDebug>

using namespace std;
int sav,minx,y;
char* st;

/* check if the size is power of 2 (only for ) */
bool check_size(int size){
	/* size should be positive */
	if (size<1)
		return false;
	/*size should have only one '1'*/
	while(size>1){
		if(size & 1)
			return false;
		else
			size>>=1;}
	return true;
	}

/* limits for tree --- temporary */	
const int MinX = 0;
const int MinY = 0;
const int MaxX = 512;
const int MaxY = 512;

/* empty node creator */
Node *create_node(Node *parent, int minX, int maxX, int minY, int maxY){
	Node *f;
	int i;
	/* if size isn't power of 2, return 0 and print debug message */
	if(!check_size(maxX - minX)){
		qDebug() << "Size of square [" << minX << ',' << maxX << ") is wrong: ";
		return NULL;}
	if(!check_size(maxY - minY)){
		qDebug() << "Size of square [" << minY << ',' << maxY << ") is wrong: ";
		return NULL;}
	
	/* create empty node */
	f = new Node;
	f->xmin=minX;
	f->ymin=minY;
	f->xmax=maxX;
	f->ymax=maxY;
	f->parent = parent;
	f->state = NoInfo;
	for(i=0;i<4;++i)
			f->branch[i]=NULL;
	return f;}
	
/* destroy tree stated by *root */
void destroy_tree(Node **root){
	int i;
	/* if tree is empty --- return, else destroy subtrees and *root itself */
	if(*root){
		for(i=0; i<4; ++i)
			destroy_tree(&((*root)->branch[i]));
		delete *root;
		*root = NULL;}}


/* add square to tree; square is [point_x, point_x+size), [point_y, point_y+size). */		
int add(Node **root, int point_x, int point_y, int size, float point_value){
    int i,pos;
    Node *current;
	
	/* if size isn't power of 2, error -1 and debug message */
	if(!check_size(size)){
		qDebug() << "Size of element (" << point_x << ',' << point_y << ") is wrong: " << size;
		return -1;}
	
	/* if point isn't in limits, return -2 (temporary)*/
	if(point_x>MaxX || point_x<MinX || point_y>MaxY || point_y<MinY){
		qDebug() << "Coords of element (" << point_x << ',' << point_y << ") is''t in acceptable limits";
		return -2;}
	
	/* if *root is null, insert first point in the tree (now with fixed size)*/
	if(*root == NULL)
		*root = create_node(NULL, MinX, MaxX, MinY, MaxY);
		
	/* go lower while square size isn't equal to point size */
	current = *root;
	while(current){
		/* if we find nessesary square, replace data in it by point_value
		 * (subtrees will be destroyed!) */
		if(point_x == current->xmin && point_y == current->ymin && 
			point_x + size == current->xmax && point_y + size == current->ymax){
			/* delete subtrees if they exist */
			for(i=0;i<4;++i)
				if(current->branch[i])
					destroy_tree(&(current->branch[i]));
			/* set state to point_value*/
            if (current->state == NoInfo)
                current->state = point_value;
                else
                    current->state=(current->state + point_value)/2;
			return 0;}
		
		/* continue to subtree: if it doesn't exist, create it */
		pos = choose_branch(current, point_x, point_y);
        if(pos>=0 && !current->branch[pos]){
			int new_min_x = current->xmin + (pos >> 1)*(current->xmax - current->xmin)/2;
			int new_min_y = current->ymin + (pos & 1)*(current->ymax - current->ymin)/2;
			current->branch[pos] = create_node(current, new_min_x, new_min_x + (current->xmax - current->xmin)/2,
				new_min_y, new_min_y + (current->ymax - current->ymin)/2);}
		//print_tree(*root,0);
		
		/* go to subtree */
        if(pos>=0)
            current = current->branch[pos];
        else return -2;}
	return 0;}


/* choose subtree by point:
 *    2    Y    3
 *         <
 *vvvvvvvvv<vvvvvvvv X
 *         <
 *    0    <    1
 */
int choose_branch(Node *node, int point_x, int point_y)
{
	int disp_x=0, disp_y=0;
    /* if empty tree --- null*/
	if(!node){
		qDebug()<<"Choosing branch in empty node; point is ("<<point_x<<','<<point_y<<')';
		return -1;}
	/* if point is out of branch --- -2*/
	if(node->xmin>point_x || node->ymin>point_y || node->xmax<=point_x || node->ymax<=point_y){
		qDebug()<<"Point is out of node; point is ("<<point_x<<','<<point_y<<
			"), node is ("<< node->xmin<<','<<node->ymin<<")--"<<(node->xmax - node->xmin)/2;
		return -1;}
	/* else locate position by x and y*/
	if(node->xmin + (node->xmax - node->xmin)/2 <= point_x)
		disp_x=2;
    if(node->ymin + (node->ymax - node->ymin)/2 <= point_y)
		disp_y=1;
    return disp_x+disp_y;}

/* iterator funcion for tree traversing 
 * f --- function to execute for each node
 * parameter --- pointer to f parameter.
 * Usually "parameter" contains extra variables for function to use */
void iterate_tree(Node *p, void *parameter, void (*f)(Node*, void*)){
	if(p){
		f(p,parameter);
		for(int i=0;i<4;i++)         
			iterate_tree(p->branch[i],parameter,f);}}

/* function for text output of 1 node*/
void print_tree_func(Node *p, void*){
	qDebug() << '(' << p->xmin<< ',' << p->ymin << ") - (" << p->xmax << ',' << p->ymax << ')';}

/* print tree p*/
void print_tree(Node *p){
	iterate_tree(p, NULL, &print_tree_func);}
	
	
