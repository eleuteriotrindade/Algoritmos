/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int vetor[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int vetor[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(vetor, l, m);
        mergeSort(vetor, m+1, r);
 
        merge(vetor, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void imprimir(int A[], int tamanho)
{
    int i;
    for (i=0; i < tamanho; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    clock_t Ticks[2];
    Ticks[0] = clock();
    int vetor[1000000]; 
    int vetor_size = sizeof(vetor)/sizeof(vetor[0]);
    int controle = 0;

    srand( (unsigned)time(NULL) );

    for(controle = 0 ; controle < vetor_size ; controle++)
    {
        vetor[controle] = rand () % 10000;
    }
        

 
    printf("Given array is \n");
    imprimir(vetor, vetor_size);
 
    mergeSort(vetor, 0, vetor_size - 1);
 
    printf("\nSorted array is \n");
    imprimir(vetor, vetor_size);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();


    return 0;
}