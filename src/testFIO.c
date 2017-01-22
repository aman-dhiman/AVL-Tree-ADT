#include "fileIO.h"
#include "helper.h"
#include "wrapper.h"
#include "compAndDest.h"

int main (){
    char dir[100] = "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest";
    Tree * theTree = createTree (&compareFile, &destroyFile);
    listDir (dir, 0, theTree);
/*    strcpy (dir, "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/more");
    deleteDir (dir);
    strcpy (dir, "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest");
    listDir (dir);
    renameOrMove (0, "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/another",
                     "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/more");
    renameOrMove (1, "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/a",
                     "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/more/a");
    listDir (dir);*/
    char * path = "/home/undergrad/2/dhimana/cis2520/assign/3/dirTest/fly/e";
    removeFromTree (theTree, path);
    printInOrder (theTree->root);
    Node * temp = find (theTree->root, path, &compareFile);
    if (temp != NULL){
    printf ("%s\n", (char*)(temp->data));}
    destroyTree (theTree);
    return 0;
}
