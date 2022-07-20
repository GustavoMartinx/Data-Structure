#include "queue.h"
#include <string.h>

/**************************************
* Data Specification
**************************************/
typedef struct node {
    int data;
    struct node* next;
} Node;

struct queue {
    Node* start;
    Node* end;
    int qtde;
};

/**************************************
* Auxiliary Functions
**************************************/

bool queue_valid(Queue* q) {
    return (q != NULL? true: false);
}

Node* newNode(int valor) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = valor;
    new->next = NULL;
    return new;
}

/**************************************
* Functions Implementations
**************************************/
Queue* queue_create() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->start = NULL;
    queue->end = NULL;
    queue->qtde = 0;
    return queue;
}

void queue_destroy(Queue** queueAdress);

bool queue_insert(Queue* q, ElementType element) {
    if(!queue_valid(q)) return false;

    Node* new = newNode(element);

    if(queue_empty(q)) {
        q->start = new;
    } else {
        q->end->next = new;
    }
    q->end = new;
    q->qtde++;

    return true;
}

bool queue_remove(Queue* q, ElementType* out) {
    if(!queue_valid(q)) return false;
    if(queue_empty(q)) return false;

    Node* aux = q->start;
    q->start = q->start->next;
    q->qtde--;
    
    *out = aux->data;
    free(aux);
    
    if(q->start == NULL){        
        q->end = NULL;
    }
    
    return true;
}

bool queue_first(Queue* q, ElementType* out) {
    if(!queue_valid(q)) return false;
    if(queue_empty(q)) return false;

    *out = q->start->data;
    return true;
}
bool queue_empty(Queue* q) {
    if(!queue_valid(q)) return true;

    return (q->qtde == 0 ? true : false);
}

int queue_size(Queue* q) {
    if(!queue_valid(q)) return 0;

    return q->qtde;
}

bool queue_toString(Queue* q, char* str) {
    if (!queue_valid(q)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char element[20];

    Node* aux = q->start;
    
    while(aux != NULL) {    
        sprintf(element,"%d", aux->data);
        strcat(str, element);
        if (aux->next != NULL) strcat(str, ",");
        aux = aux->next;
    }
    strcat(str, "]");
    return true;
}