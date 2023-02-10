#include "lista.h"
#include <stdlib.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {

    pLista->ultimo->prox =( Celula *) malloc ( sizeof ( Celula ));
    pLista->ultimo = pLista->ultimo->prox ;
    pLista->ultimo->item = item;
    pLista->ultimo->prox = NULL ;

    return true;

}

bool ListaInsereInicio(Lista* pLista, Item item) {

    Celula *aux = ( Celula *) malloc ( sizeof ( Celula ));
    aux->prox = pLista->cabeca->prox;
    aux->item = item;
    pLista->cabeca->prox = aux;

    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    
    if (ListaEhVazia(pLista))
        return false;

    Celula *aux;

    aux = pLista->cabeca->prox;
    *pItem = aux->item;
    pLista->cabeca->prox = aux->prox;

    free(aux);

    return true;
}

void ListaLibera(Lista* pLista) {
    if (ListaEhVazia(pLista)){
        free(pLista->cabeca);
        return;
    }

    Celula *atual = pLista->cabeca->prox;
    Celula *aux = atual;

    while(atual){
        
        aux = atual->prox;
        free(atual);
        atual = aux;
        
    }

    free(pLista->cabeca);
}