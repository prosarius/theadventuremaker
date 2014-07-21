#include "../h/Character.h"
#include "../h/defines.h"

Character::Character(std::string name) {
	this->name = name;
}
Character::~Character() {
}
std::string Character::getName(){
	return this->name;
}

void Character::setName(std::string name){
	this->name = name;
}
void Character::move(int direction){
	float currX = this->position.getX();
	float currY = this->position.getY();
	if(direction | NORTHEAST) this->position.setXY(currX - 0.707, currY + 0.707);
	else if(direction | SOUTHEAST) this->position.setXY(currX + 0.707, currY + 0.707);
	else if(direction | SOUTHWEST) this->position.setXY(currX + 0.707, currY - 0.707);
	else if(direction | NORTHWEST) this->position.setXY(currX - 0.707, currY - 0.707);
	else if(direction | NORTH) this->position.setX(currX - 1);
	else if(direction | EAST) this->position.setY(currY + 1);
	else if(direction | SOUTH) this->position.setX(currX + 1);
	else if(direction | WEST) this->position.setY(currY - 1);
}
void Character::turn(int direction){
	
	this->currentAnimation = this->directionAnimation.at(direction);
}
