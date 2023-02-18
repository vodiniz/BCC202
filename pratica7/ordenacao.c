#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	int h = 1;
    Aluno aux;
    while( h < n)
        h = 3 * h + 1;

    do{

        h = (h - 1)/3;

        for ( int i = h; i < n;i++){
            aux = alunos[i]; 
            int j = i;
            while(compare(alunos[j - h].nome, aux.nome) > 0){
                alunos[j] = alunos[j-h];
                j = j - h;
                if ( j < h){
                    break;
                }
            }
            alunos[j] = aux;
            
        }
    } while ( h != 1); 
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {

    // printf("Comparando %s e %s\n", aluno1, aluno2);

    int compare = strcmp(aluno1, aluno2);

    if(compare == 0){
        // printf("retornei 0\n");
        return 0;
    } else if (compare > 0){
        // printf("retornei 1\n");
        return 1;
    } else {
        // printf("retornei -1\n");
        return -1;
    }
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    if ( k < n)
        printf("%s\n", alunos[n - k].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno *alunos = (Aluno*) malloc(n * sizeof(Aluno));
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for(int i = 0; i < n; i++){
        scanf("%s", alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d%d", n, k);
}

void imprimeTodos(Aluno* aluno, int n){
    for( int i = 0; i < n; i++){
        printf("%s\n", aluno[i].nome);
    }

}
