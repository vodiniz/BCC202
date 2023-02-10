#include <stdio.h>
#include <string.h>
#define TAM 20
#define VEC_TAM 24


typedef struct {
    char pais[TAM];
    char texto[TAM];
} Traducao ;





void add_traducao(char *pais, char *texto, Traducao *traducoes, int pos);
int encontra_traducao(char *pais, Traducao *traducoes, int tam);


void add_traducao(char *pais, char *texto, Traducao *traducoes, int pos){

    strcpy(traducoes[pos].pais, pais);
    strcpy(traducoes[pos].texto, texto);
}

int encontra_traducao(char *pais, Traducao *traducoes, int tam){

    for ( int i = 0; i < tam; i++){
        if(!strcmp(pais, traducoes[i].pais))
            return i;
    }

    return -1;
}

int main(void){

    Traducao traducoes[VEC_TAM];
    char str[TAM];

    add_traducao("brasil","Feliz Natal!",traducoes, 0);
    add_traducao("alemanha","Frohliche Weihnachten!",traducoes, 1);
    add_traducao("austria","Frohe Weihnacht!",traducoes, 2);
    add_traducao("coreia","Chuk Sung Tan!",traducoes, 3);
    add_traducao("espanha","Feliz Navidad!",traducoes, 4);
    add_traducao("grecia","Kala Christougena!",traducoes, 5);
    add_traducao("estados-unidos","Merry Christmas!",traducoes, 6);
    add_traducao("inglaterra","Merry Christmas!",traducoes, 7);
    add_traducao("australia","Merry Christmas!",traducoes, 8);
    add_traducao("portugal","Feliz Natal!",traducoes, 9);
    add_traducao("suecia","God Jul!",traducoes, 10);
    add_traducao("turquia","Mutlu Noeller",traducoes, 11);
    add_traducao("argentina","Feliz Navidad!",traducoes, 12);
    add_traducao("chile","Feliz Navidad!",traducoes, 13);
    add_traducao("mexico","Feliz Navidad!",traducoes, 14);
    add_traducao("antardida","Merry Christmas!",traducoes, 15);
    add_traducao("canada","Merry Christmas!",traducoes, 16);
    add_traducao("irlanda","Nollaig Shona Dhuit!",traducoes, 17);
    add_traducao("belgica","Zalig Kerstfeest!",traducoes, 18);
    add_traducao("italia","Buon Natale!",traducoes, 19);
    add_traducao("libia","Buon Natale!",traducoes, 20);
    add_traducao("siria","Milad Mubarak!",traducoes, 21);
    add_traducao("marrocos","Milad Mubarak!",traducoes, 22);
    add_traducao("japao","Merii Kurisumasu!",traducoes, 23);

    

    while(scanf("%s", str) != EOF){

        int index = encontra_traducao(str, traducoes, VEC_TAM);

        if(index >= 0){
            printf("%s\n", traducoes[index].texto);
        } else {
            printf("--- NOT FOUND ---\n");
        }

    }



    return 0;
}
