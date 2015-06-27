#include "FindElement.h"
#include "SimpleList.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Element *listFind(List *list, void *data)
// {
  // Element *tempElement = malloc(sizeof(Element));
  
  // //printf("%d data\n",*((int *)data));
  // tempElement = list->head;
  // while(tempElement != NULL && tempElement->data != data)
  // {
    // tempElement = tempElement->next;
    // printf("%p\n",tempElement);
  // }
  // //printf("now = %d",*((int *)(tempElement->data)));
  
  // return tempElement;
  
// }

int intCompare(void *first, void *second) //0 = equal,non-0 =not equal
{
  //printf("first value in int = %d\n",*((int *)first));
  if(*((int *)first) == *((int *)second))
    return 0;
  else if(*((int *)first) > *((int *)second))
    return 1;
  else
    return -1;
}

int strCompare(void *first, void *second)
{
  //printf("first = %s\n", (char *)first);
  return (strcmp(((char *)first),((char *)second)));
}

Element *listFind(List *list, void *data, int (*compare)(void *, void *))
{
  Element *tempElement = malloc(sizeof(Element));
  //printf("%d data\n",*((int *)data));
  tempElement = list->head;
  while(tempElement != NULL && compare(tempElement->data,data) != 0)
    tempElement = tempElement->next;
    //printf("%p\n",tempElement);
  //printf("now = %d",*((int *)(tempElement->data)));
  
  return tempElement;
}