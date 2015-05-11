#include "../h/Position.h"

using namespace std;

/* Constructors */
Position::Position(float x, float y) : valX(x), valY(y) {
	this->calcMagnitude();
}

/* setter */
void Position::setX(float x) {
	this->valX = x;
	this->calcMagnitude();
}
void Position::setY(float y) {
	this->valY = y;
	this->calcMagnitude();
}
void Position::setXY(float x, float y) {
	this->valX = x;
	this->valY = y;
	this->calcMagnitude();
}

/* getter */
float Position::getX() const {
	return this->valX;
}
float Position::getY() const {
	return this->valY;
}
float Position::getMagnitude() const {
	return this->magnitude;
}

/* operators */
Position Position::operator+(const Position &p) const {
    return Position(this->valX + p.valX , this->valY + p.valY);
}
Position Position::operator-(const Position &p) const {
    return Position(this->valX - p.valX , this->valY - p.valY);
}

bool Position::operator<(const Position &p) const {
    return (this->getMagnitude() < p.getMagnitude());
}

bool Position::operator>(const Position &p) const {
    return (this->getMagnitude() > p.getMagnitude());
}

/* other methods */

void Position::calcMagnitude() {
	this->magnitude = sqrt(pow(this->valX, 2) + pow(this->valY, 2));
}

Position Position::getNearestPosition(float m, float n, bool asympt) const {
    if(asympt)
        return Position(n, this->valY);
    if(!m)
        return Position(this->valX, n);

    float newM = -1 / m;
    float newN = this->valY / (m * this->valX);

    return Position((newN - n) / (m - newM), ((m * newN) - (newM * n)) / (m - newM));

}
