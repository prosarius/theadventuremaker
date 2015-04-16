#ifndef CHARACTER_H
#define	CHARACTER_H

#include <array>
#include <vector>
#include <stdlib.h>
#include <iostream>

#include "ScreenObject.h"
#include "Animation.h"
#include "Position.h"

using namespace std;
class Character : public ScreenObject {
	Animation* currentAnimation;
	Position target;
	float speed;
public:
	Character(const string &name, const int &width, const int &height, const int &x, const int &y, const string &texturePath, const float &speed = 1);

	void setPosition(const Position &osition);
	void setPosition(const float &x, const float &y);
	void setTarget(const float &x, const float &y);
	void setSpeed(const float &speed);

	Position* getPosition();
	float getSpeed() const;

	void tick();
	void startRunning();
	void stopRunning();
};

#endif	/* CHARACTER_H */

