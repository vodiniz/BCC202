#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int chave ;
} TItem ;

typedef struct cel {
    TItem item ;
    struct cel * pProx ;
} TCelula ;


typedef struct {
    TCelula * pPrimeiro;
    TCelula *pUltimo;
} TLista;


void TLista_Inicia(TLista *pLista) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
}

int TLista_InsereFinal(TLista *pLista, TItem x) {
    pLista->pUltimo->pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL ;

    return 1;

}


void insere_numeros(TLista *pLista, int num){
    
    TItem item;
    for ( int i = 1; i <= num ; num++){
        item.chave = i;
        TLista_InsereFinal(pLista, item);
    }

}


//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return ( pLista -> pPrimeiro->pProx == NULL);
}

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

int Tlista_conta_elementos(TLista *pLista){

    int contador_elementos = 0;
    TCelula *atual = pLista->pPrimeiro->pProx;

    while (atual != NULL){
        contador_elementos++;
        atual = atual->pProx;
    }

    return contador_elementos;
}

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

int main(void){

    int num;
    TLista lista;
    scanf("%d", &num);
    TItem x;



    printf("teste\n");
    while (num){
        TLista_Inicia(&lista);
        insere_numeros(&lista, num);
        int elementos = Tlista_conta_elementos(&lista) > 2;

        if (elementos > 2)
            printf("Discarded cards:");

        while(elementos){

            TLista_RetiraPrimeiro(&lista, &x);
            printf(" %d", x.chave);
            TLista_RetiraPrimeiro(&lista, &x);
            TLista_InsereFinal(&lista, x);

            if (elementos > 3)
                printf(",");

        }

        printf("Remaining card: %d", lista.pPrimeiro->pProx->item.chave);
        TLista_Esvazia(&lista);

        scanf("%d", &num);
        
    }
    


    return 0;
}