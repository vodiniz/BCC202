#include <stdio.h>
#define MAX_TAM 30

int selection_sort(char *v, int n);
void trocar(char *x, char *y);

int main(void){

    int n;
    int string_tam;
    char string[MAX_TAM];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++){
        scanf("%d", &string_tam);
        scanf("%s", string);

        if(selection_sort(string, string_tam) <= 1)
            printf("There are the chance.\n");
        else
            printf("There aren't the chance.\n");

    }


    return 0;
}


int selection_sort(char *v, int n){

    int trocas = 0;

    for (int i = 0; i < n; i++){
        
        int min = i;
        for ( int j = i + 1; j < n; j++){
            if (v[j] < v[min])
                min = j;
        }

        if( i != min){
            trocar(&v[i], &v[min]);
            trocas++;
        }

    }

    return trocas;
}


void trocar(char *x, char *y){
    char aux = *x;
    *x = *y;
    *y = aux;
}
