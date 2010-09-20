#include "StdAfx.h"
#include "aSnake.h"
#include "CNode.h"
#include "SnakePart.h"

aSnake::aSnake(void)
: score(0)
, pos(0)
, direction(0)
, text(0)
{
}

aSnake::~aSnake(void)
{
}

// Move our snake to the left
void aSnake::moveLeft(void)
{
	move();

	if((direction == 0)||(direction == 1)){
       snakeList.reset();
	   CNode * head = snakeList.nextNode();
	   CNode * firstPart = snakeList.nextNode();

	   	   
	   CPoint * headPos = head->getData()->getPos();
	   CPoint * fPartPos =firstPart->getData()->getPos();
	   BITMAP bm;
	   firstPart->getData()->getImage()->getBitmap(&bm);
	   headPos->x = fPartPos->x - bm.bmWidth;
	   headPos->y = fPartPos->y;
	   direction = 3;
	}

}

// Move our snake to the right
void aSnake::moveRight(void)
{
	
	move();

	if((direction == 0)||(direction == 1)){
       snakeList.reset();
	   CNode * head = snakeList.nextNode();
	   CNode * firstPart = snakeList.nextNode();

	   	   
	   CPoint * headPos = head->getData()->getPos();
	   CPoint * fPartPos =firstPart->getData()->getPos();
	   BITMAP bm;
	   firstPart->getData()->getImage()->getBitmap(&bm);
	   headPos->x = fPartPos->x + bm.bmWidth;
	   headPos->y = fPartPos->y;
	   direction  = 2;
	}
}

// Move our snake upwards
void aSnake::moveUp(void)
{
	
	move();

	if((direction == 2)||(direction == 3)){
       snakeList.reset();
	   CNode * head = snakeList.nextNode();
	   CNode * firstPart = snakeList.nextNode();

	   	   
	   CPoint * headPos = head->getData()->getPos();
	   CPoint * fPartPos =firstPart->getData()->getPos();
	   BITMAP bm;
	   firstPart->getData()->getImage()->getBitmap(&bm);
	   headPos->x = fPartPos->x;
	   headPos->y = fPartPos->y + bm.bmHeight;
	   direction = 0;
	}
}

// Move our snake downwards
void aSnake::moveDown(void)
{
	move();

	if((direction == 2)||(direction == 3)){
       snakeList.reset();
	   CNode * head = snakeList.nextNode();
	   CNode * firstPart = snakeList.nextNode();

	   	   
	   CPoint * headPos = head->getData()->getPos();
	   CPoint * fPartPos =firstPart->getData()->getPos();
	   BITMAP bm;
	   firstPart->getData()->getImage()->getBitmap(&bm);
	   headPos->x = fPartPos->x;
	   headPos->y = fPartPos->y - bm.bmHeight;
	   direction = 1;
	}
}
//Returns whether the snake is still alive
bool aSnake::isAlive(CPoint s, CPoint e)
{
	
	bool alive = true;
	snakeList.reset();
	CNode * head = snakeList.nextNode();
	CNode * aCurr = snakeList.nextNode();
	while(aCurr != NULL){
		bool ans = collidePart(head, aCurr);

		if(ans){
			alive = false;
		}

	}
	CPoint * headPos =head->getData()->getPos();

	if((headPos->x < s.x)||(headPos->x > e.x)||(headPos->y <s.y)||(headPos->y > e.y)){
		alive = false;
	}
	return alive;
}

// Returns the current score of the snake
int aSnake::getScore(void)
{
	return score;
}

// Set the current score
void aSnake::setScore(int s)
{
	score = s;
}

void aSnake::draw(CDC * pDC)
{
	CNode aCurr = snakeList.nextNode();

	while(aCurr != NULL){
		(aCurr.getData()).draw(pDC);
		aCurr = snakeList.nextNode();
	}
}

// Grows our snake by one unit
void aSnake::Grow(CBitmap img)
{
   SnakePart aPart(pos,2,img);
   CNode next = snakeList.nextNode()
   
	   if(next != NULL){
           snakeList.Add(aPart);
	   }
   snakeList.reset();

}

// Shrink the snake by one unit
void aSnake::Shrink(void)
{
	CNode next = snakeList.nextNode();
	if(next != NULL){
	   snakeList.remove();
	}
	snakeList.reset();
}

// Determine if the snakes hits an item
bool aSnake::collision(Food aFood)
{
	bool hit = false
	CPoint foodPos = aFood.getPos();
	snakeList.reset();
	CNode * head = snakeList.nextNode();
	CPoint * headPos = head->getData()->getPos();
	BITMAP bm;
	head->getData()->getImage()->getBitmap(&bm);

    if((headPos->x <= foodPos->x)&&( headPos->x + bm.bmWidth >= foodPos->x )&&(headPos->y <= foodPos->y)&&(headPos.y +bm.bmHeight >= foodPos->y )){
		 hit = true;
	}
    
	return hit;
}

// Move the snake forward by one body length in its current direction
void aSnake::move(void)
{
	BITMAP bm;
	CNode * tail = snakeList.removeLast();
	CNode * tail2 = snakeList.removeLast();

	SnakePart * a = tail->getData();
	a->setPos(tail2->getData()->getPos());
	tail->setData(a);

	snakeList.addLast(tail);
	snakeList.reset();
	CNode * head = snakeList.nextNode();
	CPoint  * headPos = head->getData()->getPos();
	tail2->getData()->setPos(headPos);
	headPos.getImage()->getBitmap(&bm);
	if(direction == 0){
	  headPos->y += bm.bmHeight;
	} else if(direction == 1){
	  headPos->y -= bm.bmHeight;
	}else if(direction == 2){
		headPos->x +=bm.bmWidth;

	}else{
		headPos->x -= bm.bmWidth;
	}
	head->getData()->setPos(new CPoint(headPos));
}

// Determine if two parts of the snake hit each other
bool aSnake::collidePart(CNode * head, CNode * aCurr)
{
	hit = false;
    
     CPoint * headPos = head->getData()->getPos();
	 CPoint * aCurrPos = aCurr->getData()->getPos();
	 BITMAP bm;
	 aCurr->getData()->getImage()->getBitmap(&bm);

	 if((aCurrPos->x <= headPos->x)&&( aCurrPos->x + bm.bmWidth >= headPos->x )&&(aCurrPos->y <= headPos->y)&&(aCurrPos.y +bm.bmHeight >= headPos->y )){
		 hit = true;
	 }
	return hit;
}

// Displays Snakey's current score to the screen
void aSnake::displayScore(CDC * pDC)
{
	CString s;
	s.Format(_T("%d"),getScore());
	pDC->TextOutW(text.X,text.Y,s,s.GetLength());
}

aSnake::aSnake(int startScore, Cpoint startPos, int startDirection, CPoint scorePos)
{
	 score = startScore;
     pos = startPos;
     direction = startDirection
     text = scorePos;
}
