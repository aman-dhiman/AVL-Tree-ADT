#include "fileIO.h"

void populateTree(const char *name, int level, Tree * theTree)
{
    DIR *dir;
    struct dirent *entry;
    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s[%s]\n", level*4, "", entry->d_name);
            addToTree (theTree, entry->d_name);
            populateTree(path, level + 1, theTree);
        }
        else {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            printf("%*s- %s\n", level*4, "", entry->d_name);
            addToTree (theTree, entry->d_name);
        }
    } while ((entry = readdir(dir)) != NULL);
    closedir(dir);
}

void listDir(const char *name, int level, Tree * theTree)
{
    DIR *dir;
    struct dirent *entry;
    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s[%s]\n", level*4, "", entry->d_name);
            listDir(path, level + 1, theTree);
        }
        else {
            printf("%*s- %s\n", level*4, "", entry->d_name);
        }
    } while ((entry = readdir(dir)) != NULL);
    closedir(dir);
}


/*void listDir (char * dir){
    DIR * dPtr;
    struct dirent *ePtr;
    dPtr = opendir (dir);

    if (dPtr != NULL) {
        while ((ePtr = readdir (dPtr)) != NULL){
            printf ("%s\n", ePtr->d_name);
        }
        closedir (dPtr);
    }
    else {
        perror ("Couldn't open the directory.");
    }

    int flags = 0;
    nftw (dir, displayDir, 20, flags);
}*/

void deleteDir (char * dir, int * removed){
    *removed = remove (dir);
    if (*removed == 0){
        printf ("File successfully deleted.\n");
    }
    else {
        printf ("Error: Unable to delete file.\n");
    }
}

void renameOrMove (int type, char * oldDir, char * newDir){
    int renamed;
    renamed = rename (oldDir, newDir);
    if (renamed == 0){
        if (type == 0){
            printf ("File Successfully renamed.\n");
        }
        else {
            printf ("File Successfully moved.\n");
        }
    }
    else {
        if (type == 0){
            printf ("Error: Unable to rename file.\n");
        }
        else {
            printf ("Error: Unable to move file.\n");
        }
    }
}

/*int displayDir (const char * path, const struct stat *sPtr, int type, struct
                FTW * buffer){
    const char * name = path + buffer->base;
    printf ("%*s", buffer->level * 4, "");
    switch (type){
        case FTW_F:
            printf ("%s (File)\n", name);
            break;

        case FTW_D:
            printf ("%s (Folder)\n", name);
            break;
    }
    return 0;
}
*/
