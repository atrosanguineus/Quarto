#ifndef MODULI_LISTE_BASEALBERI_H_
#define MODULI_LISTE_BASEALBERI_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode TNode;
struct TNode
{
	struct TNode* parent;
	void* data;
	int numChildren;
	struct TNode** children;
};

typedef struct
{
	TNode* start;
	int depth;
}Tree;

TNode* getParent(TNode node);
void* getTData(TNode node);
int getNumChildren(TNode node);
TNode** getChildren(TNode node);
int setParent(TNode* node, TNode* parent);
int setTData(TNode* node, void* data);
int setNumChildren(TNode* node, int numChildrens);
int setChildren(TNode* node, TNode** childrens);
TNode newTNode(void* data);

TNode* getTStart(Tree tree);
int getDepth(Tree tree);
int setTStart(Tree* tree, TNode* node);
int setDepth(Tree* tree, int depth);
Tree initTree();

int addChild(TNode* node, TNode child);

#endif /* MODULI_LISTE_BASEALBERI_H_ */
