#include "indiceInvertido.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inicia a lista copiando 
void inicia(IndiceInvertido indiceInvertido){
    
    for (int i = 0; i < M; i++) {
        // memcpy(indiceInvertido[i].chave, VAZIO, N);
        strcpy(indiceInvertido[i].chave, VAZIO); 
        indiceInvertido[i].n = 0;
    }   
}

//insere um documento baseado na chave no TAD IndiceInvertido.
bool insereDocumento(IndiceInvertido indiceInvertido, Chave chave, NomeDocumento nomeDocumento){

    int indice = h(chave, M); //indice recebe o hash baseado na chave passada por parâmetro e tamanho da tabela 
    if (chaveEhVazia(indiceInvertido[indice].chave)) 
        return false;


    while(strcmp(indiceInvertido[indice % M].chave, chave)){ //faz a comparação entre a chave passada por parâmetro
        indice++;                                           // e a chave presente na tabela do indiceInvertido. Enquanto as chaves forem
                                                            // iguais o indice vai mudando.
        //printf("Loop INFINITO INSERE DOCUMENTO\n");

    }
    
    strcpy(indiceInvertido[indice].documentos[indiceInvertido[indice % M].n++], nomeDocumento);  // quando achar um lugar vazio na tabela/lista vai copiar o nome
                                                                                                // do documento passado como parâmetro para o documento presente no indiceInvertido
    
    return true;
}

//retorna o índice de uma chave passada por parâmetro presente TAD IndiceInvertido, caso não tenha retorna -1
int busca(IndiceInvertido indiceInvertido, Chave chave){
    int j = 0;
    int ini = h(chave, M);

    while (strcmp(indiceInvertido[(ini + j) % M].chave, VAZIO) != 0 && //compara se a
            strcmp(indiceInvertido[(ini + j) % M].chave, chave) != 0 && // compara se a chave do parâmetro e a presente na tabela são diferentes
            j < M) //enquanto j for menor que o tamanho da tabela
        j++; 
    
    if (strcmp(indiceInvertido[(ini + j) % M].chave, chave) == 0) //se as chaves forem iguais retorna a posição na tabela
        return (ini + j) % M;
    
    return -1; //caso não haja correspondencia da chaves retorna -1
}

//baseado em uma ou mais chaves, retorna o nome dos documentos que contêm todas as
//chaves no índice invertido presente no TAD IndiceInvertido.
int consulta(IndiceInvertido indiceInvertido, Chave* chave, int numero_chaves, NomeDocumento* nomeDocumento){

    int documentos_encontrados = 0;
    if(!numero_chaves)
        return 0;

    Item item_base;
    int indice_item_base = busca(indiceInvertido, chave[0]); //recebe a posição da tabela que a chave se escontra

    Item comparar;
    int indice_comparar;

    if(indice_item_base == -1){ //se for -1, condição que diz que não há essa chave a tabela, retorna 0
        // printf("none\n");
        // printf("TESTEEEE\n");
        return 0;
    }


    item_base = indiceInvertido[indice_item_base]; //se estiver na tabela, essa váriavel do tipo Item recebe as informações presentes no indiceInvertido na posição do indice_item_base

    // printf("Item base : %s\n", item_base.chave);
    // for(int i = 0; i < item_base.n; i++)
    //     printf("%s - ", item_base.documentos[i]);
    // printf("\n");

    
    int *vetor_int1 = inicializa_um(item_base.n); //inicializa com 1 o vetor que vai ter tamanho do numero de documentos

    for(int i = 1; i < numero_chaves; i++){
        


        // printf("------LOOP %d --------\n", i);

        int *vetor_int2 = calloc(item_base.n, sizeof(int)); //inicia com 0 o vetor que vai ter tamanho do numero de documentos

        indice_comparar = busca(indiceInvertido, chave[i]); //recebe a posição em que a chave[i] está
        
        if(indice_comparar == -1) //se for -1 passa pro próximo loop
            continue;

        comparar = indiceInvertido[indice_comparar]; //se houver, a variável do tipo Item recebe o que tem no indiceInvertido nessa posição

        // printf("Item comparar : %s\n", comparar.chave);
        // for(int i = 0; i < comparar.n; i++) 
        //     printf("%s - ", comparar.documentos[i]);
        // printf("\n");

        for(int j = 0 ; j < item_base.n; j++){
            for(int k = 0; k < comparar.n; k++){
                if(!strcmp(item_base.documentos[j], comparar.documentos[k])){ //
                    vetor_int2[j] = 1;
                    
                }
            }
        }
        
        // imprime_vetor(vetor_int1, item_base.n);
        // imprime_vetor(vetor_int2, item_base.n);


        for(int j = 0; j < item_base.n;j++)
            vetor_int1[j] = vetor_int2[j];

        free(vetor_int2);

        // printf("---------------\n");
        

        if(vetor_tudo_zero(vetor_int1, item_base.n)){ //passa tudo que tem no vetor1 para 0
            // printf("none\n");
            free(vetor_int1); //desaloca
            return 0;
        }

    }


    // imprime_vetor(vetor_int1, item_base.n);


    for(int i = 0 ; i < item_base.n; i++){

        if(vetor_int1[i]){
            strcpy(nomeDocumento[documentos_encontrados++], item_base.documentos[i]); //copia o que tem no item_base para o nome do documentos na posição documentos_encontrados
        }                                                                              //que inicialmente era 0
    }

    return documentos_encontrados; //retorna a quantidade de documentos encontrados que tem a chave que foi buscada
    
}

