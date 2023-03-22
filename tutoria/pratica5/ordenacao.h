#define TAM_STR 100

typedef struct {

    char estudante[TAM_STR];
    char cor_logo[TAM_STR];
    char tamanho_camiseta;

}Camiseta;



void heap_sort(Camiseta *camisetas, int n);
void heap_constroi (Camiseta *camisetas, int n);
void heap_refaz (Camiseta *camisetas, int esq, int dir);
int compare(Camiseta *camiseta1, Camiseta *camiseta2);
void imprime_camisetas(Camiseta *camisetas, int n);