#pragma once
#include "atltypes.h"

class Food
{
public:
	Food(void);
	~Food(void);
private:
	// Determines what type of food the object is
	int type;
	// Stores the picture of the current fruit
	CBitmap *image;
	// Stores the location of the food on screen
	CPoint pos;
	// Stores the current value the food adds to our snake
	int value;
public:
	// Returns the current position of the food
	CPoint getPos(void);
	// Set the current position of the food on screen
	void setPos(CPoint position);
	// Set the current value of this food
	void setValue(int val);
	// Returns the current value of this food
	int getValue(void);
	// Set the current type of this food
	void setType(int t, CBitmap img);
	// Returns the current food type
	int getType(void);
	// Draws the image of the food on screen
	void draw(CDC *pDC);
private:
	// Determine if current food is eaten
	bool eaten;
public:
	Food(CPoint position, CBitmap img, int val, int foodType);
};
