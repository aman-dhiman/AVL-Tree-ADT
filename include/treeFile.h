#ifndef TREEFILE_H
#define TREEFILE_H

#include "wrapper.h"
#include "fileIO.h"

void deleteFile (char * file, Tree * theTree);
void renameFile (int type, char * oldName, char * newName, Tree * theTree);
void printMenu ();

#endif
