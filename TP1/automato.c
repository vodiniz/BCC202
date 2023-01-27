
#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    MORTO = 0,
    VIVO = 1
} VIDA;

struct automatoCelular
{
    VIDA vida;
};

void lerDimensao(int *dimensao)
{
    scanf("%d", dimensao);
}

AutomatoCelular **alocarReticulado(int dimensao)
{
    AutomatoCelular **automatoCelular = malloc(dimensao * sizeof(AutomatoCelular *));

    for (int i = 0; i < dimensao; i++)
    {
        automatoCelular[i] = malloc(dimensao * sizeof(AutomatoCelular));
    }

    return automatoCelular;
}

void desalocarReticulado(AutomatoCelular ***automatoCelular, int dimensao)
{
    for (int i = 0; i < dimensao; i++)
    {
        free((*automatoCelular)[i]);
    }
    free(*automatoCelular);
}

void leituraReticulado(AutomatoCelular **automatoCelular, int dimensao)
{
    int vidaReticulado;

    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &vidaReticulado);
            automatoCelular[i][j].vida = vidaReticulado;
        }
    }
}



AutomatoCelular **evoluirReticulado(AutomatoCelular **automatoCelular, int dimensao)
{

    AutomatoCelular **CopiaAutomatoCelular;
    CopiaAutomatoCelular = copiaAutomato(automatoCelular, dimensao);

    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {

            int contadorCelular = 0;
            int x0 = i - 1;
            int y0 = j - 1;
            int xf = i + 1;
            int yf = j + 1;

            
            if (x0 < 0) 
                x0 = 0;

            if (y0 < 0) 
                y0 = 0;

            if(xf >= dimensao)
                xf = dimensao - 1;

            if(yf >= dimensao)
                yf = dimensao - 1;

            for (int k = x0; k <= xf; k++)
            {
                for (int l = y0; l <= yf; l++)
                {
                    if (!(k == i && l == j))
                    {
                        // printf("checando a celula[%d][%d] = %d\n",k, j, automatoCelular[k][l].vida);
                        if (CopiaAutomatoCelular[k][l].vida == VIVO)
                        {
                            contadorCelular++;
                        }
                    }
                }
            }

            // celula renasce
            if (automatoCelular[i][j].vida == MORTO && contadorCelular == 3)
            {
                automatoCelular[i][j].vida = VIVO;
            } // solidão
            else if (automatoCelular[i][j].vida == VIVO && contadorCelular < 2)
            {
                automatoCelular[i][j].vida = MORTO;
            } // continua viva
            else if (automatoCelular[i][j].vida == VIVO && (contadorCelular == 2  || contadorCelular == 3))
            {
                automatoCelular[i][j].vida = VIVO;
            } //sufocamento
            else if (automatoCelular[i][j].vida == VIVO && contadorCelular > 3)
            {
                automatoCelular[i][j].vida = MORTO;
            }

        }
    }



    desalocarReticulado(&CopiaAutomatoCelular, dimensao);
    return automatoCelular;
}


void imprimeReticulado(AutomatoCelular **automatoCelular, int dimensao)
{
    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {
            printf("%d ", automatoCelular[i][j].vida);
        }
        printf("\n");
    }
}

AutomatoCelular **copiaAutomato(AutomatoCelular **automatoCelular, int dimensao){


    AutomatoCelular **copia;
    copia = alocarReticulado(dimensao);

    for(int i = 0; i < dimensao; i++){
        for(int j = 0; j < dimensao; j++){
            copia[i][j].vida = automatoCelular[i][j].vida; 
        }
    }

    return copia;

}
