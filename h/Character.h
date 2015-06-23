#ifndef CHARACTER_H
#define	CHARACTER_H

#include <array>
#include <vector>
#include <list>
#include <queue>
#include <stdlib.h>
#include <iostream>

#include "ScreenObject.h"
#include "Animation.h"
#include "Point.h"

using namespace std;
class Character : public ScreenObject {
	Animation* currentAnimation;
	Point target;
    list<Point> path;
	float speed;
public:
	Character(const string &name, const int &width, const int &height, const int &x, const int &y, const string &texturePath, float speed = 1, float pivotX = 0, float pivotY = 0, float hitboxWidth = 0, float hitboxHeight = 0);

	void setPoint(const Point &osition);
	void setPoint(const float &x, const float &y);
	void setTarget(const float &x, const float &y);
	void setSpeed(float speed);

	Point* getPoint();
	float getSpeed() const;

	void tick();
	void startRunning();
	void stopRunning();
    bool collidesWithSomething(float x, float y) const;
};

#endif	/* CHARACTER_H */

