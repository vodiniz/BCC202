#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 11


void swap(char *x, char *y);
void permute(char* string, int left, int right);
void PrintSortedPermutations(char* inStr);
int compare (const void * a, const void * b);


int main(void){

    int test_cases;
    scanf("%d", &test_cases);
    char string[MAX_TAM];

    for( int i = 0; i < test_cases; i++){
        scanf("%s", string);
        PrintSortedPermutations(string);
        printf("\n");
    }


    return 0;
}



void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char* a, int l, int r){
    int i;
    if (l == r)
        printf("%s\n", a);
    else {
        for (i = l; i <= r; i++) {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
        }
    }
}



void PrintSortedPermutations(char* inStr){
    // Re-implementation of algorithm described here:
    // http://www.geeksforgeeks.org/lexicographic-permutations-of-string/
    int strSize = strlen(inStr);
    // 0. Ensure input container is sorted
    qsort(inStr, strSize, sizeof(char), compare);


    int largerPermFound = 1;
    do{
        // 1. Print next permutation
        printf("%s\n", inStr);
        // 2. Find rightmost char that is smaller than char to its right
        int i;
        for (i = strSize - 2; i >= 0 && inStr[i] >= inStr[i+1]; --i){}

        // if we couldn't find one, we're finished, else we can swap somewhere
        if (i > -1)
        {
            // 3 find character at index j such that 
            // inStr[j] = min(inStr[k]) && inStr[k] > inStr[i] for all k > i
            int j = i+1;
            int k;
            for(k=j;k<strSize && inStr[k];++k)
            {
                if (inStr[k] > inStr[i] && inStr[k] < inStr[j])
                    j = k;
            }

            // 3. Swap chars at i and j
            swap(&inStr[i], &inStr[j]);

            // 4. Sort string to the right of i
            qsort(inStr+i+1, strSize-i-1, sizeof(char), compare);
        }
        else
        {
            largerPermFound = 0;
        }
    }while(largerPermFound);
}

int compare (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}