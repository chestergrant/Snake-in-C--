#pragma once

class CNode
{
public:
	CNode(void);
	~CNode(void);
	CNode(SnakePart data);
	CNode(SnakePart data, CNode * next, CNode * prev);
	SnakeData getData(void);
private:
	// Stores the location of the next node in the linked list
	CNode * nextNode;
	// Stores the location of the previous node in the linked list
	CNode * prevNode;
public:
	// Set the next node in the linked list
	void setNext(CNode * next);
	// Returns the next node in the linked list
	CNode * getNext(void);
	// Set the previous node in the linked list
	void setPrevious(CNode * prev);
private:
	// Stores the segment of the snake
	SnakePart myData;
public:
	CNode * getPrevious(void);
};
