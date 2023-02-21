#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#define STR_LENGHT 50

struct upa{
    char nome[STR_LENGHT];
    int emergencia;
    int urgencia;
    int semEmergencia;
    int medicos;
};

int alocarUpa (TADupa **aux,int n){

    *aux = malloc(n * sizeof(TADupa));

    if (*aux == NULL) 
        return 0;
    

    return 1;
}

void desalocaUpas(TADupa **aux){
    free(*aux);
}


void preencheVetor(TADupa *upas, int n){

    for ( int i = 0; i < n; i++){

        scanf("%s", upas[i].nome);
        scanf("%d", &upas[i].emergencia);
        scanf("%d", &upas[i].urgencia);
        scanf("%d", &upas[i].semEmergencia);
        scanf("%d", &upas[i].medicos);
    }

}

int comparaUpas(TADupa *upa1, TADupa *upa2){

    if (upa1->emergencia > upa2->emergencia)
        return 1;
    else if (upa1->emergencia < upa2->emergencia)
        return 0;
    else{
        if(upa1->urgencia > upa2->urgencia)
            return 1;
        else if (upa1->urgencia < upa2->urgencia)
            return 0;
        else{
            if (strcmp(upa1->nome, upa2->nome) > 0)
                return 0;
            else
                return 1;
        }
    }

}


void merge(TADupa *v, int l, int m, int r){

    int size_l = (m - l + 1); //Recebe o tamanho do vetor da esquerda
    int size_r = (r - m); //Recebe o tamanho do vetor da direita

    TADupa *vet_l, *vet_r;

    alocarUpa(&vet_l, size_l);
    alocarUpa(&vet_r, size_r);


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

        else if (comparaUpas(&vet_l[i], &vet_r[j]))
            v[k] = vet_l[i++]; //i irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da direita

        else
            v[k] = vet_r[j++]; //j irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da esquerda
    }

    //Liberando os vetores da direita e da esquerda alocados
    desalocaUpas(&vet_l);
    desalocaUpas(&vet_r);

}


void mergesort(TADupa *v, int l, int r){
    if (l < r){
        int m = (l + r)/2; //M recebe o meio do vetor
        mergesort(v, l, m); //Recursividade para continuar dividindo o vetor em metades
        mergesort(v, m + 1, r); //Dividindo a outra metade do vetor
        merge(v, l, m, r); //Chama a implementação de conquista do método de ordenação

    }
}



void ordenaUpas(TADupa *upas, int n){

    mergesort(upas, 0, n - 1);
    
}



void imprimeUpas(TADupa *upas, int n){
    for(int i = 0; i < n; i++)
        printf("%s %d %d %d %d\n", upas[i].nome,
            upas[i].emergencia,
            upas[i].urgencia,
            upas[i].semEmergencia,
            upas[i].medicos);
    
}

