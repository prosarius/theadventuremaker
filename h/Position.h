#ifndef POSITION_H
#define	POSITION_H

#include <iostream>
#include <typeinfo>

class Position {
	void calcMagnitude();
	float valX, valY;
	float magnitude;
public:
	Position();
	Position(float, float);
	void setX(float);
	void setY(float);
	void setXY(float, float);
	float getX();
	float getY();
	float getMagnitude();
};

#endif	/* POSITION_H */

