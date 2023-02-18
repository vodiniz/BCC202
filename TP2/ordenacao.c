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

    Objeto* lista = (Objeto*)malloc(nobj * sizeof(Objeto));

    for (int i = 0; i < nobj; i++){

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
    
    printf("NOBJETO: %d\n",nobj);
    for(int i = 0; i < nobj; i++){
        //conferir aritimetica de ponteiros
        desalocaPontos(&((*lista)[i].pontos));
        printf("I: %d\n", i);
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
    double distancia = 0;
    for(int i = 0; i < objeto->npontos - 1; i++){
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
    
    if(l < r){
        int m = (l + r)/2;
        mergeSort(objetos, l, m);
        mergeSort(objetos, m + 1, r);
        merge(objetos, l, m, r);
    }
}

void merge(Objeto *objetos, int l, int m, int r){

    int size_l = (m - l + 1);
    int size_r = (r - m);

    Objeto *objetosL = alocaObjetos(objetos->npontos, size_l);
    Objeto *objetosR = alocaObjetos(objetos->npontos, size_r);

    int j, i ;



    for (i = 0; i < size_l; i++){
        objetosL[i] = objetos[i + l];
    }
    for ( j = 0; j < size_r; j++)
    {
        objetosR[j] = objetos[m + j + 1];
    }

    i = 0;
    j = 0;

    for (int k = l; k <= r; k++)
    {
        if (i == size_l)
        {
            objetos[k] = objetosR[j++];
        }
        else if (j == size_r)
        {
            objetos[k] = objetosL[i++];
        }
        else if (comparaObjeto(&objetosL[i], &objetosR[j]))
        {
            objetos[k] = objetosL[i++];
        } 
        else {
            objetos[k] = objetosR[j++];
        }
         
    }
    
//     printf("------------DESALOCANDO L NO MERGE----------\n");
    // desalocaObjetos(&objetosL, size_l );
//     printf("---------------------------------------------\n");

//     printf("------------DESALOCANDO R NO MERGE----------\n");
    // desalocaObjetos(&objetosR, size_r);
//     printf("---------------------------------------------\n");

}

int comparaObjeto(Objeto *objeto1, Objeto *objeto2){


    //perigoso comparar doubles, ficar esperto 
    if (objeto1->distancia > objeto2->distancia){
        printf("%lf > %lf\n", objeto1->distancia, objeto2->distancia);
        return 1;
        
    } else if (objeto1->distancia < objeto2->distancia){
        printf("%lf < %lf\n", objeto1->distancia, objeto2->distancia);
        return 0;
    } else {

        printf("%lf == %lf\n", objeto1->distancia, objeto2->distancia);
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