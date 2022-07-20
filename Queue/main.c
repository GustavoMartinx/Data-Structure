#include <stdio.h>
#include <string.h>

#include "fila.h"

#define ERRO "***ERRO***"

int main(){

    
    char str[200];
    TipoElemento elemento;


    /**************************************
    * Teste insercao e primeiro
    **************************************/
    Fila* f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_toString(f1, str);
    printf("----- Teste Insercao -----\n");
    printf("%s\n", strcmp(str, "[10,20,30]")==0 ? "[OK]" : ERRO);
    

    printf("----- Teste Primeiro -----\n");
    fila_primeiro(f1, &elemento);
    printf("%s\n", elemento == 10 ? "[OK]" : ERRO);    

    /**************************************
    * Teste remocao
    **************************************/
    printf("----- Teste Remocao -----\n");
    fila_remover(f1, &elemento);
    printf("%s\n", elemento == 10 ? "[OK]" : ERRO); 
    
    fila_remover(f1, &elemento);
    printf("%s\n", elemento == 20 ? "[OK]" : ERRO);
    
    fila_remover(f1, &elemento);
    printf("%s\n", elemento == 30 ? "[OK]" : ERRO);
    
    bool resultado = fila_remover(f1, &elemento);
    printf("%s\n", resultado == false ? "[OK]" : ERRO);

    printf("----- Teste toString fila vazia -----\n");
    fila_toString(f1, str);
    printf("%s\n", strcmp(str, "[]")==0 ? "[OK]" : ERRO);
    

    // fila_destruir(&f1);

}