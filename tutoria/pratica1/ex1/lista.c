#include "lista.h"

void TLista_Inicia (TLista * pLista ) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;

}

int TLista_EhVazia ( TLista * pLista ) {
    return ( pLista -> pPrimeiro == pLista -> pUltimo );
}

int TLista_Insere_Fim ( TLista * pLista , char x) {

    pLista->pUltimo->pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item.letra = x;
    pLista -> pUltimo -> pProx = NULL ;

    return 1;
}

int TLista_Insere_Inicio ( TLista * pLista , char x){
    
    TCelula *aux = ( TCelula *) malloc ( sizeof ( TCelula ));
    aux->pProx = pLista->pPrimeiro->pProx;
    aux->item.letra = x;
    pLista->pPrimeiro->pProx = aux;
    
    return 1;
}

void TLista_Esvazia (TLista * pLista){
    
    TCelula *atual = pLista->pPrimeiro->pProx;
    TCelula *aux = atual;

    while(atual){
        
        aux = atual->pProx;
        free(atual);
        atual = aux;
        
    }

    free(pLista->pPrimeiro);
}

void TLista_Imprime ( TLista * pLista ){
    

    if (TLista_EhVazia(pLista))
        return;

    TCelula *atual = pLista->pPrimeiro->pProx;

    while(atual != NULL){
        printf("%c", atual->item.letra);
        atual = atual->pProx;
    }
    printf("\n");

}
