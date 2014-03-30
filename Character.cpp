/* 
 * File:   Character.cpp
 * Author: morion
 * 
 * Created on 28. März 2014, 20:21
 */

#include "Character.h"

Character::Character() {
}

Character::Character(const Character& orig) {
}

Character::~Character() {
}
void Character::move(int x, int y){
	
}
void Character::turn(int direction){
	
	this->currentAnimation = &this->directionAnimation.at(direction);
}