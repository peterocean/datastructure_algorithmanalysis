#include "sort.h"
#include <stdio.h>

#define INSERT_SORT_DEBUG 1
#define SHELL_SORT_DEBUG 1

void Exchange(ElementType *a, ElementType *b)
{
	ElementType Tmp;
	Tmp = *a;
	*a = *b;
	*b = Tmp;
}

void PrintArray(ElementType A[],int N)
{
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%3d ",A[i]);		
	}
	printf("\n");
}

void InsertSort(ElementType A[],int N)
{
	int i,j,k;
	ElementType Tmp;
	for (i = 1; i < N -1 ; i++) {
		Tmp = A[i];
		for (j = i; j > 0 && (A[j-1] > Tmp); j--) {
			A[j] = A[j-1];
		}
		A[j] = Tmp;
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
	}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
}

void ShellSort(ElementType A[], int N)
{
	int Inc = 0;
	int i = 0;
	for (Inc = N/2; Inc > 0; Inc /=2) {
		for (i = 0; (i + Inc) < N; i++) {
			if (A[i+Inc] < A[i]) Exchange(&A[i],&A[i+Inc]);	
		}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
	}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
}
