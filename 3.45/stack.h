#ifndef _STACK_H_
#define _STACK_H_

typedef  int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

struct StackRecord{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

extern int IsEmpty(Stack S);
extern int IsFull(Stack S);
extern Stack CreateStack(int MaxElements);
extern void DiposeStack(Stack S);
extern void MakeEmpty(Stack S);
extern void Push(ElementType X, Stack S);
extern ElementType Top(Stack S);
extern void Pop(Stack S);
extern ElementType TopAndPop(Stack S);

#define EMPTY_TOS (-1)
#define MIN_STACK_SIZE (5)

#endif
