#include "BaseAlberi.h"

TNode* getParent(TNode node)
{
	return node.parent;
}

void* getTData(TNode node)
{
	return node.data;
}

int getNumChildren(TNode node)
{
	return node.numChildren;
}

TNode** getChildren(TNode node)
{
	return node.children;
}

int setParent(TNode* node, TNode* parent)
{
	node->parent = parent;
	return 1;
}
int setTData(TNode* node, void* data)
{
	node->data = data;
	return 1;
}
int setNumChildren(TNode* node, int numChildrens)
{
	node->numChildren = numChildrens;
	return 1;
}
int setChildren(TNode* node, TNode** childrens)
{
	node->children = childrens;
	return 1;
}
TNode newTNode(void* data)
{
	TNode toReturn;
	setTData(&toReturn, data);
	setNumChildren(&toReturn, 0);
	setParent(&toReturn, NULL);

	return toReturn;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

TNode* getTStart(Tree tree)
{
	return tree.start;
}

int getDepth(Tree tree)
{
	return tree.depth;
}

int setTStart(Tree* tree, TNode* node)
{
	tree->start = node;
	return 1;
}

int setDepth(Tree* tree, int depth)
{
	tree->depth = depth;
	return 1;
}

Tree initTree()
{
	Tree toReturn;
	setTStart(&toReturn, NULL);
	setDepth(&toReturn, 0);
	return toReturn;
}

int addChild(TNode* node, TNode child)
{
	int children = getNumChildren(*node);
	TNode** childStorage = getChildren(*node);

	TNode* tempChild = malloc( sizeof(child) );
	*tempChild = child;
	setParent(tempChild, node);

	children = children + 1;
	childStorage = realloc(childStorage, children * sizeof(*tempChild));
	childStorage[children - 1] = tempChild;

	setChildren(node, childStorage);
	setNumChildren(node, children);
	return 1;
}

