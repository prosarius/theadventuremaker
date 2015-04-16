#include "../h/Position.h"

using namespace std;
Position::Position(float x, float y) : valX(x), valY(y) {
	this->calcMagnitude();
}

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
float Position::getX() const {
	return this->valX;
}
float Position::getY() const {
	return this->valY;
}
void Position::calcMagnitude() {
	this->magnitude = sqrt(pow(this->valX, 2) + pow(this->valY, 2));
}
float Position::getMagnitude() const {
	return this->magnitude;
}
Position Position::operator+(const Position &p) const {
    return Position(this->valX + p.valX , this->valY + p.valY);
}
Position Position::operator-(const Position &p) const {
    return Position(this->valX - p.valX , this->valY - p.valY);
}
