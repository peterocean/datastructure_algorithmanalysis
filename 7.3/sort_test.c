#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define  ARRAY_SIZE 10
#define  RANDOM_MAX 1000

void RandomFillArray(ElementType A[], int N)
{
	int i = 0;
	for (i = 0; i < N; i++) {
		A[i] = (rand()%RANDOM_MAX);
	}
}
int main(int argc, char *argv[])
{
	int N = 0;
	ElementType *A;

	if (argc != 2) return -1;
	N = atoi(argv[1]);
	assert(N != 0);

	A = malloc(sizeof(ElementType)*N);
	assert(A != NULL);
	memset(A,0,N*sizeof(ElementType));


	RandomFillArray(A,N);
	printf("original array:\n");
	PrintArray(A,N);

	printf("sort start:\n");
//	InsertSort(A,N);
//	BubbleSort(A,N);
	ShellSort_V2(A,N);
	printf("sort end.\n");

	printf("After sort array is:\n");
	PrintArray(A,N);

	free(A);
	return 0;
}
