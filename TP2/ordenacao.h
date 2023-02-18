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

Ponto* alocaPontos (int npontos);
Objeto* alocaObjetos (int npontos, int nobj);
void desalocaPontos (Ponto **pontos);
void desalocaObjetos (Objeto **lista, int nobj);

void lerPontos(Ponto*, int);
void lerObjetos(Objeto *lista, int nobj);

double calcularDistancia (Objeto *objeto);
double calcularDeslocamento (Objeto *objeto);
void realizaCalculos(Objeto *objetos, int nobj);

void mergeSort(Objeto *objetos, int l, int r);
void merge(Objeto *objetos, int l, int m, int r);
int comparaObjeto(Objeto*, Objeto*);

void imprime (Objeto *lista, int nobj);

#endif