//imprime os documentos do indiceInvertido presente no TAD IndiceInvertido.
void imprime(IndiceInvertido indiceInvertido){
    
    for( int i = 0; i < M; i++){

        if(chaveEhVazia(indiceInvertido[i].chave)) //se a chave for vazia vai pro próximo laço
            continue;

        printf("%s", indiceInvertido[i].chave); //imprime a chave
        printf(" - ");

        for( int j = 0; j < indiceInvertido[i].n; j++){//e os documentos que possuem cada chave
            if ( j <  indiceInvertido[i].n - 1) 
                printf("%s ", indiceInvertido[i].documentos[j]);
            else
                printf("%s", indiceInvertido[i].documentos[j]);
        }

        printf("\n");

    }

}

//void sort(NomeDocumento* nomeDocumento, int qtdDocumentos);

//adiciona chaves na tabela
void adicionarChaves(IndiceInvertido indiceInvertido, Chave *chaves, int qtdChaves, int *contador){


    for (int i = 0; i < qtdChaves; i++){

        bool chaveDuplicada = false; //varíavel pra verificar se a chave já foi inserida anteriormente

        int indice = h(chaves[i], M); 
        
        while(!chaveEhVazia(indiceInvertido[indice % M].chave)){

            if(!strcmp(indiceInvertido[indice % M].chave, chaves[i])){
                chaveDuplicada = true;
                break;
            }

            indice++;
            (*contador)++;
        }

        if(chaveDuplicada)
            continue;

        strcpy(indiceInvertido[indice % M].chave, chaves[i]);
    }

    
}

//verifica se a chave é vazia
int chaveEhVazia(Chave chave){

    if(!strcmp(chave, VAZIO))
        return 1;

    return 0;
}

//inicia o vetor com 1
int *inicializa_um(int n){

    int *vetor = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        vetor[i] = 1;

    return vetor;
}

int vetor_tudo_zero(int *vetor, int n){
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += vetor[i];
        if(soma >= 1)
            return 0; 
    }

    return 1;
}

//imprime o vetor
void imprime_vetor(int *vetor, int n){
    printf("[ ");
    for(int i = 0; i < n;i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

//ordenação
void mergeSort(NomeDocumento *documentos, int l, int r){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(documentos,l,m);
        mergeSort(documentos, m+1, r);
        merge(documentos, l, m, r);
    }
}

void merge(NomeDocumento *documentos, int l, int m, int r){
    int size_l = (m - l + 1);
    int size_r = r - m;
    int i, j;

    NomeDocumento *vet_l =  malloc(size_l * sizeof(NomeDocumento));
    NomeDocumento *vet_r =  malloc(size_r * sizeof(NomeDocumento));

    for (i = 0; i < size_l; i++)
    {
       strcpy(vet_l[i], documentos[i+l]);
    }
    for (j = 0; j < size_r; j++)
    {
        strcpy(vet_r[j], documentos[m + j + 1]);
    }
    i = 0; j = 0;
    for (int k = l; k <= r; k++)
    {
        if (i == size_l)
        {
            strcpy(documentos[k], vet_r[j++]);
            //documentos[k] = vet_r[j++];
        }
        else if (j == size_r)
        {
            strcpy(documentos[k], vet_l[i++]);
            //documentos[k] = vet_l[i++];
        }
        else if (compare(vet_l[i],vet_r[j]))
        {
            strcpy(documentos[k], vet_l[i++]);
            //documentos[k] = vet_l[i++];
        }
        else{
            strcpy(documentos[k], vet_r[j++]);
            //documentos[k] = vet_r[j++];
        }
    }
    free(vet_l);
    free(vet_r);
}


//comparação
int compare(const NomeDocumento documento1, const NomeDocumento documento2) {

    if(strcmp(documento1, documento2) < 0)
        return 1;
    else
        return 0;
}