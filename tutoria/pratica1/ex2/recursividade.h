#ifndef RECURSIVIDADE
#define RECURSIVIDADE

# define MAXTAM 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} TItem ;

typedef struct celula {
    struct celula *pProx ;
    TItem item;
} TCelula;

typedef struct {
    TCelula *pPrimeiro, *pUltimo;
} TLista ;

void TLista_FazVazia ( TLista * pLista );
int recursividade(TCelula* celula);
int TLista_Insere ( TLista * pLista , TItem x);

#endif