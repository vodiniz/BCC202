#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;

}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return ( pLista -> pPrimeiro == pLista -> pUltimo );
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    pLista->pUltimo->pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL ;

    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if (TLista_EhVazia(pLista))
        return 0;

    TCelula *pAux;

    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux ->item;
    pLista->pPrimeiro->pProx = pAux->pProx;

    free(pAux);

    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {

    if (TLista_EhVazia(pLista))
        return;

    TCelula *atual = pLista->pPrimeiro->pProx;
    while(atual != NULL){
        printf("%s ", atual->item.nome);
        atual = atual->pProx;
    }
    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {

    //cuidado se a lista for vazia. ????

    TCelula *atual = pLista->pPrimeiro->pProx;
    TCelula *aux = atual;

    while(atual){
        
        aux = atual->pProx;
        free(atual);
        atual = aux;
        
    }

    free(pLista->pPrimeiro);


}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){

    TCelula *pAux = pLista1->pUltimo;


    pAux->pProx = pLista2->pPrimeiro->pProx;

    while(pAux->pProx != NULL){
        pAux = pAux->pProx;
    }

    pLista1->pUltimo = pAux;

    free(pLista2->pPrimeiro);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){


    TCelula *pAux = pLista1->pPrimeiro;
    TCelula *pAuxStr;


    while(strcmp(str, pAux->pProx->item.nome)){

        pAux = pAux->pProx;
    }



    pAuxStr = pAux->pProx;

    pAux -> pProx = pLista2->pPrimeiro->pProx;

    while (pAux->pProx != NULL){
        pAux = pAux ->pProx;
    }
    
    pAux->pProx = pAuxStr;

    free(pLista2->pPrimeiro);


}

void insere_cursor(TLista *pLista, TCelula celula){




}
