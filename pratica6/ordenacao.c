#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int *vetor, int n) {
    vetor = malloc (n * sizeof (int));
    return vetor;
}

int *desalocaVetor(int *vetor) {
    free(vetor);
    return vetor;
}

void trocar(int *x, int *y){
    int swap = *x;
    *x = *y;
    *y = swap;
}

void ordenacao(int *vetor, int n, int *movimentos) {


    for ( int i = 0; i < n; i++){
        for (int j = 1; j < n -i; j++){
            if (vetor[j] < vetor[j - 1]){
                trocar(&vetor[j], &vetor[j - 1]);
                (*movimentos)++;
            }
        }
    }

}

