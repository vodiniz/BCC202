#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
    
}

int TLista_Insere ( TLista * pLista , TItem x) {

    pLista->pUltimo->pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL ;

    return 1;
    
}

int recursividade(TCelula* celula){

    if (celula == NULL)
        return 0;
    else 
        return celula->item.valor + recursividade(celula->pProx);
}