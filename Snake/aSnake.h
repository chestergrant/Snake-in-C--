#pragma once
#include "linkedlist.h"
#include "atltypes.h"

class aSnake
{
public:
	aSnake(void);
	~aSnake(void);
private:
	// Stores all the body parts of the current snake
	CLinkedList snakeList;
	// Stores the current score of our snake
	int score;
	// Stores the current position of the head of our snake
	CPoint pos;
public:
	// Move our snake to the left
	void moveLeft(void);
	// Move our snake to the right
	void moveRight(void);
	// Move our snake upwards
	void moveUp(void);
	// Move our snake downwards
	void moveDown(void);
	bool isAlive(CPoint s, CPoint e);
	// Returns the current score of the snake
	int getScore(void);
	// Set the current score
	void setScore(int s);
	void draw(void);
	// Grows our snake by one unit
	void Grow(void);
	// Shrink the snake by one unit
	void Shrink(void);
	// Determine if the snakes hits an item
	bool collision(Food aFood);
	// Move the snake forward by one body length in its current direction
	void move(void);
private:
	// Stores whether the snake is moving vertical or horizontal
	int direction;
	// Determine if two parts of the snake hit each other
	bool collidePart(CNode * head, CNode * aCurr);
public:
	// Displays Snakey's current score to the screen
	void displayScore(CDC * pDC);
private:
	// Stores the text display location
	CPoint text;
public:
	aSnake(int startScore, Cpoint startPos, int startDirection, CPoint scorePos);
};
