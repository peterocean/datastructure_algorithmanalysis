#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

extern int IsEmpty(Queue Q);
extern int IsFull(Queue Q);

extern Queue CreateQueue(int MaxElements);
extern void DisposeQueue(Queue Q);
extern void MakeEmpty(Queue Q);
extern void Enqueue(ElementType X, Queue Q);
extern ElementType Front(Queue Q);
extern void Dequeue(Queue Q);
extern ElementType FrontAndDequeue(Queue Q);

#define MIN_QUEUE_SIZE (5)
struct  QueueRecord 
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

#endif
