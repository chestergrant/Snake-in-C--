#include "StdAfx.h"
#include "SnakePart.h"

SnakePart::SnakePart(void)
: pos(0)
, bodyType(0)
, image(NULL)
{
}

SnakePart::~SnakePart(void)
{
}

// Gets the current position of this snake body part
CPoint SnakePart::getPos(void)
{
	return pos;
}

//Set the current  position of this snakes body part
void SnakePart::setPos(CPoint position)
{
	pos = position;
}

// Returns the current body type of this snake part
int SnakePart::getBodyType(void)
{
	return bodyType;
}

// Set the current body type of this snake body part
void SnakePart::setBodyType(int bType)
{
   bodyType = bType
}

//Returns the current image of the body part
CBitmap * SnakePart::getImage(void)
{
	return image;
}

// Sets the current image of the body part
void SnakePart::setImage(CBitmap * img)
{
	image = img;
}


// draws the body part to the screen
void SnakePart::Draw(CDC * pDC)
{
  BITMAP bm;
  image->GetBitmap(&bm);
  CDC dcMem;

  dcMem.CreateCompatibleDC(pDC);
  CBitmap* pOldBitmap = (CBitmap*)dcMem.SelectObject(image);
  
  pDC->BitBlt(pos.x,pos.y,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
}

 SnakePart::SnakePart(CPoint position, int bType, CBitmap * img)
{
	pos = position;
	bodyType = bType;
	image = img;
}
