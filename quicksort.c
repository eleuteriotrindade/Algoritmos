#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void quicksort(int vetor[], int inicio, int fim)
{
	int i, j, meio, aux;

	i = inicio;
	j = fim;
	meio = vetor[(inicio + fim) / 2];

	do
	{
		while(vetor[i] < meio)
			i++;
		while(vetor[j] > meio)
			j--;
		if (i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}while(i <= j);
	if (inicio < j)
	{	
		quicksort(vetor, inicio, j);
	}
	if (i < fim)
	{
		quicksort(vetor, i, fim);
	}

}


int main(){

	clock_t Ticks[2];
    Ticks[0] = clock();

    int vetor[1000000];
    int controle;

    srand( (unsigned)time(NULL) );

    for(controle = 0 ; controle < 1000000; controle++)
    {
        vetor[controle] = rand () % 10000;
    }

 	quicksort(vetor, 0, 999999);

    for (int k = 0; k < 1000000; k++)
    {	
    	printf("%d ", vetor[k]);
    }


    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
    getchar();

	return 0;
}