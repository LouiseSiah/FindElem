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


void test_strCompare()
{
  char *first = "ab";
  char *second = "ab";
  //int equal = stringCompare(first, second);
  //printf("*STR equal x? %d\n", equal);
  TEST_ASSERT_EQUAL(0,strCompare(first, second));
}

void test_findElement()
{
  // int value1 = 1;
  // int myValue1 = 1;
  // int value3 = 3;
  // int value4 = 4;
  // int value6 = 6;
  // int value7 = 7;

  char *str1 = "one";
  char *str3 = "three";
  char *str4 = "four";
  char *str6 = "six";
  char *str7 = "seven";
  char *myStr4 = "four";
  
	List *list = listCreate();
  Element *elem, *elemNext;
  
  elemNext = elementCreate(str6);
  elem = elementCreate(str4);
  elem->next = elemNext;
  elemNext = elem;
  
 // printf("%p\n",(elem->data));

  elem = elementCreate(str1);
  elem->next = elemNext;
  elemNext = elem;
  
  elem = elementCreate(str7);
  elem->next = elemNext;
  elemNext = elem;

  elem = elementCreate(str3);
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
  elem = listFind(list, myStr4, strCompare);
  
  TEST_ASSERT_NOT_NULL(elem);
  TEST_ASSERT_NOT_NULL(elem->data);
  // //TEST_ASSERT_EQUAL(1,*(int *)(elem->data)); //error
  // // TEST_ASSERT_EQUAL(1,*(elem->data)); //error
  TEST_ASSERT_EQUAL_STRING(str4, (char *)elem->data);
  TEST_ASSERT_EQUAL_STRING("four", ((char *)elem->data));
}