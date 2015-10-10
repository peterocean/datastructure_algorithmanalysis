#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INSERT_SORT_DEBUG 1
#define SHELL_SORT_DEBUG 1
#define BUBBLE_SORT_DEBUG 1
#define QUICK_SORT_DEBUG 1
#define MERGE_SORT_DEBUG 1

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
	int j = 0;
	for (Inc = N/2; Inc > 0; Inc /=2) {
		for(j = 0; j < N; j++) {
			for (i = j + Inc; i < N; i += Inc) {
				if (A[i] < A[i-Inc]) Exchange(&A[i],&A[i-Inc]);	
			}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
		}
	}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
}

void ShellSort_V2(ElementType A[], int N)
{
	int Inc = 0;
	int i = 0;
	int j = 0;
	ElementType temp;

	for (Inc = N/2; Inc > 0; Inc /=2) {
		for (i = Inc; i < N; i++) {
			for ( j = i; j < N; j += Inc) {
				if (A[j] < A[j-Inc]) Exchange(&A[j],&A[j-Inc]);
			}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
		}
	}
#ifdef INSERT_SORT_DEBUG
		PrintArray(A,N);
#endif
}



void BubbleSort(ElementType A[], int N)
{
	int i,j,k;
	for (i = N; i > 0 ; i--) {
		for (j = 1; j < i;j++) {
			if (A[j -1] > A[j]) 
				Exchange(&A[j],&A[j-1]);
		}
#ifdef BUBBLE_SORT_DEBUG
		PrintArray(A,N);
#endif
	}
#ifdef BUBBLE_SORT_DEBUG
		PrintArray(A,N);
#endif
}


int Partition(ElementType A[],int left, int right)
{
	int i = left;
	int j = right;
	ElementType key  = A[right]; 
	
#ifdef QUICK_SORT_DEBUG
	printf("Before Partition:i=%d;j=%d,left=%d,right=%d.\n",i,j,left,right);
#endif
	while (1) {
		while (A[i] <= key) i++;
		while (A[j] >=  key) j--;
		if (i < j) Exchange(&A[i],&A[j]);
		else break;
	}
	Exchange(&A[i],&A[right]);
#ifdef QUICK_SORT_DEBUG
	printf("After Partition:i=%d;j=%d,left=%d,right=%d.\n",i,j,left,right);
#endif
	return i;
}


void _QuickSort(ElementType A[],int left, int right)
{
	int i = left;
	int j = right;
	ElementType v = A[right];
	
	if (right <= 1) return;
	i = Partition(A,left,right);
#ifdef QUICK_SORT_DEBUG
	PrintArray(A,right+1);
#endif
	_QuickSort(A,left,i-1);
	_QuickSort(A,i+1,right);
}
void QuickSort(ElementType A[],int N)
{
	_QuickSort(A,0,N-1);

	return;
}

static void Merge(ElementType A[], int N,ElementType TmpArray[],int Lpos, int Rpos,int RightEnd)
{
	int i, LeftEnd, NumElements,Tmppos;
	LeftEnd = Rpos - 1;
	Tmppos = Lpos;
	NumElements = RightEnd - Lpos + 1;

#ifdef MERGE_SORT_DEBUG
	printf("Merge before: Lpos=%3d,LeftEnd=%d;  Rpos=%3d,RightEnd=%d; \n",Lpos,LeftEnd,Rpos,RightEnd);
#endif
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			TmpArray[Tmppos++] = A[Lpos++];
		else
			TmpArray[Tmppos++] = A[Rpos++];
	}
	while (Lpos <= LeftEnd)
		TmpArray[Tmppos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[Tmppos++] = A[Rpos++];
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
#ifdef MERGE_SORT_DEBUG
	PrintArray(A,N);
#endif
}
 
static void MSort(ElementType A[],int N,ElementType TmpArray[],int Left, int Right)
{
	int Center;
	if(Left < Right)
	{
		Center = (Left + Right)/2;
		MSort(A,N,TmpArray,Left,Center);
		MSort(A,N,TmpArray,Center + 1,Right);
		Merge(A,N,TmpArray,Left,Center + 1,Right);
	}
}

void MergeSort(ElementType A[], int N)
{
	ElementType *TmpArray = malloc(N*sizeof(ElementType));
	assert(TmpArray != NULL);
	MSort(A,N,TmpArray,0,N-1);
	PrintArray(A,N);
	free(TmpArray);
}




