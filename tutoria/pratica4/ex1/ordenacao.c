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
        return 0;
    else if (upa1->emergencia < upa2->emergencia)
        return 1;
    else{
        if(upa1->urgencia > upa2->urgencia)
            return 0;
        else if (upa1->urgencia < upa2->urgencia)
            return 1;
        else{
            if (strcmp(upa1->nome, upa2->nome) > 0)
                return 1;
            else
                return 0;
        }
    }

}



void shellSort(TADupa *upas, int n) {

    if(n == 1){
        return;
    }

	int h = 1; //Inicia com 1
    TADupa aux;
    while( h < n) //Pegando o valor inicial de h
        h = 3 * h + 1;  //Seguindo o método de cálculo do shellSort

    do{

        h = (h - 1)/3; //atualiza o valor de h

        for ( int i = h; i < n;i++){
            aux = upas[i];  //Recebe o objeto para comparação
            int j = i;
            while(comparaUpas(&upas[j - h], &aux)){ //Chama a função de comparar os valores
                upas[j] = upas[j-h]; //Troca as posições
                j = j - h;
                if ( j < h){
                    break; //Interrompe
                }
            }
            upas[j] = aux;
            
        }
    } while ( h != 1); //Repetição enquanto h for diferente de 1
}



void ordenaUpas(TADupa *upas, int n){

    shellSort(upas, n);
    
}



void imprimeUpas(TADupa *upas, int n){
    for(int i = 0; i < n; i++)
        printf("%s %d %d %d %d\n", upas[i].nome,
            upas[i].emergencia,
            upas[i].urgencia,
            upas[i].semEmergencia,
            upas[i].medicos);
    
}

