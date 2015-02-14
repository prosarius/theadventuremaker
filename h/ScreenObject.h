#ifndef SCREENOBJECT_H
#define	SCREENOBJECT_H
#include <vector>
#include <string>

#include "Position.h"
#include "Animation.h"
#include "Screen.h"

using namespace std;
class Animation;
class Screen;
class ScreenObject {
	vector<Animation> animations;
	Animation* activeAnimation;
	void setDefaultAnimation();

protected:
	string name;
	Position position;
	int height, width;
	Screen* screen;

public:
	ScreenObject(string name, int width, int height, int x, int y, string texturePath);

	void addAnimation(Animation animation);
	void addAnimation(string texturePath, int speed = 60);
	void addAnimation(vector<string> texturePaths, int speed = 60);
	void addAnimations(vector<Animation> animations);

	void setName(string name);
	void setScreen(Screen* screen);

	Animation* getActiveAnimation();
	string getName();
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	Screen* getScreen();
};

#endif	/* SCREENOBJECT_H */

