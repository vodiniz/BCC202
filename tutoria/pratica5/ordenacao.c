#include <stdio.h>
#include <string.h>
#include "ordenacao.h"

void heap_sort(Camiseta *camisetas, int n){

    heap_constroi(camisetas, n);
    
    Camiseta aux;
    while(n > 1){
        
        aux = camisetas[n - 1];
        camisetas[n - 1] = camisetas[0];
        camisetas[0] = aux;
        n--;
        heap_refaz(camisetas, 0, n - 1);
    }

}

void heap_constroi (Camiseta *camisetas, int n){

    int esq = (n / 2) - 1;
    while (esq >= 0){
        heap_refaz(camisetas, esq, n - 1);
        esq--;
    }
}   


void heap_refaz (Camiseta *camisetas, int esq, int dir){

    int i = esq;
    int j = i * 2 + 1;
    Camiseta aux = camisetas[i];

    while(j <= dir){

        if ( j < dir && compare(&camisetas[j], &camisetas[j+1]))
            j ++;

        if(!compare(&aux, &camisetas[j]))
            break;
        
        camisetas[i] = camisetas[j];
        i = j;
        j = i * 2 + 1;
    }
    camisetas[i] = aux;

}



int compare(Camiseta *camiseta1, Camiseta *camiseta2){

    if(strcmp(camiseta1->cor_logo, camiseta2->cor_logo) < 0)
        return 1;

    else if(strcmp(camiseta1->cor_logo, camiseta2->cor_logo) > 0)
        return 0;

    else {
        if (camiseta1->tamanho_camiseta > camiseta2->tamanho_camiseta)
            return 1;

        else if (camiseta1->tamanho_camiseta < camiseta2->tamanho_camiseta)
            return 0;

        else {
            if(strcmp(camiseta1->estudante, camiseta2->estudante) < 0)
                return 1;
            else
                return 0;
        }
        
    
    }
    
    return 0;
}



void imprime_camisetas(Camiseta *camisetas, int n){
    for (int i = 0; i < n; i++){
        printf("%s %c %s\n", camisetas[i].cor_logo,camisetas[i].tamanho_camiseta, camisetas[i].estudante);
    }
}
