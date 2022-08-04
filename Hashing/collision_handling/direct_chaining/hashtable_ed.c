#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED* HT, int chave){
    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
    THED* nova;
    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->n = 0;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(int i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);
    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor){
    int h = THED_Hash(HT, chave);
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Inserir(HT->t[h], chave, valor);
    if(tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n++;
}

void THED_Remover(THED* HT, int chave){
    int h = THED_Hash(HT, chave);
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Remover(HT->t[h], chave);
    if(tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n--;
}

INOH* THED_Buscar(THED* HT, int chave){
    int h = THED_Hash(HT, chave);
    int p = ILIST_Buscar(HT->t[h], chave);
    return ILIST_Endereco(HT->t[h], p);
}

void THED_Imprimir(THED* HT){
    printf("TABELA HASH M = %ld\n", HT->m);
    for(int i = 0; i < HT->m; i++){
        printf("%d:\n", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
    printf("===");
}

size_t THED_N(THED* HT){
    return HT->n;
}

ILIST* THED_Chaves(THED* HT){
    ILIST* s = ILIST_Criar(THED_N(HT) + 1);
    INOH* p;
    for(int i = 0; i < HT->m; i++){
        ILIST_Rebobinar(HT->t[i]);
        p = ILIST_Prox(HT->t[i]);
        while(p != NULL)
        {
            ILIST_Inserir(s, p->chave, p->valor);
            p = ILIST_Prox(HT->t[i]);
        }
    }
    return s;
}

void THED_Destruir(THED* HT){
    for(int i = 0; i < HT->m; i++)
        ILIST_Destruir(HT->t[i]);
    free(HT->t);
    free(HT);
}

// ***** Ex 1 a) - Lista 5: Encadeamento Direto *********

unsigned int string_hash(char* string, int M, int k) {
    int n = -1; // número de elementos da string (a partir de zero)
    
    // for p contar o n de elem da string
    for(int i = 0; i < n; i++) {
        string[i];
        n++; // *n += *n;
    }

    // representando a string por um int (acum)
    int acum = 0;
    while(n > -1) {
        int i = 0;

        acum += (string[i] * (pow(k, n)));
        n--;
        i++;
    }

    // retorna o mod
    return (acum % M);
}