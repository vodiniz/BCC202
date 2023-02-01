#include <stdio.h>
#include "lista.h"
#define TAM 100000

int main(){
        
    TLista lista;
    char str[TAM], c;
    int insere = 1;


    

    TLista_Inicia(&lista);


   


    while (scanf("%s",str) != EOF){
        int start_bracket_index = 0;
        int end_bracket_index = 0;
        int contador = 0;
        int insere = 1;
        c = str[contador];
        while(c != '\0'){

            if ( c == '['){

                start_bracket_index = contador;
                insere = 0;

            } else if ( c == ']'){
                end_bracket_index = contador;
                insere = 1;

                for ( int i = end_bracket_index - 1; i > start_bracket_index; i--)
                    TLista_Insere_Inicio(&lista, str[i]);

                start_bracket_index = 0;
                end_bracket_index = 0;

            } else {
                if (insere)
                    TLista_Insere_Fim(&lista, str[contador]);
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