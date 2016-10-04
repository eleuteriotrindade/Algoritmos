#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	clock_t Ticks[2];
	Ticks[0] = clock();

	int vetor[100000];
	int tamanho = 100000;
	int temp = 0, j;
	int k;
	srand((unsigned)time(NULL));

	for (k = 0; k < tamanho; k++)
	{
		vetor[k] = rand() % 1000000;
	}

	for (int i = 2; i<tamanho; i++)
	{
		temp = vetor[i];
		j = i - 1;
		while (j >= 0 && vetor[j]>temp)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = temp;
	}

	for (int r = 0; r<tamanho; r++)
	{
		printf("%d\n", vetor[r]);
	}

	Ticks[1] = clock();
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\nTempo gasto: %g ms.", Tempo);
	getchar();

	return 0;
}