#include "StdAfx.h"
#include "LinkedList.h"
#include "Node.h"
#include "SnakePart.h"


CLinkedList::CLinkedList(void)
: top(NULL)
, curr(NULL)
{
	CNode top = new CNode();
	top.setNext(NULL);
	top.setPrevious(NULL);
	curr = top;
}

CLinkedList::~CLinkedList(void)
{
}

void CLinkedList::Add(SnakePart data)
{
    CNode s = new CNode(data);
	s->setNext(top->getNext());
	s->setPrevious(top);
	top->setNext(s);

	
}

CNode * CLinkedList::deleteLast(void)
{
     CNode * last;
	 last = top->getNext();
	 if(last != NULL){
		 while(last->getNext() != NULL){
			 last = last->getNext();
		 }
		 last->getPrevious() = last->getNext();
	     return last;
	 }

	 return NULL;
}

// Returns the next Node in the Linked List
CNode * CLinkedList::nextNode(void)
{
	if(curr != NULL){
	   CNode * ans = curr->getNext();
       curr = ans;

	   reutrn ans;
	}
	return NULL

}

// Returns the previous node in the Linked List
CNode * CLinkedList::previousNode(void)
{
	if(curr != NULL){
	   CNode * ans = curr->getPrevious();
	   curr = prev;
	   return ans;
	}
	return NULL;
}

// Resets the traversing of the linked list
void CLinkedList::reset(void)
{
	curr = top;
}

// Change the start of the linked list
void CLinkedList::setTop(CNode * aTop)
{
	top = aTop;
}
