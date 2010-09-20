#pragma once

class CLinkedList
{
public:
	CLinkedList(void);
	~CLinkedList(void);
private:
	// Stores the location of the first node in the linked list
	CNode *top;
public:
	void Add(SnakePart data);
	CNode * deleteLast(void);
private:
	// Stores the Current Node being travarsed
	CNode *curr;
public:
	// Returns the next Node in the Linked List
	CNode * nextNode(void);
	// Returns the previous node in the Linked List
	CNode * previousNode(void);
	// Resets the traversing of the linked list
	void reset(void);
	// Change the start of the linked list
	void setTop(CNode * aTop);
};
