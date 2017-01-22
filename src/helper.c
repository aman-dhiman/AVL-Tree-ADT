#include "helper.h"
#include "compAndDest.h"
#include <stdio.h>
#include <stdlib.h>

int getMax (int a, int b){
    if (a > b){
        return a;
    }
    else {
        return b;
    }
}

Node * create (void * value){
    Node * newNode = malloc (sizeof (Node));
    if (newNode == NULL) {
        printf ("Enough memory not available.\n");
        exit(0);
    }
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->deleted = FALSE;
    return (newNode);
}

Node * rotateRightWithLeftChild (Node * oldRoot){
    Node * temp = oldRoot->left;
    oldRoot->left = temp->right;
    temp->right = oldRoot;
    if ((temp->left != NULL)&&(temp->right != NULL)){
        temp->height = getMax (temp->left->height, temp->right->height) + 1;
    }
    else if ((temp->left == NULL)&&(temp->right != NULL)) {
        temp->height = temp->right->height + 1;
    }
    else if ((temp->right == NULL)&&(temp->left != NULL)) {
        temp->height = temp->left->height + 1;
    }
    if ((oldRoot->left != NULL)&&(oldRoot->right != NULL)){
        oldRoot->height = getMax (oldRoot->left->height, oldRoot->right->height) + 1;
    }
    else if ((oldRoot->left == NULL)&&(oldRoot->right != NULL)) {
        oldRoot->height = oldRoot->right->height + 1;
    }
    else if ((oldRoot->right == NULL)&&(oldRoot->left != NULL)) {
        oldRoot->height = oldRoot->left->height + 1;
    }
    return (temp);
}

Node * rotateLeftWithRightChild (Node * oldRoot){
    Node * temp = oldRoot->right;
    oldRoot->right = temp->left;
    temp->left = oldRoot;
    if ((temp->left != NULL)&&(temp->right != NULL)){
        temp->height = getMax (temp->left->height, temp->right->height) + 1;
    }
    else if ((temp->left == NULL)&&(temp->right != NULL)) {
        temp->height = temp->right->height + 1;
    }
    else if ((temp->right == NULL)&&(temp->left != NULL)) {
        temp->height = temp->left->height + 1;
    }
    if ((oldRoot->left != NULL)&&(oldRoot->right != NULL)){
        oldRoot->height = getMax (oldRoot->left->height, oldRoot->right->height) + 1;
    }
    else if ((oldRoot->left == NULL)&&(oldRoot->right != NULL)) {
        oldRoot->height = oldRoot->right->height + 1;
    }
    else if ((oldRoot->right == NULL)&&(oldRoot->left != NULL)) {
        oldRoot->height = oldRoot->left->height + 1;
    }
    return (temp);
}

Node * doubleRotateWithLeftChild (Node * oldRoot){
    oldRoot->left = rotateLeftWithRightChild (oldRoot->left);
    oldRoot = rotateRightWithLeftChild (oldRoot);
    return (oldRoot);
}

Node * doubleRotateWithRightChild (Node * oldRoot){
    oldRoot->right = rotateRightWithLeftChild (oldRoot->right);
    oldRoot = rotateLeftWithRightChild (oldRoot);
    return (oldRoot);
}

Node * insert (Node * root, void * value, int (*compare) (void * data1, void * data2)){
    if (root == NULL){
        Node * newNode = create (value);
        return (newNode);
    }
    else if (compare (value, root->data) < 0){
        root->left = insert (root->left, value, compare);
        if (((root->right != NULL)&&((root->left->height - root->right->height) > 1))||
            ((root->right == NULL)&&(root->left->height > 1))){
            if (compare (value, root->left->data) < 0){
                root = rotateRightWithLeftChild (root);
            }
            else {
                root = doubleRotateWithLeftChild (root);
            }
        }
    }
    else if (compare (value, root->data) > 0){
        root->right = insert (root->right, value, compare);
        if (((root->left != NULL)&&((root->right->height - root->left->height) > 1))||
            ((root->left == NULL)&&(root->right->height > 1))){
            if (compare (value, root->right->data) > 0){
                root = rotateLeftWithRightChild (root);
            }
            else {
                root = doubleRotateWithRightChild (root);
            }
        }
    }
    if ((root->left != NULL)&&(root->right != NULL)){
        root->height = getMax (root->left->height, root->right->height) + 1;
    }
    else if ((root->left == NULL)&&(root->right != NULL)) {
        root->height = root->right->height + 1;
    }
    else if ((root->right == NULL)&&(root->left != NULL)) {
        root->height = root->left->height + 1;
    }
    return (root);
}

Node * delete (Node * root, void * value, int (*compare) (void * data1, void * data2)){
    if (root == NULL){
        return (NULL);
    }
    else if (compare (value, root->data) < 0){
        root->left = delete (root->left, value, compare);
    }
    else if (compare (value, root->data) > 0){
        root->right = delete (root->right, value, compare);
    }
    else if (compare (value, root->data) == 0){
        root->deleted = TRUE;
    }
    return (root);
}

Node * find (Node * root, void * value, int (*compare) (void * data1, void * data2)){
    Node * found;
    found = NULL;
    if (root == NULL){
        return NULL;
    }
    else if (compare (value, root->data) < 0){
        found = find (root->left, value, compare);
    }
    else if (compare (value, root->data) > 0){
        found = find (root->right, value, compare);
    }
    else if ((compare (value, root->data) == 0)&&(root->deleted == FALSE)){
        found = root;
        return found;
    }
    return found;
}

void printInOrderInt (Node * root){
    if (root == NULL){
        return;
    }
    printInOrderInt (root->left);
    if (root->deleted == FALSE){
        printf ("%d\n", *(int*)(root->data));
    }
    printInOrderInt (root->right);
}

void printInOrder (Node * root){
    if (root == NULL){
        return;
    }
    printInOrder (root->left);
    if (root->deleted == FALSE) {
        printf ("%s\n", (char*)(root->data));
    }
    printInOrder (root->right);
}
