#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    char ID[5];
    Ponto *pontos;
    int npontos;
    double distancia;
    double deslocamento;
}Objeto;

int alocaPontos (Objeto *lista, int npontos, int nobj);
void desalocaPontos (Objeto *lista, int nobj);
double calcularDistancia (Objeto *objeto);
double calcularDeslocamento (Objeto *objeto);
void ordena ();
void imprime (Objeto *lista, int nobj);

#endif