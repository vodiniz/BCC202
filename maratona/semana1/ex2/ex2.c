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


void TLista_Inicia(TLista *pLista);
int TLista_InsereFinal(TLista *pLista, int x);
void insere_numeros(TLista *pLista, int num);
int TLista_EhVazia(TLista *pLista);
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX);
int Tlista_conta_elementos(TLista *pLista);
void TLista_Esvazia(TLista *pLista);
void imprime_lista(TLista *pLista);


void TLista_Inicia(TLista *pLista) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
}

int TLista_InsereFinal(TLista *pLista, int x) {

    // printf("Inserindo %d no final\n", x);
    pLista->pUltimo->pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista->pUltimo = pLista->pUltimo->pProx ;
    pLista->pUltimo->item.chave = x;
    pLista->pUltimo->pProx = NULL ;


    // printf("\n----LISTA----\n");
    // imprime_lista(pLista);
    // printf("------------\n");

    return 1;

}


void insere_numeros(TLista *pLista, int num){
    
    for ( int i = 1; i <= num ; i++){
        // printf("Inserindo numero %d\n", i);
        TLista_InsereFinal(pLista, i);
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
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;

    free(pAux);

    // printf("retirando %d\n", pX->chave);

    if(pLista->pPrimeiro->pProx == NULL)
        pLista->pUltimo = pLista->pPrimeiro;
        
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


void imprime_lista(TLista *pLista){

    TCelula *atual = pLista->pPrimeiro->pProx;

    while(atual){
        printf("%d ", atual->item.chave);
        atual = atual->pProx;
    }

    printf("\n");

}

int main(void){

    int num;
    TLista lista;
    scanf("%d", &num);
    TItem x;



    // printf("Inicia Main\n");
    while (num){
        // printf("while num\n");
        TLista_Inicia(&lista);
        insere_numeros(&lista, num);
        int elementos = Tlista_conta_elementos(&lista);
        
        // printf("Elementos: %d\n", elementos);


        if (elementos > 1)
            printf("Discarded cards:");

        while(elementos > 1){

            TLista_RetiraPrimeiro(&lista, &x);
            elementos--;
            printf(" %d", x.chave);
            TLista_RetiraPrimeiro(&lista, &x);
            TLista_InsereFinal(&lista, x.chave);

            if (elementos > 1)
                printf(",");

        }

        printf("\n");

        printf("Remaining card: %d\n", lista.pPrimeiro->pProx->item.chave);
        TLista_Esvazia(&lista);

        scanf("%d", &num);
        
    }
    


    return 0;
}