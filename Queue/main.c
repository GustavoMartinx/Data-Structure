#include <stdio.h>
#include <string.h>

#include "queue.h"

#define ERROR "***ERROR***"

int main() {

    
    char str[200];
    ElementType element;


    /**************************************
    * Testing insertion and first
    **************************************/
    Queue* q1 = queue_create();
    queue_insert(q1, 10);
    queue_insert(q1, 20);
    queue_insert(q1, 30);
    queue_toString(q1, str);
    printf("----- Testing Insertion -----\n");
    printf("%s\n", strcmp(str, "[10,20,30]")==0 ? "[OK]" : ERROR);
    

    printf("----- Testing First -----\n");
    queue_first(q1, &element);
    printf("%s\n", element == 10 ? "[OK]" : ERROR);    

    /**************************************
    * Testing remove
    **************************************/
    printf("----- Testing Remove -----\n");
    queue_remove(q1, &element);
    printf("%s\n", element == 10 ? "[OK]" : ERROR); 
    
    queue_remove(q1, &element);
    printf("%s\n", element == 20 ? "[OK]" : ERROR);
    
    queue_remove(q1, &element);
    printf("%s\n", element == 30 ? "[OK]" : ERROR);
    
    bool result = queue_remove(q1, &element);
    printf("%s\n", result == false ? "[OK]" : ERROR);

    printf("----- Testing toString Empty Queue -----\n");
    queue_toString(q1, str);
    printf("%s\n", strcmp(str, "[]")==0 ? "[OK]" : ERROR);
    

    // queue_destroy(&q1);

}