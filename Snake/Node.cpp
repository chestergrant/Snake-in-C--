#include "StdAfx.h"
#include "SnakePart.h"
#include "Node.h"


CNode::CNode(void)
: nextNode(NULL)
, prevNode(NULL)
{
}

CNode::~CNode(void)
{
}

CNode::CNode(SnakePart data)
:nextNode(NULL);
:prevNode(NULL);
{
}

CNode::CNode(SnakePart data, CNode * next, CNode * prev)
{
	 myData = data;
	 nextNode = next;
	 prevNode = prev;
}

SnakeData CNode::getData(void)
{
	return myData;
}

// Set the next node in the linked list
void CNode::setNext(CNode * next)
{
	 nextNode = next;
}

// Returns the next node in the linked list
CNode * CNode::getNext(void)
{
	return nextNode;
}

// Set the previous node in the linked list
void CNode::setPrevious(CNode * prev)
{
	 prevNode = prev;
}

CNode * CNode::getPrevious(void)
{
	return prevNode;
}
