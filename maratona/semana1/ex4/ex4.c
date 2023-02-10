#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numero ;
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
int TLista_EhVazia(TLista *pLista);
int TLista_Insere_Inicio ( TLista * pLista , int x);
int TLista_RetiraPrimeiro(TLista *pLista);
void TLista_Esvazia(TLista *pLista);
void imprime_lista(TLista *pLista);
int TLista_menor(TLista *pLista);
int TLista_InsereFinal(TLista *pLista, TItem x);


void TLista_Inicia(TLista *pLista) {

    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return ( pLista -> pPrimeiro->pProx == NULL);
}


int TLista_Insere_Inicio ( TLista * pLista , int x){
    
    TCelula *aux = ( TCelula *) malloc ( sizeof ( TCelula ));
    aux->pProx = pLista->pPrimeiro->pProx;
    aux->item.numero = x;
    pLista->pPrimeiro->pProx = aux;
    
    return 1;
}


int TLista_RetiraPrimeiro(TLista *pLista) {
    if (TLista_EhVazia(pLista))
        return 0;

    TCelula *pAux;

    pAux = pLista->pPrimeiro->pProx;
    pLista->pPrimeiro->pProx = pAux->pProx;

    free(pAux);

    // printf("retirando %d\n", pX->chave);

    if(pLista->pPrimeiro->pProx == NULL)
        pLista->pUltimo = pLista->pPrimeiro;
        
    return 1;
}

int TLista_menor(TLista *pLista){

    if (TLista_EhVazia(pLista))
        return -1;

    TCelula *aux = pLista->pPrimeiro->pProx;
    int menor_presente = aux->item.numero;

    while(aux){
        if (aux->item.numero < menor_presente)
            menor_presente = aux->item.numero;
        aux = aux->pProx;
    }

    return menor_presente;

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
        printf("%d ", atual->item.numero);
        atual = atual->pProx;
    }

    printf("\n");

}

int main(void){

    int num, menor_presente;
    TLista pilha;
    char str[30];
    char* token;


    scanf("%d", &num);
    getchar();
    

    

    TLista_Inicia(&pilha);

    for ( int i = 0; i < num; i++){

        // printf("LOOP %d\n", i);
        //le a primeira linha
        fgets (str, 30, stdin);
        //remove o \n incluido pelo fgets
        str[strcspn(str, "\n")] = 0;

        //tokenizacao da string original, divide em strings delimitadas por espaco em branco

        if (!strcmp(str, "MIN")){

            // printf("----PILHA-----\n");
            // imprime_lista(&pilha);
            // printf("----PILHA-----");
            menor_presente = TLista_menor(&pilha);


            if (menor_presente >= 0)
                printf("%d\n", menor_presente);
            else
                printf("EMPTY\n");



        } else if (!strcmp(str, "POP")){

            if(TLista_EhVazia(&pilha))
                printf("EMPTY\n");
            else
                TLista_RetiraPrimeiro(&pilha);

        } else {
            
            token = strtok(str, " ");
            if (!strcmp(token, "PUSH")){
    	        token = strtok(NULL, " ");
                TLista_Insere_Inicio(&pilha, atoi(token));
            }
        }
    }


    return 0;
}