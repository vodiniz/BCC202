#include <stdio.h>
#include <time.h>

#include "indiceInvertido.h"
#include "hash.h"



int main() {

    int numeroDocumentos;
    scanf("%d", &numeroDocumentos);
    Chave chaves[NN];
    IndiceInvertido indiceInvertido;
    int numeroChaves;
    int contador_colisoes = 0;
    inicia(indiceInvertido);


    for(int i = 0; i < numeroDocumentos; i++){

        NomeDocumento nomeDocumento;
        scanf("%s ", nomeDocumento);

        numeroChaves = pegarChaves(chaves);
        adicionarChaves(indiceInvertido, chaves, numeroChaves, &contador_colisoes);


        for(int j = 0; j < numeroChaves; j++)
            insereDocumento(indiceInvertido, chaves[j], nomeDocumento);

    }


    char opcao;
    scanf("%c", &opcao);

    int documentos_encontrados;
    NomeDocumento documentos[ND];

    switch (opcao){
        case 'I':
            imprime(indiceInvertido);
            break;
        
        case 'B':
            
            
            numeroChaves = pegarChaves(chaves);
            documentos_encontrados = consulta(indiceInvertido, chaves, numeroChaves,documentos);
            
            mergeSort(documentos, 0, documentos_encontrados-1);
            // printf("---------------\n");
            if( documentos_encontrados == 0){
                printf("none\n");
            }

            else{
                for(int i = 0; i < documentos_encontrados; i++){
                    printf("%s\n", documentos[i]);
                }
            // printf("---------------\n");
            }

            break;

        }



    // printf("%d\n", contador_colisoes);
    // printf("%f\n",(float)clock() / CLOCKS_PER_SEC);
    printf("Consumo de memória: %d bytes\n", M * (sizeof(Item) + ND * sizeof(NomeDocumento)));
    return 0;
}
