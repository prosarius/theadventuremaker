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
    Position pivot;
    Position size;
    Position renderSize;
	Screen* screen;

public:
	ScreenObject(const string &name, const int &width, const int &height, const int &x, const int &y, const string &texturePath);

	void addAnimation(Animation animation);
	void addAnimation(const string &texturePath, int speed = 60);
	void addAnimation(const vector<string> &texturePaths, int speed = 60);
	void addAnimations(vector<Animation> animations);

	void setName(const string &name);
	void setScreen(Screen* screen);
    void setPivot(const float &x, const float &y);

	Animation* getActiveAnimation() const;
	string getName() const;
	int getPosX() const;
	int getPosY() const;
	int getWidth() const;
	int getHeight() const;
    int getRenderHeight() const;
    int getRenderWidth() const;
    float getPivotX() const;
    float getPivotY() const;
	Screen* getScreen() const;
};

#endif	/* SCREENOBJECT_H */

