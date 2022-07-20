#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/**************************************
* DATAS
**************************************/
typedef int ElementType;
typedef struct queue Queue;

/**************************************
* PROTOTYPES
**************************************/
Queue* queue_create();
void queue_destroy(Queue** queueAdress);

bool queue_insert(Queue* q, ElementType element);
bool queue_remove(Queue* q, ElementType* out); 

bool queue_first(Queue* q, ElementType* out); 

bool queue_empty(Queue* q);
int queue_size(Queue* q);
bool queue_toString(Queue* q, char* out);


#endif