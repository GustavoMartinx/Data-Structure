#include "stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**************************************
* Data Specification
**************************************/
typedef struct node {
    ElementType data;
    Node* next;
} Node;

struct stack {
    int qtde;
    Node* top;
};


/***********************************************
* Auxiliary Functions
************************************************/

Node* createNode(ElementType element) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = element;
    new->next = NULL;
    return new;
}

bool valid_stack(Stack* p){
    return (p != NULL ? true : false);
}

/**************************************
* Functions Implementations
**************************************/
Stack* stack_create() {
    Stack* p = (Stack*) malloc(sizeof(Stack));
    p->qtde = 0;
    p->top = NULL;
    return p;
}


void stack_destroy(Stack** adress) {
    if(!valid_stack(*adress)) return;

    Stack* p = *adress;
    Node* aux;

    while(p->top != NULL){
        aux = p->top;
        p->top = p->top->next;
        free(aux);
    }

    free(p);
    *adress = NULL;
}


bool stack_pile(Stack* p, ElementType element) {
    if(!valid_stack(p)) return false;

    // Creating the node
    // Criando o nó
    Node* new = criaNode(element);

    // Concatenating the node on Stack. Insertion on the top
    // Encadeando o nó na Pilha. Inserção node topo 
    new->next = p->top;
    
    // Updating the top
    // Atualizando o topo
    p->top = new;
    p->qtde++;
    return true;
}


bool stack_unstack(Stack* p, ElementType* out) {
    if(!valid_stack(p)) return false;
    if(stack_empty(p)) return false;

    *out = p->top->data;    
    Node* aux = p->top;
    p->top = p->top->next;    
    free(aux);
    p->qtde--;

    return true;
}


bool stack_top(Stack* p, ElementType* out) {
    if(!valid_stack(p)) return false;
    if(stack_empty(p)) return false;

    *out = p->top->data;
    return true;
} 


bool stack_empty(Stack* p) {
    if(!valid_stack(p)) return false;

    return (p->qtde == 0 ? true : false);
}

void stack_toString(Stack* p, char* out) {
    if(!valid_stack(p)) return;

    out[0] = '\0';
    strcat(out, "[");
    Node* aux = p->top;
    while(aux != NULL){
        char element[20];
        sprintf(element, "%d", aux->data);
        strcat(out, element);
        if(aux->next != NULL) strcat(out, ",");
        
        aux = aux->next;
    }
    strcat(out, "]");   
}


// void stack_print(Stack* p) {
//     Node* aux = p->top;
    
//     while(aux != NULL) {
//         printf("%d\n", aux->data);        
//         aux = aux->next;
//     }
// }


void print_recursive(Node* node) {
    if(node != NULL) {
        print_recursive(node->next);
        printf("%d\n", node->data);
    }
}

void stack_print(Stack* p) {

    print_recursive(p->top);
    
}