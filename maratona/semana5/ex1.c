#include <stdio.h>
#include <stdlib.h>


void sort(int *vetor, int n, int *swaps);
void swap(int *x, int *y);

int main(void){

    int instance_number;
    scanf("%d", &instance_number);

    for (int i = 0; i < instance_number; i++){

        int sequence_number;
        scanf("%d", &sequence_number);

        int swaps = 0;

        int *vetor = malloc ( sequence_number * sizeof(int));

        for ( int i = 0; i < sequence_number; i++)
            scanf("%d", &vetor[i]);
        
        sort(vetor, sequence_number, &swaps);
        printf("%d\n", swaps);
        free(vetor);
    }



    return 0;
}



void sort(int *vetor, int n, int *swaps){

    for(int i = 0; i < n; i++){
        
        int min = i;
        for ( int j = i + 1; j < n; j++){
            if (vetor[j] < vetor[min])
                min = j;
        }

        swap(&vetor[i], &vetor[min]);
        if(i != min)
            (*swaps)++;
        
    }
}



void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}
