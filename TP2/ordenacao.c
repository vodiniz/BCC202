#include <stdio.h>sqrt(pow())
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

int alocaPontos (Objeto *lista, int npontos, int nobj){
    lista = (Objeto*)malloc(sizeof(Objeto) * nobj);

    for(int i = 0; i < nobj; i++){
        lista[i].npontos = npontos;
        lista[i].pontos = (Ponto*)malloc(sizeof(Ponto) * npontos);
    }
    
    return 1;
}

void desalocaPontos (Objeto *lista, int nobj){
    
    for(int i = 0; i < nobj; i++){
        free(lista[i].pontos);
    }
    free(lista);
}

double calcularDistancia (Objeto *objeto){
    float distancia = 0;
    for(int i = 0; i < objeto->npontos - 1; i++){
        distancia += sqrt(pow((objeto->pontos[objeto[i+1]].x - objeto->pontos[i].x), 2) 
        + pow((objeto->pontos[i+1].y - objeto->pontos[i].y), 2));
    }
    return distancia ;
}

double calcularDeslocamento (Objeto *objeto){
    return sqrt(pow((objeto->pontos[objeto->npontos-1].x - objeto->pontos[0].x), 2) 
    + pow((objeto->pontos[objeto->npontos-1].y - objeto->pontos[0].y), 2));
}

void imprime (Objeto *lista, int nobj){
    for(int i = 0; i < nobj; i++){
        printf("%s %.2lf %.2lf\n", lista[i].ID, lista[i].distancia,lista[i].deslocamento);
    }
}