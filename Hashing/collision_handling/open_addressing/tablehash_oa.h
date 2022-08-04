#pragma once

typedef enum STATE {   // Estado
    S_FREE,     // Livre
    S_BUSY,     // Ocupado
    S_DELETED   // Apagado
} STATE;

typedef struct ELEM {  // structure that defines each element of the table
    int key;
    int value;
    STATE state;
} ELEM;

typedef struct HTOA {  // THEA Tabela Hash com Endereçamento Aberto // Hash Table whith Open Adressing
    int m;  // size of hash table (but can variable)
    ELEM* HT;  // Hash Table
} HTOA;

int HTOA_hash(HTOA* HT, int key, int k); // calculate the hash (function)
HTOA* HTOA_create(int m);
int HTOA_insert(HTOA* HT, int key, int value);
int HTOA_search(HTOA* HT, int key);
void HTOA_remove(HTOA* HT, int key);

// Ex 1 b) - Lista 6
int min(THEA* TH);