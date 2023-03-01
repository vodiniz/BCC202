#include <stdio.h>
#include <stdlib.h>





void insertionSort(int arr[], int size, int *counter){
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*counter)++;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(void){

    int test_cases;
    scanf("%d", &test_cases);


    for ( int i = 0; i < test_cases; i++){

        int array_size;
        int counter = 0;

        scanf("%d", &array_size);

        int *array = malloc ( array_size * sizeof(int));

        for ( int i = 0; i < array_size; i++){
            scanf("%d", &array[i]);
        }

        // printArray(array, array_size);

        insertionSort(array, array_size, &counter);

        // printArray(array, array_size);

        printf("Optimal train swapping takes %d swaps.\n", counter);

        free(array);

    }


    return 0;
}


