#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int ElementType;

/**************************************
* DATA
**************************************/
typedef struct list List;


/**************************************
* PROTOTYPE
**************************************/
List* list_create();
void list_destroy(List** listdress);

bool list_attach(List* l, ElementType element);
bool list_insert(List* l, ElementType element, int position);

bool list_removePosition(List* l, int position, ElementType* adress);
int list_removeElement(List* l, ElementType element);

bool list_replace(List* l, int position, ElementType newElement);
int list_position(List* l, ElementType element);
bool list_search(List* l, int position, ElementType* adress);

int list_size(List* l);
bool list_empty(List* l);
bool list_toString(List* l, char* str);

#endif