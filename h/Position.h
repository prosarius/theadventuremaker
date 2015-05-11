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

    float getX() const;
	float getY() const;
	float getMagnitude() const;

    Position operator+(const Position &p) const;
    Position operator-(const Position &p) const;

    bool operator<(const Position &p) const;
    bool operator>(const Position &p) const;

    Position getNearestPosition(float m, float n, bool asympt = false) const;
};

#endif	/* POSITION_H */

