#ifndef SCREENOBJECT_H
#define	SCREENOBJECT_H

#include <vector>
#include <string>

#include "Point.h"
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
    Point size;
	Point position;
    Point pivot;
    Point hitbox;
    Point renderSize;
	Screen* screen;

public:
	ScreenObject(const string &name, const int width, const int height, const int x, const int y, const string &texturePath, float pivotX = 0, float pivotY = 0, float hitboxWidth = 0, float hitboxHeight = 0);

	void addAnimation(Animation animation);
	void addAnimation(const string &texturePath, int speed = 60);
	void addAnimation(const vector<string> &texturePaths, int speed = 60);
	void addAnimations(vector<Animation> animations);

	void setName(const string &name);
	void setScreen(Screen* screen);
    void setPivot(const float &x, const float &y);
    void setHitbox(float width, float height);

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
    float getHitboxHeight() const;
    float getHitboxWidth() const;
    vector<Point> getHitboxPoints() const;

    static bool greaterThan(ScreenObject* a, ScreenObject* b);
    bool collides(float x, float y) const;
};

#endif	/* SCREENOBJECT_H */

