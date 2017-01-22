#ifndef HELPER_H
#define HELPER_H

#define FALSE 0
#define TRUE 1

typedef int bool;

struct AVLTreeNode {
    void * data;
    int height;
    struct AVLTreeNode * left;
    struct AVLTreeNode * right;
    bool deleted;
};

typedef struct AVLTreeNode Node;

struct AVLTree {
    Node * root;
    int (*compare) (void * data1, void * data2);
    void (*destroy) (void * data);
};

typedef struct AVLTree Tree;

int getMax (int a, int b);

Node * create (void * value);

Node * rotateRightWithLeftChild (Node * oldRoot);
Node * rotateLeftWithRightChild (Node * oldRoot);
Node * doubleRotateWithLeftChild (Node * oldRoot);
Node * doubleRotateWithRightChild (Node * oldRoot);

Node * insert (Node * root, void * value, int (*compare) (void * data1, void * data2));

Node * delete (Node * root, void * value, int (*compare) (void * data1, void * data2));

Node * find (Node * root, void * value, int (*compare) (void * data1, void * data2));

void printInOrderInt (Node * root);

void printInOrder (Node * root);

#endif
