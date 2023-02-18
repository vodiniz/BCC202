#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[32];
    int quantidade;
} Arvore;

int compare(const char* aluno1, const char* aluno2) {

    if (strcmp(aluno1, aluno2) > 0)
        return 1;
    else
        return 0;
}

void increment_or_add(Arvore *arvores, int *n, char* nome){

    int is_on_array = 0;

    for ( int i = 0; i < *n; i++){
        if (!strcmp(arvores[i].nome, nome)){
            is_on_array = 1;
            arvores[i].quantidade++;
            return;
        }
    }

    if (!is_on_array){
        strcpy(arvores[*n].nome, nome);
        arvores[*n].quantidade = 1;
        (*n)++;
    }
}



void imprimeVetor(Arvore *arvores, int n, int totalArvores){

    for ( int i = 0; i < n; i++){
        printf("%s %.4f\n", arvores[i].nome, (float) ((float) arvores[i].quantidade/totalArvores) * 100);
    }

}




int main(void){

    int n;
    char nome[32];
    Arvore arvores[10000];
    scanf("%d", &n);
    getchar();
    getchar();

    for ( int i = 0; i < n; i++){

        int index = 0;
        int total_arvores = 0;

        fgets(nome,32, stdin);

        while(strcmp(nome, "\n") > 0){

            total_arvores++;
            nome[strlen(nome) - 1] = '\0';
            increment_or_add(arvores, &index, nome);

            if (fgets(nome, 32, stdin) == NULL){
                break;
            }

        }

        printf("\n");
        qsort(arvores, index, sizeof(Arvore), (int(*)(const void*, const void*)) compare);
        imprimeVetor(arvores, index, total_arvores);


    }

    return 0;
}