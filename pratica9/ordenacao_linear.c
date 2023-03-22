#include "ordenacao_linear.h"

#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

// Manter como especificado
void le(Paciente* pacientes, int n) {
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */

    for (int i = 0; i < n; i++){
        scanf("%s %s", pacientes[i].senha, pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    for (int i = 0; i < n; i++){
        printf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
    }
}

// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i) {
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */
    int *C = calloc(10 , sizeof(int));

    for (int j = 0; j < n;j++){
        C[char2int(A[j].senha[i])]++;
    }


    for(int j = 1; j < 10; j++){
        C[j] = C[j] + C[j - 1];
    }


    for (int j = n - 1 ; j >= 0; j--){
        B[C[char2int(A[j].senha[i])] - 1] = A[j] ;
        // printf("B[%d] = A[%d]\n", C[char2int(A[j].senha[i])], j);
        C[char2int(A[j].senha[i])] = C[char2int(A[j].senha[i])] - 1;
    }

    free(C);

}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];
    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */

    
    for (int i = m - 1; i >= 0; i--){
        // printf("----------Counting Digit %d\n", i);
        coutingSort(pacientes, B, n, i);
        // printf("---------------\n");

        for( int j = 0; j < n; j++)
            pacientes[j] = B[j];
    
    }




}
// 
