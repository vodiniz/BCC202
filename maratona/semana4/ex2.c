#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100


typedef struct {
    char name[21];
    int friend;
    int name_lenght;
    int id;

} Application;



int compare_applications (Application* person1, Application* person2){

    if (person1->friend > person2->friend)
        return 1;
    else if (person2->friend > person1->friend)
        return 0;
    else{
        int str_compare = strcmp(person1->name, person2->name);

        if (str_compare < 0)
            return 1;
        else
            return 0;
    }

}



//Implementação do mergesort
void merge(Application *v, int l, int m, int r){

    int size_l = (m - l + 1); //Recebe o tamanho do vetor da esquerda
    int size_r = (r - m); //Recebe o tamanho do vetor da direita

    Application *vet_l = malloc( size_l * sizeof(Application));
    Application *vet_r = malloc( size_r * sizeof(Application));

    //copiando os elemntos do vetores principais para os sub elementos
    for (int i = 0; i < size_l; i++)
        vet_l[i] = v[i + l]; 


    for (int j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    //Inicializando variáveis de controle com zero
    int i = 0; 
    int j = 0; 

    for (int k = l; k <= r; k++){
         
        if (i == size_l)
            v[k] = vet_r[j++]; //se i for igual o tamanho do vetor da esquerda, j irá ser inserido e acrescentado, passando para o próximo indice
        
        else if (j == size_r)
            v[k] = vet_l[i++]; //se j for igual o tamanho do vetor da direita, i irá ser inserido e acrescentado, passando para o próximo indice

        else if (compare_applications(&vet_l[i], &vet_r[j]))
            v[k] = vet_l[i++]; //i irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da direita

        else
            v[k] = vet_r[j++]; //j irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da esquerda
    }

    //Liberando os vetores da direita e da esquerda alocados
    free(vet_l);
    free(vet_r);

}

//Método de ordenação mergesort
void mergesort(Application *v, int l, int r){
    if (l < r){
        int m = (l + r)/2; //M recebe o meio do vetor
        mergesort(v, l, m); //Recursividade para continuar dividindo o vetor em metades
        mergesort(v, m + 1, r); //Dividindo a outra metade do vetor
        merge(v, l, m, r); //Chama a implementação de conquista do método de ordenação

    }
}


void append_array(Application *applications, Application *to_add, int *index){

    int already_on_list = 0;

    for(int i = 0; i < *index; i++){
        if(!strcmp(applications[i].name, to_add->name))
            already_on_list = 1;
    }

    if(*index < n && !already_on_list){
        applications[*index] = *to_add;

        if(to_add->friend){
            applications[*index].name_lenght = strlen(applications[*index].name);
        }

        applications[*index].id = *index;
        (*index)++;
    }
}

void choose_friend(Application *applications, int size){

    int friend_index = 0;
    for (int i = 1; i < size; i++){

        if(applications[i].friend < 1)
            break;
        if (applications[i].name_lenght > applications[friend_index].name_lenght)
            friend_index = i;
        else if (applications[i].name_lenght == applications[friend_index].name_lenght){
            if(applications[i].id < applications[friend_index].id)
                friend_index = i;
        }
    }

    printf("Amigo do Habay:\n");
    printf("%s\n", applications[friend_index].name);
}

void printArray(Application arr[], int size){
    for (int i = 0; i < size; i++)
            printf("%s\n", arr[i].name);
    printf("\n");
}



int main(void){

    int index = 0;
    Application aux;
    Application applications[n];

    char friend[4];

    scanf("%s", aux.name);


    while(strcmp(aux.name, "FIM")){

        scanf("%s", friend);
        aux.friend = (!strcmp(friend,"YES")) ? 1 : 0;

        append_array(applications, &aux, &index);


        scanf("%s", aux.name);
    }

    mergesort(applications, 0, index - 1);
    printArray(applications, index);
    choose_friend(applications, index);


    return 0;
}
