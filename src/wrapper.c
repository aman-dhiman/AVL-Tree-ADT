#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>

Tree * createTree (int (*compare) (void * data1, void * data2), void (*destroy) 
                  (void * node)){
    Tree * newTree = malloc (sizeof (Tree));
    if (newTree == NULL){
        printf ("Enough memory not available.\n");
        exit(0);
    }
    newTree->root = NULL;
    newTree->compare = compare;
    newTree->destroy = destroy;
    return (newTree);
}

void destroyTree (Tree * theTree){
    theTree->destroy (theTree->root);
    theTree->root = NULL;
    theTree->compare = NULL;
    theTree->destroy = NULL;
    free (theTree);
}

void addToTree (Tree * theTree, void * value){
    theTree->root = insert (theTree->root, value, theTree->compare);
}

void removeFromTree (Tree * theTree, void * value){
    theTree->root = delete (theTree->root, value, theTree->compare);
}
