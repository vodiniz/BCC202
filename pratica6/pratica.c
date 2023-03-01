#include "ordenacao.h"
#include <stdio.h>

int main() {

	int *vetor;
	int i, n;

	while(scanf("%d", &n), n) {
		int movimentos = 0;
		// aloca o vetor
		vetor = alocaVetor(vetor, n);

		// preenche o vetor
		for( int i = 0; i < n; i++)
			scanf("%d", &vetor[i]);
		// ordena o vetor e determina o número de movimentos
		ordenacao(vetor, n, &movimentos);
		// imprime o resultado

		if(movimentos % 2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");


		vetor = desalocaVetor(vetor);
	}

	return 0;
}