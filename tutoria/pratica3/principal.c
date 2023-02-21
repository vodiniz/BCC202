#include <stdio.h>
#include "ordenacao.h"

int main(){
    
    int upa_numbers;
    TADupa *upas;
    
    scanf("%d", &upa_numbers);
    alocarUpa(&upas, upa_numbers);

    preencheVetor(upas, upa_numbers);
    
    ordenaUpas(upas, upa_numbers);
    imprimeUpas(upas, upa_numbers);


    return 0;
}

