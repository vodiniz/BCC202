#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


void atualiza_times(Time*times, int time1, int pontos1, int time2, int pontos2);

void heap_sort(Time *times, int n);
void heap_constroi (Time *times, int n);
void heap_refaz (Time *times, int esq, int dir);


// Manter como especificado
Time *alocaVetor(int n) {

    Time *times = malloc (n * sizeof(Time));

    for ( int i = 0; i < n; i++){
        times[i].id = i + 1;
        times[i].pontos = 0;
        times[i].vitorias = 0;
        times[i].derrotas = 0;
        times[i].cestas_marcadas = 0;
        times[i].cestas_tomadas = 0;
    }

    return times;
}

// Manter como especificado
void desalocaVetor(Time **vetor) {
    free(*vetor);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Time *vetor, int n) {
    heap_sort(vetor, n);
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2) {

    if (t1.pontos < t2.pontos){
        return 1;
    } else if (t1.pontos > t2.pontos){
        return 0;
    } else {
        
        float saldo_cestas_t1 = (t1.cestas_tomadas) ? 
            ((float) t1.cestas_marcadas)/t1.cestas_tomadas : t1.cestas_marcadas;

        float saldo_cestas_t2 = (t2.cestas_tomadas) ? 
            ((float) t2.cestas_marcadas)/t2.cestas_tomadas : t2.cestas_marcadas;

        if(saldo_cestas_t1 < saldo_cestas_t2)
            return 1;
        else if (saldo_cestas_t1 > saldo_cestas_t2)
            return 0;
        else {

            if (t1.cestas_marcadas < t2.cestas_marcadas)
                return 1;
            else if (t1.cestas_marcadas > t2.cestas_marcadas)
                return 0;
            else {
                if ( t1.id < t2.id)
                    return 0;
                else
                    return 1;
            }
        }
    }
}


void heap_sort(Time *times, int n){

    heap_constroi(times, n);
    
    Time aux;
    while(n > 1){
        
        aux = times[n - 1];
        times[n - 1] = times[0]; // ACHO QUE O PEDRO ESCREVEU ERRADO
        times[0] = aux;
        n--;
        heap_refaz(times, 0, n - 1);
    }

}

void heap_constroi (Time *times, int n){

    int esq = (n / 2) - 1;
    while (esq >= 0){
        heap_refaz(times, esq, n - 1);
        esq--;
    }
}   


void heap_refaz (Time *times, int esq, int dir){

    int i = esq;
    int j = i * 2 + 1;
    Time aux = times[i];

    while(j <= dir){

        if ( j< dir && !compare(times[j], times[j+1]))
            j = j + 1;

        if(compare(aux, times[j]))
            break;
        
        times[i] = times[j];
        i = j;
        j = i * 2 + 1;
    }
    times[i] = aux;

}


void atualiza_times(Time *times, int time1, int pontos1, int time2, int pontos2){

    int index_time1 = time1 - 1;
    int index_time2 = time2 - 1;




    if(pontos1 > pontos2){
        times[index_time1].vitorias++;
        times[index_time1].pontos += 2;
        times[index_time2].derrotas++;
        times[index_time2].pontos += 1;
    } else {
        times[index_time2].vitorias++;
        times[index_time2].pontos += 2;
        times[index_time1].derrotas++;
        times[index_time1].pontos += 1;
    }

    times[index_time1].cestas_marcadas += pontos1;
    // printf("time: %d, pontos %d\n", times[index_time1].id, times[index_time1].cestas_marcadas);
    times[index_time2].cestas_marcadas += pontos2;

    times[index_time1].cestas_tomadas += pontos2;
    // printf("time: %d, pontos %d\n", times[index_time2].id, times[index_time2].cestas_marcadas);

    times[index_time2].cestas_tomadas += pontos1;

}


void imprime_times(Time *times, int n){

    for ( int i = 0; i < n; i++){

        float saldo_cestas = (times[i].cestas_tomadas) ? 
            (float) times[i].cestas_marcadas/times[i].cestas_tomadas : times[i].cestas_marcadas;
        printf("-----Time %d ------\n", times[i].id);
        printf("Pontos: %d \n", times[i].pontos);
        printf("Vitorias: %d \n", times[i].vitorias);
        printf("Derrotas: %d \n", times[i].derrotas);
        printf("Cestas Marcadas: %d \n", times[i].cestas_marcadas);
        printf("Cestas Tomadas: %d \n", times[i].cestas_tomadas);
        printf("Saldo de cestas: %f \n", saldo_cestas);
        printf("-------------\n");
    }

}