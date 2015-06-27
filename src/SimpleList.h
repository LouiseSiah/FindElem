#ifndef SimpleList_H
#define SimpleList_H

typedef struct Element_t Element; //the way of pointing to myself
struct Element_t
{
  Element *next;
  void *data; //any type also can
};

typedef struct
{
  Element *head;
  int length;
} List;

List *listCreate();
Element *elementCreate(void *data);
void elementDestroy(Element *elem);

#endif // SimpleList_H
