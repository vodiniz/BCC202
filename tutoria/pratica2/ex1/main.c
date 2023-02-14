#include <stdio.h>
#include "f91.h"

int main (){

    int num;
    while(scanf("%d", &num), num){
        printf("f91(%d) = %d\n", num, f91(num));
    }

    
    
}