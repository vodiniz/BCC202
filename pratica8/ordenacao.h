# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    int id;
    int pontos;
    int vitorias;
    int derrotas;
    int cestas_marcadas;
    int cestas_tomadas;
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void atualiza_times(Time *times, int time1, int pontos1, int time2, int pontos2);


void imprime_times(Time *times, int n);

# endif
