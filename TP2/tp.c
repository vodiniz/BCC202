#include <stdio.h>
#include "ordenacao.h"

int main(void){

    Objeto *lista; //Cria a lista do tipo Objeto
    int npontos, nobj;

    scanf("%d%d", &nobj, &npontos); //Recebe a quantidade de objetos e de pontos que eles possuem

    lista = alocaObjetos(npontos, nobj); //Lista recebe sua alocação
    lerObjetos(lista, nobj); //Chama a função e leitura das informações de cada objeto


    realizaCalculos(lista, nobj); //Realiza todos os cálculos necessários
    mergesort(lista, 0, nobj - 1, npontos); //Chama o método de ordenção
    // shellSort(lista, nobj);
    imprime(lista, nobj); //Imprime as informações
    desalocaObjetos(&lista, nobj); //Desaloca toda memória reservada

    return 0;
}