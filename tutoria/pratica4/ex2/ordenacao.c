#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




void merge(char *v, int l, int m, int r){

    int size_l = (m - l + 1); //Recebe o tamanho do vetor da esquerda
    int size_r = (r - m); //Recebe o tamanho do vetor da direita

    char *vet_l = malloc( size_l * sizeof(char));
    char *vet_r = malloc( size_r * sizeof(char));

    for (int i = 0; i < size_l; i++)
        vet_l[i] = v[i + l]; 


    for (int j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    //Inicializando variáveis de controle com zero
    int i = 0; 
    int j = 0; 

    for (int k = l; k <= r; k++){
         
        if (i == size_l)
            v[k] = vet_r[j++]; //se i for igual o tamanho do vetor da esquerda, j irá ser inserido e acrescentado, passando para o próximo indice
        
        else if (j == size_r)
            v[k] = vet_l[i++]; //se j for igual o tamanho do vetor da direita, i irá ser inserido e acrescentado, passando para o próximo indice

        else if (tolower(vet_l[i]) < tolower(vet_r[j]))
            v[k] = vet_l[i++]; //i irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da direita

        else
            v[k] = vet_r[j++]; //j irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da esquerda
    }

    //Liberando os vetores da direita e da esquerda alocados
    free(vet_l);
    free(vet_r);

}


void mergesort(char*v, int l, int r){
    if (l < r){
        int m = (l + r)/2; //M recebe o meio do vetor
        mergesort(v, l, m); //Recursividade para continuar dividindo o vetor em metades
        mergesort(v, m + 1, r); //Dividindo a outra metade do vetor
        merge(v, l, m, r); //Chama a implementação de conquista do método de ordenação

    }
}


