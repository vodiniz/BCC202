//ORDENE CADA PALAVRA UTILIZANDO METODOS DE ORDENACAO
//SE NENHUM METODO FOR APLICADO DURANTE A RESOLUCAO, A QUESTAO SERA INVALIDADA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#define TAM_STR 50

typedef struct{
    char palavra[TAM_STR];
    char ordenado;
} Entrada;


int main(void){

    int test_cases;
    scanf("%d", &test_cases);

    Entrada *entradas = malloc (test_cases * sizeof(Entrada));    
    char palavra[TAM_STR];

    for(int i = 0; i < test_cases; i++){

        scanf("%s", palavra);
        strcpy(entradas[i].palavra, palavra);
        
        mergesort(palavra, 0, strlen(palavra) - 1);

        entradas[i].ordenado = (strcmp(entradas[i].palavra, palavra)) ? 'N' : 'O';

    }

    for(int i = 0; i < test_cases; i++){

        if(entradas[i].ordenado == 'O'){

            int tam_str = strlen(entradas[i].palavra);

            for(int j = 0; j < tam_str - 1; j++){
                if(entradas[i].palavra[j] == entradas[i].palavra[j + 1]){
                    entradas[i].ordenado = 'N';
                    break;
                }
            }


        }

    }

    for(int i = 0; i < test_cases; i++){
        printf("%s: %c\n", entradas[i].palavra, entradas[i].ordenado);
    }

    free(entradas);

    return 0;
}