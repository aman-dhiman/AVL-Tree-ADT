#include "treeFile.h"

void deleteFile (char * file, Tree * theTree){
    int removed = 0;
    deleteDir (file, &removed);
    if (removed == 0){
        removeFromTree (theTree, file);
    }
}

void renameFile (int type, char * oldName, char * newName, Tree * theTree){
    renameOrMove (type, oldName, newName);
    removeFromTree (theTree, oldName);
    addToTree (theTree, newName);
}

void printMenu (){
    printf ("1. Delete a file\n");
    printf ("2. Rename a file\n");
    printf ("3. Move a file\n");
    printf ("4. Exit\n");
}
