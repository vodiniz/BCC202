#include <stdio.h>
#include "ordenacao.h"

int main(void){

    Objeto *lista; //Cria a lista do tipo Objeto
    int npontos, nobj;

    validaEntrada(&nobj, &npontos);
    lista = alocaObjetos(nobj, npontos); //Lista recebe sua alocação



    if (lista ==NULL){
        printf("Falha na alocação do vetor. Saindo do programa");
        return 0;
    }
    lerObjetos(lista, nobj); //Chama a função e leitura das informações de cada objeto


    realizaCalculos(lista, nobj); //Realiza todos os cálculos necessários
    mergesort(lista, 0, nobj - 1, npontos); //Chama o método de ordenção
    // shellSort(lista, nobj);
    imprime(lista, nobj); //Imprime as informações
    desalocaObjetos(&lista, nobj); //Desaloca toda memória reservada

    return 0;
}