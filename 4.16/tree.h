#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

extern SearchTree MakeEmpty(SearchTree T);
extern Position Find(ElementType X, SearchTree T);
extern Position FindMax(SearchTree T);
extern Position FindMin(SearchTree T);
extern SearchTree Insert(ElementType X, SearchTree T);
extern SearchTree Delete(ElementType X, SearchTree T）；
extern ElementType Retrieve(Position P);

struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
}
#endif
