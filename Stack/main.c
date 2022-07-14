#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "stack.h"

void test_print_recursive() {
    Stack* p1 = stack_create();
    stack_pile(p1, 10);
    stack_pile(p1, 20);
    stack_pile(p1, 30);

    stack_print(p1);
    stack_destroy(&p1);
}

int main() {

    test_print_recursive();
    
    Stack* p1 = stack_create();
    stack_pile(p1, 10);
    stack_pile(p1, 20);
    stack_pile(p1, 30);

    char str[200];
    stack_toString(p1, str);
    printf("%s\n", str); //[30,20,10]

    int element;

    stack_top(p1, &element);
    printf("Top: %d\n", element); // 30
    
    while(!stack_empty(p1)) {  // 30 20 10
        stack_unstack(p1, &element);
        printf("Unstacked: %d\n", element); 
    }

    
    /***********************************************
    * EMPTY STACK OPERATIONS
    ************************************************/
    if(!stack_unstack(p1, &element)) {
        printf("Stack empty\n");
    }
    
    if(!stack_top(p1, &element)) {
        printf("Stack empty\n");
    }

    stack_toString(p1, str);
    printf("%s\n", str);  // []
    
    stack_destroy(&p1);


    return 0;
}