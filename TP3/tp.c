#include <stdio.h>
#include "indiceInvertido.h"
#include "hash.h"


int main() {

    int numeroDocumentos;
    scanf("%d", &numeroDocumentos);
    Chave chaves[NN];
    IndiceInvertido indiceInvertido;
    int numeroChaves;
    inicia(indiceInvertido);


    for(int i = 0; i < numeroDocumentos; i++){

        NomeDocumento nomeDocumento;
        scanf("%s ", nomeDocumento);

        numeroChaves = pegarChaves(chaves);
        adicionarChaves(indiceInvertido, chaves, numeroChaves);


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

    return 0;
}
