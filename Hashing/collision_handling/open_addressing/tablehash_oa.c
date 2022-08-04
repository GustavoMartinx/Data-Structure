#include "tablehash_oa.h"
#include <stdlib.h>

int HTOA_hash(HTOA* HT, int key, int k) {
    return ((key % HT->m) + k) % HT->m; // (all) % HT->m  to get circular behavior (going through the whole table)
}


HTOA* HTOA_create(int m) {
    HTOA* new;  // creating a new HT
    new = malloc(sizeof(HTOA)); // allocating the new HT
    new->HT = malloc(sizeof(ELEM) * m); // allocating elem vector
    new->m = m;

    for (int i = 0; i < m; i++) {
        new->HT[i].state = S_FREE;
    }
    return new;
}

int HTOA_insert(HTOA* HT, int key, int value) {
    int h;  // ponto onde iniciam-se as tentativas de fazer a inserção
    int k;
    int h_init;  // onde iniciou-se a busca por um espaço livre para realizar a inserção

    h = HTOA_hash(HT, key, k);
    
    if(h < 0) {
        k = 0;
        h_init = h;                                                                                                                                                

        while(HT->HT[h].state == S_BUSY) {
            if(HT->HT[h].key == key) {
                break;
            }

            k++;
            h = HTOA_hash(HT, key, k);

            if(h == h_init) {
                return -1;
            }
        }
    }

    HT->HT[h].key = key;
    HT->HT[h].value = value;
    HT->HT[h].state = S_BUSY;

    return h;
}

int HTOA_search(HTOA* HT, int key) {
    int h;
    int h_init;
    int k;

    k = 0;
    h = HTOA_hash(HT, key, k);
    h_init = h;

    while(HT->HT[h].state != S_FREE) {
        if((HT->HT[h].state == S_BUSY) && (HT->HT[h].key == key)) {
            return h;
        }

        k++;
        h = HTOA_hash(HT, key, k);

        if(h_init == h) {
            return -1;
        }
    }
    return -1;
}

void HTOA_remove(HTOA* HT, int key) {
    int x = HTOA_search(HT, key);
    if(x != -1) {
        HT->HT[x].state = S_DELETED;
    }
}


// Ex 1 b) - Lista 6
int min(THEA* TH) {
    HT->HT
}