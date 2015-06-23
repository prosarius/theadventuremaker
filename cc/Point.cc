#include "../h/Point.h"

using namespace std;

/* Constructors */
Point::Point(float x, float y) : valX(x), valY(y) {
	this->calcMagnitude();
}

/* setter */
void Point::setX(float x) {
	this->valX = x;
	this->calcMagnitude();
}
void Point::setY(float y) {
	this->valY = y;
	this->calcMagnitude();
}
void Point::setXY(float x, float y) {
	this->valX = x;
	this->valY = y;
	this->calcMagnitude();
}

/* getter */
float Point::getX() const {
	return this->valX;
}
float Point::getY() const {
	return this->valY;
}
float Point::getMagnitude() const {
	return this->magnitude;
}

/* operators */
Point Point::operator+(const Point &p) const {
    return Point(this->valX + p.valX , this->valY + p.valY);
}
Point Point::operator-(const Point &p) const {
    return Point(this->valX - p.valX , this->valY - p.valY);
}

bool Point::operator<(const Point &p) const {
    return (this->getMagnitude() < p.getMagnitude());
}

bool Point::operator>(const Point &p) const {
    return (this->getMagnitude() > p.getMagnitude());
}

bool Point::operator==(const Point &p) const {
    return (this->valX == p.valX && this->valY == p.valY);
}

bool Point::operator!=(const Point &p) const {
    return (this->valX != p.valX || this->valY != p.valY);
}

/* other methods */

void Point::calcMagnitude() {
	this->magnitude = sqrt(pow(this->valX, 2) + pow(this->valY, 2));
}

Point Point::getNearestPoint(float m, float n, bool asympt) const {
    if(asympt)
        return Point(n, this->valY);
    if(!m)
        return Point(this->valX, n);

    float newM = -1 / m;
    float newN = this->valY / (m * this->valX);

    return Point((newN - n) / (m - newM), ((m * newN) - (newM * n)) / (m - newM));

}


void Point::moveTo(const Point &to, float speed) {
    Point distance = to - *this;
//  cout << distance.magnitude << " | " << speed << endl;
    if(distance.magnitude <= speed) {
        this->valX = to.valX;
        this->valY = to.valY;
        return;
    }
    Point fak( (distance.valX > 0) ? 1 : -1 , (distance.valY > 0) ? 1 : -1 );
	if(!distance.valX)
		/* Just move in y direction */
        this->valY = this->valY + fak.valY * speed;
	else if(!distance.valY)
		/* Just move in x direction */
        this->valX = this->valX + fak.valX * speed;
	else
		/* move x and y */
		this->setXY(this->valX + (float(distance.valX) / distance.magnitude * speed),
				    this->valY + (float(distance.valY) / distance.magnitude * speed));

}
