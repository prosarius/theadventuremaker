#ifndef SCREENOBJECT_H
#define	SCREENOBJECT_H
#include <vector>
#include <string>
#include "Position.h"
#include "Animation.h"

using namespace std;
class Animation;
class ScreenObject {
	vector<Animation> animations;
	Animation* activeAnimation;
	void setDefaultAnimation();
public:
	ScreenObject(int width, int height);
	ScreenObject(string name, int width, int height);
	ScreenObject(string name, int width, int height, string path);
	ScreenObject(string name, int width, int height, vector<string> paths);
	ScreenObject(string name, int width, int height, Animation animation);
	ScreenObject(string name, int width, int height, vector<Animation> animations);
	ScreenObject(string name, int width, int height, vector<vector<string>> paths);

	Animation* addAnimation();
	Animation* addAnimation(Animation animation);
	Animation* addAnimation(string path);
	Animation* addAnimation(vector<string> paths);
	void addAnimations(vector<Animation> animations);
	void addAnimations(vector<vector<string>> paths);

	void setName(string name);

	string getName();
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	Animation* getActiveAnimation();
protected:
	Position position;
	int height, width;
	string name;
};

#endif	/* SCREENOBJECT_H */

