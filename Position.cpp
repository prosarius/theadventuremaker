/* 
 * File:   Position.cpp
 * Author: morion
 * 
 * Created on 1. Mai 2014, 05:12
 */

#include "Position.h"
#include "Animation.h"

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