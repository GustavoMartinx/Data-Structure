#pragma once

#include "ilist.h"

typedef struct THED {   // Tabela Hash com Encadeamento Direto
    ILIST** t;
    size_t m, n;
} THED;

int THED_Hash(THED* HT, int chave);
THED* THED_Criar(int m, int alloc_step);
void THED_Inserir(THED* HT, int chave, int valor);
void THED_Remover(THED* HT, int chave);
INOH* THED_Buscar(THED* HT, int chave);
void THED_Imprimir(THED* HT);
size_t THED_N(THED* HT);
ILIST* THED_Chaves(THED* HT);
void THED_Destruir(THED* HT);

// Ex 1 - Lista 5: Encadeamento Direto 
unsigned int string_hash(char* string, int M, int k);
