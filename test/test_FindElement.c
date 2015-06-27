#include "unity.h"
#include "FindElement.h"
#include "SimpleList.h"
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_intCompare()
{
  int first = 1;
  int second = 3;
 // int equalno = intCompare(&first, &second);
 // printf("euqal x? %d\n", equalno);
  TEST_ASSERT_EQUAL(-1, intCompare(&first, &second));
}


void test_stringCompare()
{
  char *first = "ab";
  char *second = "ab";
  //int equal = stringCompare(first, second);
  //printf("*STR equal x? %d\n", equal);
  TEST_ASSERT_EQUAL(0,stringCompare(first, second));
}

void test_findElement()
{
  int value1 = 1;
  int myValue1 = 1;
  int value3 = 3;
  int value4 = 4;
  int value6 = 6;
  int value7 = 7;

	List *list = listCreate();
  Element *elem, *elemNext;
  
  elemNext = elementCreate(&value6);
  elem = elementCreate(&value4);
  elem->next = elemNext;
  elemNext = elem;
  
 // printf("%p\n",(elem->data));

  elem = elementCreate(&value1);
  elem->next = elemNext;
  elemNext = elem;
  
  elem = elementCreate(&value7);
  elem->next = elemNext;
  elemNext = elem;

  elem = elementCreate(&value3);
  elem->next = elemNext;
  elemNext = elem;

  // ...
  
 // elem = elementCreate(&value3);
  list->head = elem;
  
  // while(list->head != NULL)
  // {
    // printf("%d",*((int *)(list->head->data)));
    // list->head = list->head->next;
  // }

  
  elem = NULL;
  elem = listFind(list, &myValue1, intCompare);
  
  TEST_ASSERT_NOT_NULL(elem);
  TEST_ASSERT_NOT_NULL(elem->data);
  // //TEST_ASSERT_EQUAL(1,*(int *)(elem->data)); //error
  // // TEST_ASSERT_EQUAL(1,*(elem->data)); //error
  TEST_ASSERT_EQUAL(value1, *((int *)elem->data));
  TEST_ASSERT_EQUAL(value4, *((int *)elem->next->data));
}