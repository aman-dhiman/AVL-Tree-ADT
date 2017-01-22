#include "main.h"

int main (int argc, char * argv[]){
    Tree * theTree = createTree (&compareFile, &destroyFile);
    char oldName[100];
    char newName[100];

    char choice;
    printf("\e[1;1H\e[2J");
    if (argc == 2){
        populateTree (argv[1], 0, theTree);
    }
    else {
        populateTree (".", 0, theTree);
    }
    printf ("\n");
    printMenu();

    while ((choice = getchar()) != '4'){
        switch (choice){
            case '1':
                printf ("\n");
                printf ("Enter the full path for the directory you wish to delete\n");
                scanf ("%s", oldName);
                printf("\e[1;1H\e[2J");
                deleteFile (oldName, theTree);
                break;

            case '2':
                printf ("\n");
                printf ("Enter the full path for the directory you wish to rename\n");
                scanf ("%s", oldName);
                printf ("Enter the full path of the new directory\n");
                scanf ("%s", newName);
                printf("\e[1;1H\e[2J");
                renameFile (0, oldName, newName, theTree);
                break;

            case '3':
                printf ("\n");
                printf ("Enter the full path for the directory you wish to move\n");
                scanf ("%s", oldName);
                printf ("Enter the full path of the new directory\n");
                scanf ("%s", newName);
                printf("\e[1;1H\e[2J");
                renameFile (1, oldName, newName, theTree);
                break;

            default:
                printf("\e[1;1H\e[2J");
                printf ("Invalid input. Please select one of the given options\n");
                break;
        }
        printf ("\n");
        if (argc == 2){
            listDir (argv[1], 0, theTree);
        }
        else {
            listDir (".", 0, theTree);
        }
        printf ("\n");
        printMenu();
        getchar();
    }

    destroyTree (theTree);
    return 0;
}
