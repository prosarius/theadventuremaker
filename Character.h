/* 
 * File:   Character.h
 * Author: morion
 *
 * Created on 28. März 2014, 20:21
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#include <array>
#include "Position.h"
#include "Animation.h"
#include "ScreenObject.h"

class Character : ScreenObject{
public:
	std::array<Animation*,4> directionAnimation;
	Animation* currentAnimation;
	Character();
	Character(const Character& orig);
	virtual ~Character();
	void move(int direction);
	void turn(int direction);
private:
	Position position;
};

#endif	/* CHARACTER_H */

