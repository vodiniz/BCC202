#include <stdio.h>
#include <stdlib.h>


void merge(int *v, int l, int m, int r){

    int size_l = (m - l + 1);
    // printf("sizeof l: %d\n", size_l);
    int size_r = (r - m);
    // printf("sizeof r: %d\n", size_r);
    
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

void mergesort(int *v, int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);

    }
}



void read_array(int *array, int n){

    for ( int i = 0; i < n; i++)
        scanf("%d", &array[i]);
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        if (i < size - 1)
            printf("%d ", arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("\n");
}




int main(void){


    int test_cases;

    scanf("%d", &test_cases);

    for ( int i = 0; i < test_cases; i++){

        int array_size;
        scanf("%d", &array_size);

        int *array = malloc(array_size * sizeof(int));

        read_array(array, array_size);

        mergesort(array, 0, array_size - 1);

        printArray(array, array_size);

    }



    return 0;
}
