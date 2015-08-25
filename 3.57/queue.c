#include "queue.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define QUEUE_DEBUG 1

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
void MakeEmpty(Queue Q)
{
	Q->Front = 0;
	Q->Rear = 0;
	Q->Size = 0;
}
Queue CreateQueue(int MaxElements) 
{
	Queue Q;

	if (MaxElements < MIN_QUEUE_SIZE){
		MaxElements = MIN_QUEUE_SIZE;
	}
	Q = malloc(sizeof(struct QueueRecord)); 	
	if (Q == NULL) return NULL;
	Q->Capacity = MaxElements;
	Q->Array = malloc(sizeof(ElementType)*Q->Capacity);
	assert(Q->Array != NULL);
	MakeEmpty(Q);
}
int QueueShift(int Pos, Queue Q)
{
	if ((Pos + 1) == Q->Capacity) {
		return 0;
	} else {
		return (Pos+1);
	}
}
void Enqueue(ElementType X, Queue Q)
{
	assert( Q != NULL);
	if (IsFull(Q)) {
		printf("Queue if full.\n");
		return;	
	} else {
		Q->Array[Q->Rear] = X;
		Q->Size++;
#ifdef QUEUE_DEBUG
		printf("Enqueue:%d,queue Size:%d\n",Q->Array[Q->Rear],Q->Size);
#endif
		Q->Rear = QueueShift(Q->Rear,Q);
	}
}
ElementType Front(Queue Q)
{
	assert(Q != NULL);
	if (!IsEmpty(Q)) {
		return Q->Array[Q->Front];
	}
	else {
		printf("Queu is empty,quit abnormal.\n");
		exit(-1);
	}
}


void Dequeue(Queue Q)
{
	assert(Q != NULL);
	if (!IsEmpty(Q)) {
		Q->Front = QueueShift(Q->Front,Q);
		Q->Size--;
	} else {
		printf("Queu is empty.\n");
		exit(-1);
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	int Tmp;
	assert(Q != NULL);
	if (!IsEmpty(Q)) {
		Tmp = Q->Array[Q->Front];
		Q->Front = QueueShift(Q->Front,Q);
		Q->Size--;
#ifdef QUEUE_DEBUG
		printf("Dequeue:%d,queue Size:%d\n",Tmp,Q->Size);
#endif
		return Tmp;
	} else {
		printf("Queu is empty,quit abnormal.\n");
		exit(-1);
	}
} 

void DisposeQueue(Queue Q)
{
	if (Q != NULL) {
		free(Q->Array);
		free(Q);
	}
}





