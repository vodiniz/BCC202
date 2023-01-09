#ifndef AUTOMATO_H
#define AUTOMATO_H

typedef struct automatoCelular AutomatoCelular;

void lerDimensao(int *);

AutomatoCelular **alocarReticulado(int);

void desalocarReticulado(AutomatoCelular***, int);

void leituraReticulado(AutomatoCelular**, int);

AutomatoCelular **evoluirReticulado(AutomatoCelular**, int);

void imprimeReticulado(AutomatoCelular**, int );

AutomatoCelular **copiaAutomato(AutomatoCelular**, int);


#endif