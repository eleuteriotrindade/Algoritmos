#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//algoritmo retirado de https://www.vivaolinux.com.br/script/Ordenacao-QuickSort

void Quick(int *vetor, int inicio, int fim){

	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (int)((i + j) / 2);
	pivo = vetor[meio];

	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;

		if (i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	} while (j > i);

	if (inicio < j) Quick(vetor, inicio, j);
	if (i < fim) Quick(vetor, i, fim);

}

int main(){

	clock_t Ticks[2];
	Ticks[0] = clock();

	int vetor[1000], tamanho = 1000;

	srand((unsigned)time(NULL));

	for (int k = 0; k < tamanho; k++)
	{
		vetor[k] = rand() % 100000;
	}

	Quick(vetor, 0, 999);
	
	printf("Vetor ordenado:\n");
	for (int i = 0; i < 1000; i++)
	{
		printf("%d ", vetor[i]);
	}

	Ticks[1] = clock();
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\nTempo gasto: %g ms.", Tempo);
	getchar();

	return 0;
}

