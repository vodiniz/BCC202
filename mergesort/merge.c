#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

void mergesort(int *v, int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);

    }
}


void merge(int *v, int l, int m, int r){

    int size_l = (m - l + 1);
    printf("sizeof l: %d\n", size_l);
    int size_r = (r - m);
    printf("sizeof r: %d\n", size_r);
    
    int *vet_l = (int*) malloc (size_l * sizeof(int));
    int *vet_r = (int*) malloc (size_r * sizeof(int));

    int i,j;
    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    for (j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
         
        if (i == size_l)
            v[k] = vet_r[j++];
        
        else if (j == size_r)
            v[k] = vet_l[i++];

        else if (vet_l[i] <= vet_r[j])
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }

    free(vet_l);
    free(vet_r);

}