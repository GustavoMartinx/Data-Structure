#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "lista.h"

void teste_string(char* resultado, char* esperado){
    bool teste = strcmp(esperado, resultado) == 0;
    printf("[%s] %s \n", (teste ? "PASS" : "ERROR"), resultado);
}

void teste_int(int resultado, int esperado){        
    printf("[%s] %d \n", (resultado==esperado ? "PASS" : "ERROR"), resultado);
}

void teste_bool(bool resultado, bool esperado){ 
    printf("[%s] %s \n", (resultado==esperado ? "PASS" : "ERROR"), resultado ? "true" : "false");
}

void teste_anexar(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE ANEXAR \n");
    printf("------------------------------------------------\n");

    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);

    char str[300];    
    lista_toString(l, str);
    teste_string(str, "[10,20,30]");  
}

void teste_inserir(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INSERIR \n");
    printf("------------------------------------------------\n");
    char str[300];
    bool resultado = false;
    
    Lista* l = lista_criar();

    // inserção na lista vazia
    lista_inserir(l, 10, 0);

    lista_toString(l, str);
    teste_string(str, "[10]");
    
    // inserção na primeira posição
    lista_inserir(l, 5, 0);
    lista_inserir(l, 3, 0);
    lista_toString(l, str);
    teste_string(str, "[3,5,10]");

    // inserção na última posição
    lista_inserir(l, 40, 3);
    lista_inserir(l, 50, 4);
    lista_toString(l, str);
    teste_string(str, "[3,5,10,40,50]");
    
    // inserção no meio
    lista_inserir(l, 15, 3);
    lista_toString(l, str);
    teste_string(str, "[3,5,10,15,40,50]");
}

void teste_removerPosicao(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR POSICAO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    TipoElemento item;
    char str[300];
  
    // Remoção da primeira posição
    lista_removerPosicao(l, 0, &item);
    lista_toString(l, str);
    teste_int(item, 10); // [PASS] 10
    teste_string(str, "[20,30,40,50]");
 
    // Remoção da última posição
    lista_removerPosicao(l, 3, &item);
    lista_toString(l, str);
    teste_int(item, 50);
    teste_string(str, "[20,30,40]");
 
    // Remoção do meio
    lista_removerPosicao(l, 1, &item);
    lista_toString(l, str);
    teste_int(item, 30);
    teste_string(str, "[20,40]");

    // Remoção da última posição com índice negativo
    lista_removerPosicao(l, -1, &item);    
    lista_toString(l, str);
    teste_int(item, 40);
    teste_string(str, "[20]");

    // Remoção do último elemento
    lista_removerPosicao(l, -1, &item);
    lista_toString(l, str);
    teste_int(item, 20);
    teste_string(str, "[]");

    // Remoção na lista vazia
    bool teste = lista_removerPosicao(l, 0, &item);
    teste_bool(teste, false);
}

void teste_removerElemento(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR ELEMENTO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);
    lista_anexar(l, 40);
    lista_anexar(l, 50);

    int posicao;
    char str[300];


    
    // Remoção de um elemento que não existe    
    posicao = lista_removerElemento(l, 100);
    teste_int(posicao, -1);
    
    // Remoção do elemento da primeira posição
    posicao = lista_removerElemento(l, 10);    
    lista_toString(l, str);
    teste_int(posicao, 0);
    teste_string(str, "[20,30,40,50]");

    // Remoção do elemento da última posição
    posicao = lista_removerElemento(l, 50);
    lista_toString(l, str);
    teste_string(str, "[20,30,40]");
    teste_int(posicao, 3);
    
    
    // Remoção do elemento no meio
    posicao = lista_removerElemento(l, 30);
    lista_toString(l, str);
    teste_int(posicao, 1);
    teste_string(str, "[20,40]");
    

    // Remoção do elemento da última posição
    posicao = lista_removerElemento(l, 40);
    lista_toString(l, str);
    teste_int(posicao, 1);
    teste_string(str, "[20]");
    
    // Remoção do último elemento
    posicao = lista_removerElemento(l, 20);
    lista_toString(l, str);
    teste_int(posicao, 0);
    teste_string(str, "[]");

    // Remoção na lista vazia
    posicao = lista_removerElemento(l, 40);
    teste_int(posicao, -1);
}


int main(){

    teste_anexar();
    teste_inserir();
    teste_removerPosicao();
    teste_removerElemento();

    return 0;
}
