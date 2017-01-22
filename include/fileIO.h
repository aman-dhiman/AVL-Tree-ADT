#ifndef FILEIO_H
#define FILEIO_H

#include "helper.h"
#include "compAndDest.h"
#include "wrapper.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*void listDir (char * dir);*/
void populateTree(const char *name, int level, Tree * theTree);
void listDir (const char * name, int level, Tree * theTree);
void deleteDir (char * dir, int * removed);
void renameOrMove (int type, char * oldDir, char * newDir);
/*int displayDir (const char * path, const struct stat * sPtr, int type, struct
                FTW * buffer);*/

#endif
