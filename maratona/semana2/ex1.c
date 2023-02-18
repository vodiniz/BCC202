#include <stdio.h>
#include <stdlib.h>

int compare(int numero1, int numero2);
void ordena(int *numeros, int n);
void imprime_vetor(int *vetor,int n);



int main(void){


    int n;

    scanf("%d", &n);

    int *vetor = (int*)malloc( n * sizeof(int));

    for( int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
    
    ordena(vetor, n);

    imprime_vetor(vetor, n);
    free(vetor);


    return 0;
}


void imprime_vetor(int *vetor, int n){

    for ( int i = 0; i < n; i++)
        printf("%d\n", vetor[i]);
}


int compare(int numero1, int numero2){


    if (!(numero1 % 2) && !(numero2 % 2)){
        if (numero1 > numero2)
            return 1;
        else 
            return 0;

    } else if (!(numero1 % 2) && (numero2 % 2)){
        return 0;
    } else if ((numero1 % 2) && !(numero2 % 2)){
        return 1;
    } else{
        if (numero1 < numero2)
            return 1;
        else 
            return 0;
    }
    return 0;
}




void ordena(int *numeros, int n) {
	int h = 1;
    int aux;
    while( h < n)
        h = 3 * h + 1;

    do{
        h = (h - 1)/3;

        for ( int i = h; i < n;i++){
            aux = numeros[i]; 
            int j = i;
            while(compare(numeros[j - h], aux) > 0){
                numeros[j] = numeros[j-h];
                j = j - h;
                if ( j < h){
                    break;
                }
            }
            numeros[j] = aux;
            
        }
    } while ( h != 1); 
}
