#include "list.h"

/**************************************
* DAtaS
**************************************/
typedef struct node {
	ElementType data;
	struct node *previous;
	struct node *next;
} Node;

struct list {
    Node *start;
	Node *end;
	int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
bool list_valid(List* l) {    
    return (l != NULL? true: false);    
}

Node* create_node(ElementType element) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = element;
    new->next = NULL;
    new->previous = NULL;
    return new;
}

bool position_valid(List* l, int pos) {
    if(pos < 0) return false;
    if(pos > l->qtde) return false;

    return true;
}

bool position_completed(List* l, int pos) {
    if(pos < 0) return false;
    if(pos >= l->qtde) return false;

    return true;
}

Node* nodeAdress(List* l, int pos) {
    Node* aux = l->start;
    for(int cont = 0; cont < pos; cont++){
        aux = aux->next;
    }
    return aux;
}

int convertPosition(List* l, int pos) {
    return pos < 0 ? l->qtde+pos : pos;
}

/**************************************
* PROTOTYPES
**************************************/
List* list_create() {
    List* new = (List*) malloc(sizeof(List));
    new->start = NULL;
    new->end = NULL;
    new->qtde = 0;
    return new;
}

void list_destroy(List** listAdress) {
    List* l = *listAdress;
    Node* aux;
    while(l->start != NULL) {
        aux = l->start;
        l->start = l->start->next;
        free(aux);
    }    
    free(l);
    *listAdress = NULL;
}

bool list_attach(List* l, ElementType element) {
    if(!list_valid(l)) return false;

    Node* new = create_node(element);
    if(list_empty(l)) {
        l->start = new;        
    } else {
        l->end->next = new;
        new->previous = l->end;
    }
    l->end = new;
    l->qtde++;
    return true;
}

bool list_insert(List* l, ElementType element, int position) {
    if(!list_valid(l)) return false;
    position = convertPosition(l, position);
    if(!position_valid(l, position)) return false;

    Node* new = create_node(element);
    if(list_empty(l)) {
        l->start = new;
        l->end = new;
        l->qtde++;
    } else if (position == l->qtde) {
        list_attach(l, element);
    } else if (position == 0) {
        new->next = l->start;
        l->start->previous = new;
        l->start = new;
        l->qtde++;
    } else {
        Node* aux = nodeAdress(l, position-1);        

        new->next = aux->next;
        new->previous = aux;
        new->next->previous = new;
        aux->next = new;  
    }
    return true;
}

bool list_removePosition(List* l, int position, ElementType* adress) {
    if(!list_valid(l)) return false;
    if(list_empty(l)) return false;
    position = convertPosition(l, position);
    if(!position_completed(l, position)) return false;

    
    Node* aux;
    if(l->qtde == 1) {
    
        aux = l->start;
        l->start = NULL;
        l->end = NULL;

    } else if (position == 0) {
        aux = l->start;
        l->start = l->start->next;
        l->start->previous = NULL;
        aux->next = NULL;

    } else if (position == l->qtde-1) {
        aux = l->end;
        l->end = l->end->previous;
        l->end->next = NULL;
        aux->previous = NULL;
    } else {
        aux = nodeAdress(l, position);
        aux->next->previous = aux->previous;
        aux->previous->next = aux->next;
        aux->next = NULL; 
        aux->previous = NULL; 
    }
    *adress = aux->data;
    free(aux);
    l->qtde--;
    return true;
}


int list_removeElement(List* l, ElementType element) {
    if(!list_valid(l)) return false;

    int position = list_position(l, element);
    if(position == -1) return -1;
    ElementType item;
    list_removePosition(l, position, &item);
    return position;
}

bool list_replace(List* l, int position, ElementType newElement) {
    if(!list_valid(l)) return false;
    if(!position_valid(l, position)) return false;

    Node* node = nodeAdress(l, position);
    node->data = newElement;
    return true;
}

int list_position(List* l, ElementType element) {
    if(!list_valid(l)) return -1;    

    int pos = 0;
    Node* aux = l->start;
    while(aux != NULL){
        if(element == aux->data) return pos;
        pos++;
        aux = aux->next;
    }
    return -1;  
}

bool list_search(List* l, int position, ElementType* adress) {
    if(!list_valid(l)) return false;
    position = convertPosition(l, position);
    if(!position_valid(l, position)) return false;

    Node* node = nodeAdress(l, position);
    *adress = node->data;
    return true;
}

int list_size(List* l) {
    if(!list_valid(l)) return -1;

    return l->qtde;
}

bool list_empty(List* l) {
    if(!list_valid(l)) return true;

    return (l->qtde == 0 ? true : false);
}

bool list_toString(List* l, char* str) {
    if(!list_valid(l)) return false;

    int qtde = 0;
    char element[20];
    
    str[0] = '\0';
    strcat(str, "[");
    Node* aux = l->start;
    while(aux != NULL){
        sprintf(element, "%d", aux->data);
        strcat(str, element);
        
        if(aux->next != NULL) strcat(str, ",");

        aux = aux->next;
    }

    strcat(str, "]");
    return true;
}