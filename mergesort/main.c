#include <stdio.h>
#include "merge.h"



int main(void){

    int vetor[] = {5,7,1,3,8,9,6,2,4};

    mergesort(vetor, 0, 9);

    for(int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);

    printf("\n");


    return 0;
}