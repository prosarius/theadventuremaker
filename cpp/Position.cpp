#include "../h/Position.h"

using namespace std;
Position::Position() : valX(0), valY(0) {
}
Position::Position(float x, float y) : valX(x), valY(y) {
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
	cout << x << typeid(x).name() << " | " << y << typeid(y).name() << endl;
	this->valY = y;
	this->calcMagnitude();
}
float Position::getX() {
	cout << "getX" << endl;
	return this->valX;
}
float Position::getY() {
	return this->valY;
}
void Position::calcMagnitude() {
	//this->magnitude = sqrt(this->valX * this->valX + this->valY * this->valY);
}
float Position::getMagnitude() {
	return this->magnitude;
}
