#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"



//TALVEZ DIVIDIR EM DUAS FUNÇÕES PARA ALOCAR
//PENSAR SOBRE

Ponto* alocaPontos (int npontos){

    Ponto *pontos = (Ponto*)malloc(npontos * sizeof(Ponto));
    return pontos;
}

Objeto* alocaObjetos (int npontos, int nobj){

    
    Objeto* lista = (Objeto*)malloc(sizeof(Objeto) * nobj);
    for (int i = 0; i < nobj; i++)
    {
        lista[i].npontos = npontos;
        lista[i].pontos = alocaPontos(npontos);
        lista[i].deslocamento = 0;
        lista[i].distancia = 0;

    }
    
    return lista;
}


void desalocaPontos (Ponto **pontos){
    free(*pontos);
}

void desalocaObjetos(Objeto **lista, int nobj){
    
    for(int i = 0; i < nobj; i++){
        //conferir aritimetica de ponteiros
        desalocaPontos(&(lista[i]->pontos));
    }
    free(*lista);
}


void lerPontos(Ponto* pontos, int npontos){
    for (int i = 0; i < npontos; i++)
    {
        scanf("%d", &pontos[i].x);
        scanf("%d", &pontos[i].y);
    }
}


void lerObjetos(Objeto *lista, int nobj){
    for(int i = 0; i < nobj; i++){
        scanf("%s", lista[i].ID);
        lerPontos(lista[i].pontos, lista->npontos);
    }
    
}

double calcularDistancia (Objeto *objeto){
    float distancia = 0;
    for(int i = 0; i < objeto->npontos; i++){
        distancia += sqrt(pow((objeto->pontos[i+1].x - objeto->pontos[i].x), 2) 
        + pow((objeto->pontos[i+1].y - objeto->pontos[i].y), 2));
    }
    return distancia ;
}

double calcularDeslocamento (Objeto *objeto){
    return sqrt(pow((objeto->pontos[objeto->npontos-1].x - objeto->pontos[0].x), 2) 
    + pow((objeto->pontos[objeto->npontos-1].y - objeto->pontos[0].y), 2));
}

void realizaCalculos(Objeto *objetos, int nobj){
    for (int i = 0; i < nobj; i++)
    {
        objetos[i].distancia = calcularDistancia(&objetos[i]);
        objetos[i].deslocamento = calcularDeslocamento(&objetos[i]);
    }
    
}

void mergeSort(Objeto *objetos, int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        mergeSort(objetos, l, m);
        mergeSort(objetos, m + 1, r);
        merge(objetos, l, m, r);
    }
}

void merge(Objeto *objetos, int l, int m, int r){
    Objeto *objetoL, *objetoR;
    int j = 0, i = 0;
    int size_l = (m - l + 1);
    int size_r = (r - m);

    //separar em 2 funções diferentes para alocar.
    objetoL = alocaObjetos(objetos->npontos, size_l);
    objetoR = alocaObjetos(objetos->npontos, size_r);

    for (; i < size_l; i++)
    {
        objetoL[i] = objetos[i + l];
    }
    for (; j < size_r; j++)
    {
        objetoR[j] = objetos[m + j + 1];
    }

    i = 0;
    j = 0;

    for (int k = l; k <= r; k++)
    {
        if (i == size_l)
        {
            objetos[k] = objetoR[j++];
        }
        else if (j == size_r)
        {
            objetos[k] = objetoL[i++];
        }
        else if (comparaObjeto(&objetoL[i], &objetoR[j]))
        {
            objetos[k] = objetoL[i++];
        } 
        else {
            objetos[k] = objetoL[j++];
        }
         
    }
    
    desalocaObjetos(&objetoL, size_l);
    desalocaObjetos(&objetoR, size_r);
}

int comparaObjeto(Objeto *objeto1, Objeto *objeto2){


    //perigoso comparar doubles, ficar esperto 
    if (objeto1->distancia > objeto2->distancia)
    {
        return 1;
        
    } else if (objeto1->distancia < objeto2->distancia){
        return 0;
    } else {
        if (objeto1->deslocamento > objeto2->deslocamento)
        {
            return 1;
        } else if(objeto1->deslocamento < objeto2->deslocamento){
            return 0;
        }
        else{
            if(strcmp(objeto1->ID, objeto2->ID) < 0){
                return 1;
            } else {
                return 0;
            }
        }
        
    }
}


void imprime (Objeto *lista, int nobj){
    for(int i = 0; i < nobj; i++){
        printf("%s %.2lf %.2lf\n", lista[i].ID, lista[i].distancia,lista[i].deslocamento);
    }
}