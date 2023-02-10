#include "fila.h"
#include "pilha.h"

bool FilaInicia(Fila* pFila) {
    return(ListaInicia(pFila));
}

bool FilaEnfileira(Fila* pFila, Item item) {
    return(ListaInsereFinal(pFila, item));
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    return(ListaRetiraPrimeiro(pFila, pItem));
}

bool FilaEhVazia(Fila* pFila) {
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    ListaLibera(pFila);
}

bool FilaInverte(Fila* pFila) {

    Pilha pilha;
    PilhaInicia(&pilha);

    Celula *atual = pFila->cabeca->prox;

    while(atual){

        PilhaPush(&pilha, atual->item);
        atual = atual->prox;
    }

    FilaLibera(pFila);
    FilaInicia(pFila);
    
    pFila->cabeca->prox = pilha.cabeca->prox;
    pFila->ultimo = pilha.ultimo;

    PilhaLibera(&pilha);

    return true;
}
