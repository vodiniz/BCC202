#include <stdio.h>
#include <string.h>
#include "lista.h"
#define TAM 100000

int main(){
        
    TLista lista;
    char str[TAM], c;

    

    TLista_Inicia(&lista);
    TCelula *cursor;


   


    while (fgets(str, TAM, stdin) != NULL){

        str[strcspn(str, "\n")] = 0;
        int contador = 0;
        c = str[contador];
        int insere_cursor = 0;
    
        while(c != '\0'){

            if ( c == '['){
                cursor = lista.pPrimeiro;
                insere_cursor = 1;

            } else if ( c == ']'){
                insere_cursor = 0;;
            } else {
                if(!insere_cursor){

                    TLista_Insere_Fim(&lista, c);
                    // printf("Inserindo no fim:\t %c\n", c);
                }
            
                else
                    if(TLista_Insere_Cursor(&lista, cursor, c)){
                        // printf("Inserindo no cursor ( %c )\t %c\n", cursor->item.letra, c);
                        cursor = cursor->pProx;
                    }

            }

            contador++;
            c = str[contador];
        }

        TLista_Imprime(&lista);
        TLista_Esvazia(&lista);
        TLista_Inicia(&lista);

    }




    return 0;
}