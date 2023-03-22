#include <stdio.h>

long long int fatorial(int n);




int main(void){

    int m,n;

    while(scanf("%d", &m) != EOF){
        scanf("%d", &n);

        printf("%lld\n", fatorial(m) + fatorial(n));

    }


    return 0;
}


long long int fatorial(int n){

    long long int fatorial = 1;

    for(int i = n; i > 0; i--){
        fatorial *= i;
    }

    return fatorial;
}