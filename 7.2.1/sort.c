#include "sort.h"
#include <stdio.h>

#define INSERT_SORT_DEBUG 1

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
