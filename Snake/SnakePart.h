#pragma once
#include "atltypes.h"

class SnakePart
{
public:
	SnakePart(void);
	~SnakePart(void);
private:
	// Position of this current body part
	CPoint pos;
	// Determine whether current body type is a head or a tail or middle section
	int bodyType;
public:
	// Gets the current position of this snake body part
	CPoint getPos(void);
	void setPos(CPoint position);
	// Returns the current body type of this snake part
	int getBodyType(void);
	// Set the current body type of this snake body part
	void setBodyType(int bType);
private:
	// Stores the location of the image to be drawn for this body part
	CBitmap *image;
public:
	CBitmap * getImage(void);
	// Sets the current image of the body part
	void setImage(CBitmap * img);
	// draws the body part to the screen
	void Draw(CDC * pDC);
	SnakePart(CPoint position, int bType, CBitmap * img);
};
