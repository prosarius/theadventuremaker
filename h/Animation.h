#ifndef ANIMATION_H
#define	ANIMATION_H
#include <string>
#include <list>
#include <cmath>
#include <vector>

#include "ScreenObject.h"

using namespace std;
class ScreenObject;
class Animation {
	int length;
	int speed;
	bool running;
	string name;
	vector<string> images;
	vector<ScreenObject*> screenObjects;
	int activeImage;
public:
	Animation(string name, string image, int speed = 60,  ScreenObject* screenObject = NULL);
	Animation(string name, vector<string> images, int speed = 60, ScreenObject* = NULL);

	void addScreenObject(ScreenObject* object);
	vector<ScreenObject*> getScreenObjects();
	void addImage(string texturePath);
	// void removeImage(string texturePath);
	void addImages(vector<string> texturePaths);
	int getLength();
	string getActiveImage();
	void startRunning();
	void stopRunning();
	void tick();
};

#endif	/* ANIMATION_H */

