#ifndef POINT_H
#define	POINT_H

#include <cmath>
#include <iostream>
#include <typeinfo>

class Point {
	void calcMagnitude();
	float valX, valY;
	float magnitude;
public:
	Point(float x = 0, float y = 0);

    void setX(float x);
	void setY(float y);
	void setXY(float x, float y);

    float getX() const;
	float getY() const;
	float getMagnitude() const;

    Point operator+(const Point &p) const;
    Point operator-(const Point &p) const;

    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;
    bool operator==(const Point &p) const;
    bool operator!=(const Point &p) const;

    Point getNearestPoint(float m, float n, bool asympt = false) const;
    void moveTo(const Point &to, float v);
};

#endif	/* POINT_H */

