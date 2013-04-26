#ifndef TREE_H
#define TREE_H
const int data_size=1;
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

#endif // TREE_H
