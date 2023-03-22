#ifndef HASH_ABERTO
#define HASH_ABERTO

#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Os cabeçalhos de todas as funções e os TADs podem ser alterados */

#define VAZIO " !!!!!!!!!!!!!!!!!!!!\0 "




typedef struct {
    int n; // numero de documentos
    Chave chave;
    NomeDocumento documentos[ND];
} Item;

typedef Item IndiceInvertido[M];



/* Funções */ 
// void alocaIndice(IndiceInvertido);
// void desalocaIndice(IndiceInvertido);
void inicia(IndiceInvertido); //ok
bool insereDocumento(IndiceInvertido, Chave, NomeDocumento);
int busca(IndiceInvertido, Chave); 
int consulta(IndiceInvertido, Chave*, int, NomeDocumento*);
void imprime(IndiceInvertido);

//void sort(NomeDocumento*, int);


void adicionarChaves(IndiceInvertido, Chave*, int, int*);
int chaveEhVazia(Chave);


int *inicializa_um(int n);
int vetor_tudo_zero(int *vetor, int n);
void imprime_vetor(int *vetor, int n);


void mergeSort(NomeDocumento *, int l, int r);
void merge(NomeDocumento *, int l, int m, int r);
int compare(const NomeDocumento documento1, const NomeDocumento documento2);






#endif // !HASH_ABERTO
