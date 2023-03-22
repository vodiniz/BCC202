#include <stdio.h>
#include "ordenacao.h"

int main(){
    
    TADupa *upas;
    int upa_numbers;
    
    scanf("%d", &upa_numbers);
    alocarUpa(&upas, upa_numbers);

    preencheVetor(upas, upa_numbers);
    
    ordenaUpas(upas, upa_numbers);
    imprimeUpas(upas, upa_numbers);


    return 0;
    return 0;
}

