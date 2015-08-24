#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define STACK_DEBUG 1

int IsEmpty(Stack S)
{
	assert(S != NULL);
	return S->Next == NULL;
}

void MakeEmpty(Stack S)
{
	while (!IsEmpty(S))
		Pop(S);
}

Stack CreateStack(void)
{
	Stack S = malloc(sizeof(struct Node));
	assert(S != NULL);

	S->Next = NULL;
	return S; 
}

void DisposeStack(Stack S)
{
	Position P = S;
	Position Tmp;

	if (!IsEmpty(S)) {
		while (P != NULL) {
			Tmp = P;
			P = P->Next;
			free(Tmp);
		}
	}
	free(S);
}

void Push(ElementType X, Stack S)
{
	Position Tmp; 
	assert(S != NULL);

	Tmp = malloc(sizeof(struct Node));
	assert(Tmp != NULL);

	Tmp->Element = X;
	Tmp->Next = S->Next;
	S->Next = Tmp;
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S)) {
		return S->Next->Element;
	}
	else {
		printf("Stack is empty,abnormal quit.\n");
		exit(-1);
	}
}

void Pop(Stack S)
{
	Position Tmp;
	if (IsEmpty(S)) {
		printf("Stack is empty.\n");
		return;
	}

	Tmp = S->Next;
	S->Next = S->Next->Next;
#ifdef STACK_DEBUG
	printf("Pop:%d\n",Tmp->Element);
#endif
	free(Tmp);
}



