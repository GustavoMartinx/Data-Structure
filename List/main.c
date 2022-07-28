#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "list.h"

void test_string(char* result, char* waiting){
    bool test = strcmp(waiting, result) == 0;
    printf("[%s] %s \n", (test ? "PASS" : "ERROR"), result);
}

void test_int(int result, int waiting){        
    printf("[%s] %d \n", (result==waiting ? "PASS" : "ERROR"), result);
}

void test_bool(bool result, bool waiting){ 
    printf("[%s] %s \n", (result==waiting ? "PASS" : "ERROR"), result ? "true" : "false");
}

void test_attach(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTING ATTACH \n");
    printf("------------------------------------------------\n");

    List* l = list_create();
    list_attach(l, 10);
    list_attach(l, 20);
    list_attach(l, 30);

    char str[300];    
    list_toString(l, str);
    test_string(str, "[10,20,30]");  
}

void test_insert(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTING INSERT \n");
    printf("------------------------------------------------\n");
    char str[300];
    bool result = false;
    
    List* l = list_create();

    // insertion into empty list
    // inserção na list vazia
    list_insert(l, 10, 0);

    list_toString(l, str);
    test_string(str, "[10]");
    
    // insertion into first position
    // inserção na primeira posição
    list_insert(l, 5, 0);
    list_insert(l, 3, 0);
    list_toString(l, str);
    test_string(str, "[3,5,10]");

    // insertion in the last position
    // inserção na última posição
    list_insert(l, 40, 3);
    list_insert(l, 50, 4);
    list_toString(l, str);
    test_string(str, "[3,5,10,40,50]");
    
    // insertion in the middle
    // inserção no meio
    list_insert(l, 15, 3);
    list_toString(l, str);
    test_string(str, "[3,5,10,15,40,50]");
}

void test_removePosition() {
    printf("\n------------------------------------------------\n");
    printf(">>> TESTING REMOVE BY POSITION\n");
    printf("------------------------------------------------\n");
    
    List* l = list_create();
    list_attach(l, 10);
    list_attach(l, 20);
    list_attach(l, 30);
    list_attach(l, 40);
    list_attach(l, 50);

    ElementType item;
    char str[300];
  
    // Removing the first position
    // Remoção da primeira posição
    list_removePosition(l, 0, &item);
    list_toString(l, str);
    test_int(item, 10); // [PASS] 10
    test_string(str, "[20,30,40,50]");
 
    // Removing the last position
    // Remoção da última posição
    list_removePosition(l, 3, &item);
    list_toString(l, str);
    test_int(item, 50);
    test_string(str, "[20,30,40]");
 
    // Removing the middle
    // Remoção do meio
    list_removePosition(l, 1, &item);
    list_toString(l, str);
    test_int(item, 30);
    test_string(str, "[20,40]");

    // Removing of last position with negative index
    // Remoção da última posição com índice negativo
    list_removePosition(l, -1, &item);    
    list_toString(l, str);
    test_int(item, 40);
    test_string(str, "[20]");

    // Removing the last element 
    // Remoção do último elemento
    list_removePosition(l, -1, &item);
    list_toString(l, str);
    test_int(item, 20);
    test_string(str, "[]");

    // Removing in a empty list
    // Remoção na list vazia
    bool test = list_removePosition(l, 0, &item);
    test_bool(test, false);
}

void test_removeElement() {
    printf("\n------------------------------------------------\n");
    printf(">>> TESTING REMOVE POR ELEMENT\n");
    printf("------------------------------------------------\n");
    
    List* l = list_create();
    list_attach(l, 10);
    list_attach(l, 20);
    list_attach(l, 30);
    list_attach(l, 40);
    list_attach(l, 50);

    int position;
    char str[300];


    // Removing an element that not exists
    // Remoção de um elemento que não existe
    position = list_removeElement(l, 100);
    test_int(position, -1);
    
    // Removing the first position element
    // Remoção do elemento da primeira posição
    position = list_removeElement(l, 10);    
    list_toString(l, str);
    test_int(position, 0);
    test_string(str, "[20,30,40,50]");

    // Removing the last position element
    // Remoção do elemento da última posição
    position = list_removeElement(l, 50);
    list_toString(l, str);
    test_string(str, "[20,30,40]");
    test_int(position, 3);
    
    
    // Removing the middle element
    // Remoção do element no meio
    position = list_removeElement(l, 30);
    list_toString(l, str);
    test_int(position, 1);
    test_string(str, "[20,40]");
    

    // Removing the last position element
    // Remoção do elemento da última posição
    position = list_removeElement(l, 40);
    list_toString(l, str);
    test_int(position, 1);
    test_string(str, "[20]");
    
    // Removing the last element
    // Remoção do último elemento
    position = list_removeElement(l, 20);
    list_toString(l, str);
    test_int(position, 0);
    test_string(str, "[]");

    // Removing into a empty list
    // Remoção na list vazia
    position = list_removeElement(l, 40);
    test_int(position, -1);
}


int main() {

    test_attach();
    test_insert();
    test_removePosition();
    test_removeElement();

    return 0;
}
