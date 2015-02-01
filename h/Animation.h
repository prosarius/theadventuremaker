#ifndef ANIMATION_H
#define	ANIMATION_H
#include <string>
#include "ScreenObject.h"
#include "Image.h"
#include <list>
#include <cmath>
#include <vector>

using namespace std;
class Image;
class ScreenObject;
class Animation {
public:
	Animation(ScreenObject* screenObject = NULL);
	Animation(string name, ScreenObject* screenObject = NULL);
	Animation(string name, string image, ScreenObject* screenObject = NULL);
	Animation(string name, vector<string> images, ScreenObject* = NULL);

	void addScreenObject(ScreenObject* object);
	vector<ScreenObject*> getScreenObjects();
	void addImage(string path);
	// void removeImage(string path);
	void addImages(vector<string> paths);
	int getLength();
	string getActiveImage();
	void startRunning();
	void stopRunning();
	void tick();
private:
	int length;
	int speed;
	bool running;
	string name;
	vector<string> images;
	vector<ScreenObject*> screenObjects;
	int activeImage;
};

#endif	/* ANIMATION_H */

