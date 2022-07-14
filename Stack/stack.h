#ifndef _STACK_H_
#define _STACK_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h>

/**************************************
* DATAS
**************************************/
typedef int ElementType;
typedef struct stack Stack;

/**************************************
* PROTOTYPES
**************************************/
Stack* stack_create();
void stack_destroy(Stack** endereco);
bool stack_pile(Stack* p, ElementType elemento);
bool stack_unstack(Stack* p, ElementType* saida); 
bool stack_top(Stack* p, ElementType* saida); 
bool stack_empty(Stack* p);
void stack_toString(Stack* p, char* saida);
void stack_print(Stack* p);

#endif