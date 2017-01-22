#include "helper.h"
#include "wrapper.h"
#include "compAndDest.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Node * found;
    int data1[15] = {3,11,6,2,9,14,1,7,4,12,8,13,5,15,10};
    int i;
    int * data2 = malloc (sizeof (int) * 15);
    printf ("The original order\n");
    for (i = 0; i < 15; i++){
/*        data2[i] = malloc (sizeof (int));*/
        data2[i] = data1[i];
        printf ("%d\n", data2[i]);
    }
/*    Tree * oneTree = createTree (&compare, &destroy);*/
    Tree * twoTree = createTree (&compareInt, &destroyInt);
    for (i = 0; i < 15; i++){
        addToTree (twoTree, data2 + i);
    }

    printf ("\n");
    printf ("Printing in order\n\n");
    printInOrderInt (twoTree->root);
    removeFromTree (twoTree, data2 + 2);
    printf ("\n");
    printf ("The list after %d is removed\n", data2[2]);
    printf ("\n");
    printf ("Printing in order\n\n");
    printInOrderInt (twoTree->root);
    i = 7;
    found = find (twoTree->root, &i, &compareInt);
    printf ("\n");
    printf ("The found int is %d : Height = %d\n", *(int*)(found->data), found->height);
    destroyTree (twoTree);
/*    for (i = 0; i < 15; i++){
        free (data2[i]);
    }*/
    free (data2);
    return 0;
}
