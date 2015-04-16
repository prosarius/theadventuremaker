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
	Animation(const string &name, const string &image, const int &speed = 60,  ScreenObject* screenObject = NULL);
	Animation(const string &name, const vector<string> &images, const int &speed = 60, ScreenObject* screenObject = NULL);

	void addScreenObject(ScreenObject* object);
	void addImage(const string &texturePath);
	// void removeImage(string texturePath);
	void addImages(const vector<string> &texturePaths);
	void setSpeed(const int &speed);

	vector<ScreenObject*> getScreenObjects() const;
	int getLength() const;
	string getActiveImage() const;
	int getSpeed() const;

	void startRunning();
	void stopRunning();
	void tick();
};

#endif	/* ANIMATION_H */

