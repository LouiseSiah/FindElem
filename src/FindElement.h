#ifndef FindElement_H
#define FindElement_H

#include "SimpleList.h"
#include <string.h>
//Element *listFind(List *list, void *data);
int intCompare(void *first, void *second);
int strCompare(void *first, void *second);
Element *listFind(List *list, void *data, int (*compare)(void *, void *));

#endif // FindElement_H
