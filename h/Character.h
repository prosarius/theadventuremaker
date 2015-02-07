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
	int direction;
	array<Animation*,4> directionAnimation;
	Animation* currentAnimation;
	Position target;
	vector<Screen*> screens;
public:
	Character(int width, int height);
	Character(string name, int width, int height);
	Character(string name, int width, int height, string path);
	Character(string name, int width, int height, vector<string> paths);
	Character(string name, int width, int height, Animation animation);
	Character(string name, int width, int height, vector<Animation> animations);
	Character(string name, int width, int height, vector<vector<string>> paths);

	void setPosition(Position position);
	void setPosition(float x, float y);
	void move(int direction);
	void turn(int direction);
	void setTarget(float x, float y);
	Position* getPosition();
	int getDirection();
	void setDirection(int direction);
	void tick(Screen* screen);
	void startRunning();
	void stopRunning();
};

#endif	/* CHARACTER_H */

