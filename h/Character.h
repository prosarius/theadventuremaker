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
	void resize();
public:
	Character(string name, int width, int height, int x, int y, string texturePath);

	void setPosition(Position position);
	void setPosition(float x, float y);
	void setTarget(float x, float y);
	Position* getPosition();
	void tick();
	void startRunning();
	void stopRunning();
};

#endif	/* CHARACTER_H */

