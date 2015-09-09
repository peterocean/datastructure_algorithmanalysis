#include "tree.h"
#include <stdlib.h>
#include <assert.h>


SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T != NULL) {
		if (X < T->Element)
			return Find(T->Left);
		else if (X > T->Element)
			return Find(T->Right);
		else return T;
	}
	return NULL;
}

Position FindMax(ElementType X, SearchTree T)
{
	if (T == NULL) return NULL;
	while ( T->Right != NULL) {
		T = T->Right;
	}
	return P;
}

Position FindMin(ElementType X, SearchTree T)
{
	if (T == NULL) return NULL;
	while (T->Left != NULL) 
		T = T->Left;
	return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T != NULL) {
		if (X < T->Element)
			T->Left = Insert(X,T->Left)
		else if (X > T->Element)
			T->Right = Insert(X,T->Right)
	} else {
		T = malloc(sizeof(struct TreeNode));
		assert(T != NULL);
		T->Left = NULL;
		T->Right = NULL;
	}
	return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
	Position P;
	if (T == NULL) return NULL;
	P = FindMin(T->Right);
}





