#ifndef SCREEN_H
#define	SCREEN_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#ifndef SCREENOBJECT_H
#include "Character.h"
#endif

#include "ScreenObject.h"

using namespace std;
class Character;
class ScreenObject;
class Screen {
	int width, height;
	Character* player;
	vector<ScreenObject*> screenObjects;
	string name, backgroundPath;
	int stopY;
public:
	Screen(string name, int width, int height, int stopY, string texturePath);

	void setWidth(int x);
	void setHeight(int y);
	void setTexture(string texturePath);
	void addPlayer(Character* character);
	void addScreenObject(ScreenObject* screenObject);

	int getWidth();
	int getHeight();
	string getName();
	int getStopY();
	Character* getPlayer();
	vector<ScreenObject*> getScreenObjects();
	string getBackgroundPath();
};

#endif	/* SCREEN_H */
