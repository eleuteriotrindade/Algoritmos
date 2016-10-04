#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void) {

	clock_t Ticks[2];
	Ticks[0] = clock();

	int vetor[100000];
	int tamanho = 10000;
	int temp = 0;


	srand((unsigned)time(NULL));

	for (int k = 1; k <= tamanho; k++)
	{
		vetor[k] = rand() % 100000;
	}

	for (int i = tamanho; i >= 0; i--)
	{
		for (int j = i; j<tamanho; j++)
		{
			if (vetor[j]<vetor[j + 1])
			{
				temp = vetor[j + 1];
				vetor[j + 1] = vetor[j];
				vetor[j] = temp;
			}
		}
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