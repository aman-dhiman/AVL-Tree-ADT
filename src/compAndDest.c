#include "compAndDest.h"

int compareInt (void * data1, void * data2){
    int a, b;
    a = *((int*) (data1));
    b = *((int*) (data2));
    if (a > b){
        return 1;
    }
    else if (a < b){
        return (-1);
    }
    return 0;
}

void destroyInt (void * node){
    Node * temp = (Node*) node;
    if (temp != NULL){
        destroyInt (temp->left);
        destroyInt (temp->right);
        free (temp);
    }
}

int compareFile (void * data1, void * data2){
    char * a,* b;
    a = (char*)(data1);
    b = (char*)(data2);
    if (strcmp (a, b) > 0){
        return 1;
    }
    else if (strcmp (a, b) < 0){
        return (-1);
    }
    return 0;
}

void destroyFile (void * node){
    Node * temp = (Node*) node;
    if (temp != NULL){
        destroyFile (temp->left);
        destroyFile (temp->right);
        free (temp);
    }
}
