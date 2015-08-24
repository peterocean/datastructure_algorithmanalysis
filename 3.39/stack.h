#ifndef _STACK_H_
#define _STACK_H_

typedef  int ElementType;

struct Node;
typedef struct Node *PtrtoNode;
typedef PtrtoNode Stack;
typedef PtrtoNode Position;

struct Node{
	ElementType Element;
	struct Node *Next;
};

extern int IsEmpty(Stack S);
extern Stack CreateStack(void);
extern void DiposeStack(Stack S);
extern void Push(ElementType X, Stack S);
extern ElementType Top(Stack S);
extern void Pop(Stack S);
extern void MakeEmpty(Stack S);

#endif
