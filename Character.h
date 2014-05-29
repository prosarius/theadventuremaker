/* 
 * File:   Character.h
 * Author: morion
 *
 * Created on 28. März 2014, 20:21
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#include <array>
#include <stdlib.h>
#include "Position.h"
#include "Animation.h"
#include "ScreenObject.h"

class Character : ScreenObject{
public:
	std::array<Animation*,4> directionAnimation;
	Animation* currentAnimation;
	Character(std::string name);
	std::string getName();
	void setName(std::string name);
	virtual ~Character();
	void move(int direction);
	void turn(int direction);
private:
	std::string name;
	Position position;
};

#endif	/* CHARACTER_H */

