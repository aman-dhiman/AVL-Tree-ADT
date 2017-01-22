#ifndef WRAPPER_H
#define WRAPPER_H

#include "helper.h"

Tree * createTree (int (*compare) (void * data1, void * data2), void (*destroy) 
                  (void * nodeValue));
void destroyTree (Tree * theTree);
void addToTree (Tree * theTree, void * value);
void removeFromTree (Tree * theTree, void * value);

#endif
