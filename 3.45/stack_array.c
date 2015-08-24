#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define STACK_DEBUG 1

int IsEmpty(Stack S)
{
	assert(S != NULL);
	return S->TopOfStack == EMPTY_TOS;
}

int IsFull(Stack S)
{
	assert(S != NULL);
	return S->TopOfStack == S->Capacity;
}

Stack CreateStack(int MaxElements)
{
	Stack S;
	if (MaxElements < MIN_STACK_SIZE) {
		MaxElements = MIN_STACK_SIZE;
	}
	S = malloc(sizeof(struct StackRecord));
	assert(S != NULL);

	S->Array = malloc(sizeof(ElementType)*MaxElements);
	if (S->Array == NULL) {
		printf("Out of space.\n");
		free(S);
		exit(-1);
	}
	S->TopOfStack = EMPTY_TOS;
	S->Capacity = MaxElements;

	return S; 
}

void MakeEmpty(Stack S)
{
	assert(S != NULL);
	S->TopOfStack = EMPTY_TOS;
}


void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}

void Push(ElementType X, Stack S)
{
	if (!IsFull(S)) {
		S->Array[++S->TopOfStack] = X;
	}
	else {
		printf("Stack is full.\n");
	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S)) {
		return S->Array[S->TopOfStack];
	}
	else {
		printf("Stack is empty,abnormal quit.\n");
		exit(-1);
	}
}

void Pop(Stack S)
{
	if (IsEmpty(S)) {
		printf("Stack is empty.\n");
		return;
	}
	--S->TopOfStack;	
#ifdef STACK_DEBUG
	printf("Pop:%d\n",S->Array[S->TopOfStack+1]);
#endif
}

ElementType TopAndPop(Stack S)
{
	if (IsEmpty(S)) {
		printf("Stack is empty.\n");
		exit(-1);
	}
	return S->Array[S->TopOfStack--];
}

