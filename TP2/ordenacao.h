#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdbool.h>

#define TAM_ID 5
#define precision 0.00657271


typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    char ID[TAM_ID];
    Ponto *pontos;
    int npontos;
    double distancia;
    double deslocamento;
}Objeto;

void validaEntrada(int *numero_objetos, int *numero_pontos);

Ponto* alocaPontos (int npontos);
Objeto* alocaObjetos (int npontos, int nobj);
void desalocaPontos (Ponto *pontos);
void desalocaObjetos (Objeto **lista, int nobj);

void lerPontos(Ponto*, int);
void lerObjetos(Objeto *lista, int nobj);

double calcularDistancia (Objeto *objeto);
double calcularDeslocamento (Objeto *objeto);
void realizaCalculos(Objeto *objetos, int nobj);

void mergesort(Objeto *objetos, int l, int r, int npontos);
void merge(Objeto *objetos, int l, int m, int r, int npontos);

void shellSort(Objeto *objetos, int n);

int comparaObjeto(Objeto*, Objeto*);
bool approximatelyEqual(double a, double b);
bool definitelyGreaterThan(double a, double b);
bool definitelyLessThan(double a, double b);

void imprime (Objeto *lista, int nobj);

#endif