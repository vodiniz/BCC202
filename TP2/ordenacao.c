#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"


void validaEntrada(int *numero_objetos, int *numero_pontos){
    
    //Recebe a quantidade de objetos e de pontos que eles possuem
    scanf("%d %d", numero_objetos, numero_pontos); //Recebe a quantidade de objetos e de pontos que eles possuem


    while(*numero_objetos <= 0 || *numero_pontos <= 0 ){
        printf("O numero de entrada para pontos e objetos é inválido. Por favor digite novamente.\n");
        scanf("%d %d", numero_objetos, numero_pontos); //Recebe a quantidade de objetos e de pontos que eles possuem
    }

}


//Alocação dinâmica dos pontos do objeto   '
Ponto* alocaPontos (int npontos){

    Ponto *pontos = (Ponto*)malloc(npontos * sizeof(Ponto)); //Aloca o ponteiro com o espaço de número de pontos vezes o tamanho do tipo Ponto
    
    return pontos;
}

//Alocação dinâmica dos objetos que também chama a função de alocar pontos
Objeto* alocaObjetos (int nobj, int npontos ){

    Objeto* objetos = (Objeto*)malloc(nobj * sizeof(Objeto));

    for (int i = 0; i < nobj; i++){ 

        objetos[i].npontos = npontos; //Cada objeto receberá o numero de pontos que foi passado
        objetos[i].pontos = alocaPontos(npontos); //Aloca os pontos de cada objeto

        objetos[i].deslocamento = 0; //Zera o deslocamento de cada objeto
        objetos[i].distancia = 0; //Zera a distância de cada objeto

    }
    
    return objetos;
}

//Liberando o espaço alocado para os pontos
void desalocaPontos (Ponto *pontos){
    free(pontos); //Libera o ponteiro de pontos
}

//Liberando o espaço alocado para os objetos e chamando a função de liberar pontos
void desalocaObjetos(Objeto **lista, int nobj){
    for(int i = 0; i < nobj; i++){ //Repetição para percorrer todo o número de objetos
        desalocaPontos((*lista)[i].pontos); //Desalocando os pontos de cada objeto
    }
    free(*lista); //Desalocando a lista
}

//Lendo e armazenando os pontos e suas coordenadas
void lerPontos(Ponto* pontos, int npontos){
    for (int i = 0; i < npontos; i++){ //Repetição para a leitura de cada cordenada de cada ponto
        scanf("%d", &pontos[i].x); //Cordenada x
        scanf("%d", &pontos[i].y); //Cordenada y
    }
}

//Lendo os objetos e chamando a função de ler pontos
void lerObjetos(Objeto *lista, int nobj){
    for(int i = 0; i < nobj; i++){ //Repetição para ler todos os objetos
        scanf("%s", lista[i].ID); //Leitura do ID da lista
        lerPontos(lista[i].pontos, lista->npontos); //Chamando a função de ler pontos para cada objeto
    }
    
}

//Realiza o calculo da distânica entre os números de ponto
double calcularDistancia (Objeto *objeto){
    double distancia = 0; // Inicia distancia com zero
    for(int i = 0; i < objeto->npontos - 1; i++){
        distancia += sqrt(pow((objeto->pontos[i+1].x - objeto->pontos[i].x), 2) 
        + pow((objeto->pontos[i+1].y - objeto->pontos[i].y), 2));
    }
    return distancia ;
}

//Calcula o deslocamento total dos pontos
double calcularDeslocamento (Objeto *objeto){
    return sqrt(pow((objeto->pontos[objeto->npontos-1].x - objeto->pontos[0].x), 2) 
    + pow((objeto->pontos[objeto->npontos-1].y - objeto->pontos[0].y), 2)); //Retorna o resultado do cálculo de deslocamento
}

//Chama as funções de cálculo de distância e deslocamento para cada objeto
void realizaCalculos(Objeto *objetos, int nobj){
    for (int i = 0; i < nobj; i++) //Repetição para percorrer cada objeto
    {
        objetos[i].distancia = calcularDistancia(&objetos[i]); //Chama a função de calcular a distância para cada objeto
        objetos[i].deslocamento = calcularDeslocamento(&objetos[i]); //Chama a função de calcular o deslocamento para cada objeto
    }
    
}

//Método de ordenação mergesort
void mergesort(Objeto *v, int l, int r, int npontos){
    if (l < r){
        int m = (l + r)/2; //M recebe o meio do vetor
        mergesort(v, l, m, npontos); //Recursividade para continuar dividindo o vetor em metades
        mergesort(v, m + 1, r, npontos); //Dividindo a outra metade do vetor
        merge(v, l, m, r, npontos); //Chama a implementação de conquista do método de ordenação

    }
}

