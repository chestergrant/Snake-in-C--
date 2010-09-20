#include "StdAfx.h"
#include "Food.h"

Food::Food(void)
: type(0)
, image(NULL)
, pos(0)
, value(0)
, eaten(false)
{
}

Food::~Food(void)
{
}

// Returns the current position of the food
CPoint Food::getPos(void)
{
	return pos;
}

// Set the current position of the food on screen
void Food::setPos(CPoint position)
{
	 pos = position;
}

// Set the current value of this food
void Food::setValue(int val)
{
	value = val;
}

// Returns the current value of this food
int Food::getValue(void)
{
	return value;
}

// Set the current type of this food
void Food::setType(int t, CBitmap img)
{
	type = t;
	image = img;
}

// Returns the current food type
int Food::getType(void)
{
	return type;
}

// Draws the image of the food on screen
void Food::draw(CDC * pDC)
{
  BITMAP bm;
  image->GetBitmap(&bm);
  CDC dcMem;

  dcMem.CreateCompatibleDC(pDC);
  CBitmap* pOldBitmap = (CBitmap*)dcMem.SelectObject(image);
  
  pDC->BitBlt(pos.x,pos.y,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
}

Food::Food(CPoint position, CBitmap img, int val, int foodType)
{
	pos = position;
	image = img;
	value = val;
	type = foodType;
}
