#include <stdio.h>
#include "stack.h"

int main(int argc, char*argv[])
{
	Stack S;
	int i = 0;

	S = CreateStack();
	for (i = 0; i < 20; i++) {
		Push(i,S);
	}

	while (!IsEmpty(S)) {
		Pop(S);
	}
	DisposeStack(S);
	return 0;
}
