#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main(){
    int dimensao;
    AutomatoCelular **automatoCelular;

    lerDimensao(&dimensao);
    automatoCelular = alocarReticulado(dimensao);
    leituraReticulado(automatoCelular, dimensao);
    automatoCelular = evoluirReticulado(automatoCelular, dimensao);
    imprimeReticulado(automatoCelular, dimensao);
    desalocarReticulado(&automatoCelular, dimensao);

    return 0;
}