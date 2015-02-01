#ifndef CHARACTER_H
#define	CHARACTER_H
#include <array>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Position.h"
#include "Animation.h"
#include "ScreenObject.h"
#include "Screen.h"
#include "defines.h"

using namespace std;
class Screen;
class Character : public ScreenObject{
public:
	using ScreenObject::ScreenObject;
	void setPosition(Position position);
	void setPosition(float x, float y);
	void move(int direction);
	void turn(int direction);
	void setTarget(float x, float y);
	Position* getPosition();
	int getDirection();
	void setDirection(int direction);
	void tick();
private:
	int direction;
	std::array<Animation*,4> directionAnimation;
	Animation* currentAnimation;
	Position position;
	vector<Screen*> screens;
	Position target;
};

#endif	/* CHARACTER_H */

