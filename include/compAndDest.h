#ifndef COMPANDDEST_H
#define COMPANDDEST_H

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareInt (void * data1, void * data2);

void destroyInt (void * node);

int compareFile (void * data1, void * data2);

void destroyFile (void * node);
#endif
