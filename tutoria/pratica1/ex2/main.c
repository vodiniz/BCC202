#include "recursividade.h"

int main(){
    
    TLista lista;
    TItem x;

    TLista_FazVazia(&lista);

    while(scanf("%d", &x.valor) != EOF){
        TLista_Insere(&lista, x);
    }

    printf("%d\n", recursividade(lista.pPrimeiro->pProx));

}