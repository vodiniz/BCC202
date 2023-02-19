#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"
#include "compare_double.h"



//TALVEZ DIVIDIR EM DUAS FUNÇÕES PARA ALOCAR
//PENSAR SOBRE

Ponto* alocaPontos (int npontos){

    Ponto *pontos = (Ponto*)malloc(npontos * sizeof(Ponto));

    return pontos;
}

Objeto* alocaObjetos (int npontos, int nobj){

    Objeto* objetos = (Objeto*)malloc(nobj * sizeof(Objeto));

    for (int i = 0; i < nobj; i++){

        objetos[i].npontos = npontos;
        objetos[i].pontos = alocaPontos(npontos);

        objetos[i].deslocamento = 0;
        objetos[i].distancia = 0;

    }
    
    return objetos;
}


void desalocaPontos (Ponto *pontos){
    free(pontos);
}

void desalocaObjetos(Objeto **lista, int nobj){
    

    printf("-------------------DESALOCA------------\n");
    for(int i = 0; i < nobj; i++){
        desalocaPontos((*lista)[i].pontos);
        printf("I: %d\n", i);
    }
    printf("-------------------------------\n");
    free(*lista);
}


void lerPontos(Ponto* pontos, int npontos){
    for (int i = 0; i < npontos; i++){
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

void mergesort(Objeto *v, int l, int r, int npontos){
    if (l < r){
        printf("ODIO PROFUNDO\n");
        int m = (l + r)/2;
        mergesort(v, l, m, npontos);
        mergesort(v, m + 1, r, npontos);
        merge(v, l, m, r, npontos);


    }
}

void merge(Objeto *v, int l, int m, int r, int npontos){

    int size_l = (m - l + 1);
    printf("sizeof l: %d\n", size_l);

    int size_r = (r - m);
    printf("sizeof r: %d\n", size_r);
    

    Objeto *vet_l;
    
    Objeto *vet_r;

    vet_l = alocaObjetos(npontos, size_l);
    vet_r = alocaObjetos(npontos, size_r);


    int i,j;
    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    printf("---------VET L------\n");
    imprime(vet_l, size_l);
    printf("---------------\n");


    for (j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    i = 0; 
    j = 0;

    printf("---------VET R------\n");
    imprime(vet_r, size_r);
    printf("---------------\n");


    for (int k = l; k <= r; k++){
         
        if (i == size_l)
            v[k] = vet_r[j++];
        
        else if (j == size_r)
            v[k] = vet_l[i++];

        else if (comparaObjeto(&vet_l[i], &vet_r[j]))
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }

    // desalocaObjetos(&vet_l,size_l);
    // desalocaObjetos(&vet_r,size_r);

}

void shellSort(Objeto *objetos, int n) {
	int h = 1;
    Objeto aux;
    while( h < n)
        h = 3 * h + 1;

    do{

        h = (h - 1)/3;

        for ( int i = h; i < n;i++){
            aux = objetos[i]; 
            int j = i;
            while(comparaObjeto(&objetos[j - h], &aux)){
                objetos[j] = objetos[j-h];
                j = j - h;
                if ( j < h){
                    break;
                }
            }
            objetos[j] = aux;
            
        }
    } while ( h != 1); 
}

int comparaObjeto(Objeto *objeto1, Objeto *objeto2){

    if (definitelyGreaterThan(objeto1->distancia, objeto2->distancia)){
        return 0;
        
    } else if (definitelyLessThan(objeto1->distancia, objeto2->distancia)){
        return 1;
    } else {

        if (definitelyGreaterThan(objeto1->deslocamento, objeto2->deslocamento)) {
            return 1;

        } else if(definitelyLessThan(objeto1->deslocamento, objeto2->deslocamento)){
            return 0;
        } else{
            if(strcmp(objeto1->ID, objeto2->ID) > 0){
                return 1;
            } else {
                return 0;
            }
        }
        
    }
}


int comparaObjetoMerge(Objeto *objeto1, Objeto *objeto2){

    if (definitelyGreaterThan(objeto1->distancia, objeto2->distancia)){
        return 1;
        
    } else if (definitelyLessThan(objeto1->distancia, objeto2->distancia)){
        return 0;
    } else {

        if (definitelyGreaterThan(objeto1->deslocamento, objeto2->deslocamento)) {
            return 1;

        } else if(definitelyLessThan(objeto1->deslocamento, objeto2->deslocamento)){
            return 0;
        } else{
            if(strcmp(objeto1->ID, objeto2->ID) > 0){
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