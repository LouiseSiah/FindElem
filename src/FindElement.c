#include "FindElement.h"
#include "SimpleList.h"
#include <stdio.h>
#include <malloc.h>

Element *listFind(List *list, void *data)
{
  Element *tempElement = malloc(sizeof(Element));
  //printf("%x",tempElement->next);
  
  //printf("%d data\n",*((int *)data));
  tempElement = list->head;
  while(tempElement != NULL && tempElement->data != data)
  {
    tempElement = tempElement->next;
    printf("%p\n",tempElement);
  }
  //printf("now = %d",*((int *)(tempElement->data)));
  
  return tempElement;
  
}