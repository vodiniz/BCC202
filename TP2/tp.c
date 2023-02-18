#include <stdio.h>
#include "ordenacao.h"

int main(void){

    Objeto *lista;
    int npontos, nobj;

    scanf("%d%d", &nobj, &npontos);

    lista = alocaObjetos(npontos, nobj);
    lerObjetos(lista, nobj);

    // imprime(lista, nobj);

    realizaCalculos(lista, nobj);
    mergesort(lista, 0, npontos - 1, npontos);
    // shellSort(lista, nobj);
    imprime(lista, nobj);
    desalocaObjetos(&lista, nobj);

    return 0;
}