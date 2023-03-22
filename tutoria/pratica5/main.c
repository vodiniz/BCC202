#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ordenacao.h"


int main(void){

    int n;
    char cor[TAM_STR];
    char tamanho;
    Camiseta *camisetas;
    scanf("%d", &n);
    getchar();



    while(n){

        camisetas = malloc(n * sizeof(Camiseta));

        for(int i = 0; i < n; i++){

            fgets(camisetas[i].estudante, TAM_STR, stdin);
            camisetas[i].estudante[strcspn(camisetas[i].estudante, "\n")] = 0;
            // printf("|%s|\n", camisetas[i].estudante);
            scanf("%s %c", &camisetas[i].cor_logo, &camisetas[i].tamanho_camiseta);
            getchar();
            // printf("|%s| |%c|\n", camisetas[i].cor_logo, camisetas[i].tamanho_camiseta);

        }

        heap_sort(camisetas,n);
        imprime_camisetas(camisetas, n);
        // printf("O VALOR DE N  É : %d\n", n);

        scanf("%d", &n);
        getchar();
        
        free(camisetas);
    }


    return 0;
}