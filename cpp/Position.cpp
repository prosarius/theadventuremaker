#include "../h/Position.h"
#include "../h/Animation.h"

Position::Position() {
}

Position::Position(const Position& orig) {
}

Position::~Position() {
}
void Position::setX(float x){
	this->x = x;
}
void Position::setY(float y){
	this->y = y;
}
void Position::setXY(float x, float y){
	this->x = x;
	this->y = y;
}
float Position::getX(){
	return this->x;
}
float Position::getY(){
	return this->y;
}
