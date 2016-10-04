#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int k;
	int vetor[10];

	srand((unsigned)time(NULL));

	for (k = 0; k < 10; k++)
	{
		vetor[k] = rand() % 1000;
	}

	for (int i = 0; i < 10; i++)
		printf("Numero %d: %d\n", i, vetor[i]);

	return 0;
}
