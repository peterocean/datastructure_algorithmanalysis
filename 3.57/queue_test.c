#include "queue.h"
#include <stdio.h>



int main(int argc, char *argv[])
{
	int MaxElements = 0;
	Queue Q;
	int i = 0;

	if (argc != 2) return;
	MaxElements = atoi(argv[1]);

	printf("Create queue by capacity:%d\n",MaxElements);
	Q = CreateQueue(MaxElements);
	if (Q == NULL) {
		printf("Create queue failed: out of space.\n");
		exit(-1);
	}

	for (i = 0; i < Q->Capacity/2; i++) {
		Enqueue(i,Q);
	}
	
	while (!IsEmpty(Q)) {
		FrontAndDequeue(Q);
	}

	for (i = 0; i < Q->Capacity*2; i++) {
		Enqueue(i+20,Q);
	}

	for (i = 0; i < Q->Capacity*3;i++) {
		FrontAndDequeue(Q);
	}
	DisposeQueue(Q);
	return 0;
}
