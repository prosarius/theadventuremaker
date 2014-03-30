/* 
 * File:   Character.h
 * Author: morion
 *
 * Created on 28. März 2014, 20:21
 */

#ifndef CHARACTER_H
#define	CHARACTER_H
#include <array>

class Character : ScreenObject{
public:
	array<Animation*,4> directionAnimation;
	Animation* currentAnimation;
	Character();
	Character(const Character& orig);
	virtual ~Character();
	void move(int x, int y);
	void turn(int direction);
private:

};

#endif	/* CHARACTER_H */

