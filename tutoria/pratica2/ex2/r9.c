#include "r9.h"

int soma_r9(long long n){

    if ( n < 10){
        return n;
    }
    
    return n % 10 + soma_r9(n/10);
    
}