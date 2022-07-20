#include "fila.h"
#include <string.h>

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct fila {
	TipoElemento* vetor;
	int tam;
	int inicio;
	int fim;
	int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f) {
    return (f != NULL? true: false);
    
}

void realoca(Fila* f, int novoTamanho) {
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    int pos = f->inicio;

    for(i = 0; i < f->qtde; i++) {
        vetorAuxiliar[i] = f->vetor[pos];        
        pos = (pos+1) % f->tam;
    }
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    
    f->inicio = 0;
    f->fim = f->qtde;
    f->tam = novoTamanho;
}

void verifica_aumenta(Fila* f) {
    if(f->qtde == f->tam - 1) { // precisamos deixar 1 posicao vazia entre o fim e o inicio
        realoca(f, f->tam*2);
    }
}

void verifica_diminui(Fila* f) {
    if (f->qtde <= f->tam / 4 && f->tam > TAM_INICIAL) {
        realoca(f, f->tam/2);
    }
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tam = TAM_INICIAL;
    f->qtde = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir(Fila** enderecoFila) {
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento) {
    if(!fila_ehValida(f)) return false;

    verifica_aumenta(f);
    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tam;
    f->qtde++;

    return true;

}

bool fila_remover(Fila* f, TipoElemento* saida) {
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    TipoElemento elemento = f->vetor[f->inicio];
    f->inicio = (f->inicio+1) % f->tam;
    *saida = elemento;
    f->qtde--;
    verifica_diminui(f);
    
    return true;
}


bool fila_primeiro(Fila* f, TipoElemento* saida) { // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia(Fila* f) {
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int fila_tamanho(Fila* f) {
    if(!fila_ehValida(f)) return 0;

    return f->qtde;
}

bool fila_toString(Fila* f, char* str) {
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    int i = f->inicio;
    while(i != f->fim){
        sprintf(elemento,"%d", f->vetor[i]);
        strcat(str, elemento);
        if ((i+1)%f->tam != f->fim) strcat(str, ",");
        i = (i+1) % f->tam;
    }
    strcat(str, "]");
    return true;
}
