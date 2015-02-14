#ifndef POSITION_H
#define	POSITION_H

#include <cmath>
#include <iostream>
#include <typeinfo>

class Position {
	void calcMagnitude();
	float valX, valY;
	float magnitude;
public:
	Position(float x = 0, float y = 0);
	void setX(float x);
	void setY(float y);
	void setXY(float x, float y);
	float getX();
	float getY();
	float getMagnitude();
};

#endif	/* POSITION_H */

