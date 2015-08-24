#include <stdio.h>
#include "stack.h"

int main(int argc, char*argv[])
{
	Stack S;
	int i = 0;

	S = CreateStack(25);
	for (i = 0; i < 20; i++) {
		Push(i,S);
	}
	
	printf("Stack capacity:%d, Stack records:%d\n",S->Capacity,S->TopOfStack+1);
	while (!IsEmpty(S)) {
		Pop(S);
	}
	DisposeStack(S);
	return 0;
}
