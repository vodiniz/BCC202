#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char name[20];
    char region;
    int distance;

} Student;



int compare_students(Student *student1, Student *student2){


    if(student1->distance < student2->distance)
        return 0;
    else if (student1->distance > student2->distance)
        return 1;
    else {
        if(student1->region < student2->region){
            return 0;
        } else if (student1->region > student2->region)
            return 1;
        else {
            if(strcmp(student1->name, student2->name) > 0)
                return 1;
            else
                return 0;
        }
    }

}


//Implementação do mergesort
void merge(Student *v, int l, int m, int r){

    int size_l = (m - l + 1); //Recebe o tamanho do vetor da esquerda
    int size_r = (r - m); //Recebe o tamanho do vetor da direita

    Student *vet_l = malloc( size_l * sizeof(Student));
    Student *vet_r = malloc( size_r * sizeof(Student));

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

        else if (!compare_students(&vet_l[i], &vet_r[j]))
            v[k] = vet_l[i++]; //i irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da direita

        else
            v[k] = vet_r[j++]; //j irá aumentar 1 toda vez que o número do vetor da direita for menor, passando pro próximo indíce do vetor da esquerda
    }

    //Liberando os vetores da direita e da esquerda alocados
    free(vet_l);
    free(vet_r);

}

void mergesort(Student *v, int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);

    }
}

void read_students(Student *students, int n){

    for(int i = 0; i < n; i++)
        scanf("%s %c %d", 
            students[i].name,
            &students[i].region,
            &students[i].distance);

}

void print_students(Student *students, int n){

    for (int i = 0; i < n; i++)
        printf("%s\n", students[i].name);
}





int main(void){

    int students_number;

    while (scanf("%d", &students_number) != EOF){

        Student *students = malloc(students_number * sizeof(Student));

        read_students(students, students_number);


        mergesort(students, 0, students_number - 1);


        print_students(students,students_number);

        free(students);
    }



    return 0;
}