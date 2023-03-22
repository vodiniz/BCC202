#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[21];
    int validade;
} Carne;

int compare(const Carne *carne1, const Carne *carne2);

int main(void){

    int n;

    while(scanf("%d", &n) != EOF){

        Carne *carnes = malloc(n * sizeof(Carne));

        for(int i = 0; i < n; i++){
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }

        qsort(carnes, n, sizeof(Carne),(int(*)(const void*, const void*)) compare);

        for(int i = 0; i < n;i++){
            if( i < n - 1)
                printf("%s ", carnes[i].nome);
            else
                printf("%s\n", carnes[i].nome);
        }


    }



    return 0;
}

int compare(const Carne *carne1, const Carne *carne2){
    if (carne1->validade < carne2->validade)
        return 0;
    return 1;
}