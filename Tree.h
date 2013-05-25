#ifndef TREE_H
#define TREE_H

const int NoInfo=-1;

struct Node{
    /* borders of square (all points should be in [min, max) interval) */
	int xmax;
    int xmin;
    int ymax;
    int ymin;
    /* state of square [0..1] --- for list; -1 for inner node */
	float state;
    struct Node *branch[4],*parent;
};

/* insert data in tree */
int add(Node **root, int point_x, int point_y, int size, float point_value);
int choose_branch(Node *node, int point_x, int point_y);
void print_tree(Node*);
void iterate_tree(Node *p, void *parameter, void (*f)(Node*, void*));

#endif // TREE_H
