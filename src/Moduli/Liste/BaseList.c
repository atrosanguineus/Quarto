#include "BaseList.h"

void* getData(Node node)
{
	return node.data;
}

Node* getProx(Node node)
{
	return node.prox;
}

int setData(Node* node, void* data)
{
	node->data = data;
	return 1;
}

int setProx(Node* node, Node* prox)
{
	node->prox = prox;
	return 1;
}

Node newNode(void* data)
{
	Node tempNode;
	setData(&tempNode, data);
	setProx(&tempNode, NULL);

	return tempNode;
}

Node newLinkedNode(void* data, Node* prox)
{
	Node tempNode;
	setData(&tempNode, data);
	setProx(&tempNode, prox);

	return tempNode;
}

//////////////////////////////////////////////
//////////////////////////////////////////////

int getLength(List list)
{
	return list.length;
}

Node* getStart(List list)
{
	return list.start;
}

int setLength(List* list, int length)
{
	list->length = length;
	return 1;
}

int setStart(List* list, Node* start)
{
	list->start = start;
	return 1;
}

List initialize()
{
	List tempList;
	setLength(&tempList, 0);
	setStart(&tempList, NULL);
	return tempList;
}

int printList(List list, char* format)
{
	Node* listStart = getStart(list);

	if( listStart == NULL )
	{
		return -1;
	}
	else
	{
		Node currentNode = *listStart;

		int length = getLength(list);
		int i = 0;
		while( i < length )
		{
			printf(format, getData(currentNode));

			if( getProx(currentNode) != NULL )
			{
				currentNode = *getProx(currentNode);
			}

			i = i + 1;
		}

		return 1;
	}
}

//////////////////////////////////////////////
//////////////////////////////////////////////

List append(List* list, Node node)
{
	int length = getLength(*list);
	Node* toAppend = malloc(sizeof(node));
	*toAppend = node;

	Node* listStart = getStart(*list);
	if( listStart == NULL )
	{
		setStart(list, toAppend);
	}
	else
	{
		Node* currentPointer = listStart;
		while( getProx(*currentPointer) != NULL )
		{
			currentPointer = getProx(*currentPointer);
		}

		setProx(currentPointer, toAppend);
	}

	setLength(list, length + 1);
	return *list;
}

List push(List* list, Node node)
{
	int length = getLength(*list);
	Node* toAppend = malloc(sizeof(node));
	*toAppend = node;

	Node* listStart = getStart(*list);
	if( listStart == NULL )
	{
		setStart(list, toAppend);
	}
	else
	{
		setStart(list, toAppend);
		setProx(toAppend, listStart);
	}

	setLength(list, length + 1);
	return *list;
}

List insert(List* list, int pos, Node node)
{
	int length = getLength(*list);
	Node* toAppend = malloc(sizeof(node));
	*toAppend = node;

	Node* listStart = getStart(*list);
	if( listStart == NULL )
	{
		setStart(list, toAppend);
	}
	else if( pos == 0 )
	{
		setStart(list, toAppend);
		setProx(toAppend, listStart);
	}
	else if( pos == length )
	{
		Node* currentPointer = listStart;
		while( getProx(*currentPointer) != NULL )
		{
			currentPointer = getProx(*currentPointer);
		}

		setProx(currentPointer, toAppend);
	}
	else if( pos < length && pos > 0 )
	{
		int i = 0;
		Node* currentPointer = listStart;
		while( i < pos - 1 )
		{
			currentPointer = getProx(*currentPointer);
			i = i + 1;
		}

		setProx(toAppend, getProx(*currentPointer));
		setProx(currentPointer, toAppend);
	}

	setLength(list, length + 1);
	return *list;
}
