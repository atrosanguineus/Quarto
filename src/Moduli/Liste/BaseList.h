#ifndef MODULI_LISTE_BASELIST_H_
#define MODULI_LISTE_BASELIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	void* data;
	struct Node* prox;
};

typedef struct
{
	int length;
	Node* start;
}List;

void* getData(Node node);
Node* getProx(Node node);
int setData(Node* node, void* data);
int setProx(Node* node, Node* prox);
Node newNode(void* data);
Node newLinkedNode(void* data, Node* prox);

int getLength(List list);
Node* getStart(List list);
int setLength(List* list, int length);
int setStart(List* list, Node* start);
List initialize();
int printList(List list, char* format);

List append(List* list, Node node);
List push(List* list, Node node);
List insert(List* list, int pos, Node node);



#endif /* MODULI_LISTE_BASELIST_H_ */