//Implementação do mergesort
void merge(Objeto *v, int l, int m, int r, int npontos){

    int size_l = (m - l + 1); //Recebe o tamanho do vetor da esquerda
    int size_r = (r - m); //Recebe o tamanho do vetor da direita


    /*Na atribuição entre duas structs o contéudo do ponteiro referente aos pontos 
    não é copiado, apenas o ponteiro é copiado
    A solução foi ao invés de chamar a função de alocar objetos, alocar manualente outros vetores
    para não alocarmos um outro espaço de pontos, pois podemos usar apenas o seu ponteiro.
    Quanto a liberação, se usássemos a função dos objetos, um double free ocorreria, ocasionando problemas*/


    Objeto *vet_l = malloc( size_l * sizeof(Objeto));
    Objeto *vet_r = malloc( size_r * sizeof(Objeto));

    //copiando os elemntos do vetores principais para os sub elementos
    for (int i = 0; i < size_l; i++)
        vet_l[i] = v[i + l]; 


    for (int j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    //Inicializando variáveis de controle com zero
    int i = 0; 
    int j = 0; 

    for (int k = l; k <= r; k++){

        // printf("Comparando %s e %s\n", vet_l[i].ID, vet_r[j].ID);

        if (i == size_l)
            v[k] = vet_r[j++]; //se i for igual o tamanho do vetor da esquerda, j irá ser inserido e acrescentado, passando para o próximo indice
        
        else if (j == size_r)
            v[k] = vet_l[i++]; //se j for igual o tamanho do vetor da direita, i irá ser inserido e acrescentado, passando para o próximo indice

        else if (comparaObjeto(&vet_l[i], &vet_r[j])){
            v[k] = vet_r[j++]; //j irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da esquerda
            // printf("Objeto %s maior que %s\n",v[k].ID, vet_l[i].ID);
        }
        else{
            v[k] = vet_l[i++]; //i irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da direita
            // printf("Objeto %s menor que %s\n",vet_r[j].ID, v[k].ID);

        }
    }

    //Liberando os vetores da direita e da esquerda alocados
    free(vet_l);
    free(vet_r);

}


//Método de ordenação shellSort
void shellSort(Objeto *objetos, int n) {

    if(n == 1){
        return;
    }

	int h = 1; //Inicia com 1
    Objeto aux;
    while( h < n) //Pegando o valor inicial de h
        h = 3 * h + 1;  //Seguindo o método de cálculo do shellSort

    do{

        h = (h - 1)/3; //atualiza o valor de h

        for ( int i = h; i < n;i++){
            aux = objetos[i];  //Recebe o objeto para comparação
            int j = i;
            while(comparaObjeto(&objetos[j - h], &aux)){ //Chama a função de comparar os valores
                objetos[j] = objetos[j-h]; //Troca as posições
                j = j - h;
                if ( j < h){
                    break; //Interrompe
                }
            }
            objetos[j] = aux;
            
        }
    } while ( h != 1); //Repetição enquanto h for diferente de 1
}


bool approximatelyEqual(double a, double b){
    return fabs(a - b) <= precision;
}

bool definitelyGreaterThan(double a, double b){
    return (a - b) > precision;
}

bool definitelyLessThan(double a, double b){
    return (b - a) > precision;
}


//Compara os objetos da lista para a ordenação dos mesmos seguindo os parametros indicados pelo professor
// e tomando cuidado ao comparar 2 variaveis do tipo double

int comparaObjeto(Objeto *objeto1, Objeto *objeto2){

    if (definitelyGreaterThan(objeto1->distancia, objeto2->distancia)){ //Se for maior, retorna zero
        return 0;
        
    } else if (definitelyLessThan(objeto1->distancia, objeto2->distancia)){
        return 1; //Se for menor, retorna 1
    } else {

        if (definitelyGreaterThan(objeto1->deslocamento, objeto2->deslocamento)) {
            return 1; //Se for maior, retorna zero

        } else if(definitelyLessThan(objeto1->deslocamento, objeto2->deslocamento)){
            return 0;
        } else{
            if(strcmp(objeto1->ID, objeto2->ID) > 0){
                return 1; //Se for menor, retorna 1
            } else {
                return 0;
            }
        }
        
    }
}

//Imprime os intens da lista com o resultado de deslocamento e distância
void imprime (Objeto *lista, int nobj){
    for(int i = 0; i < nobj; i++){ //Repetição para percorrer cada objeto
        // printf("%s %lf %lf\n", lista[i].ID, lista[i].distancia,lista[i].deslocamento); //Imprime todas as informações de cada item da lista
        printf("%s %0.2lf %0.2lf\n", lista[i].ID, lista[i].distancia,lista[i].deslocamento); //Imprime todas as informações de cada item da lista

    }
}