#include "r9.h"
#include <stdio.h>

int main(){

    long long num;
    while(scanf("%lld", &num), num){
        
    int soma = soma_r9(num);

    if ( !(soma % 9))
        printf("%lld is a multiple of 9\n", num);
    else 
        printf("%lld is not a multiple of 9\n", num);

    }



}
