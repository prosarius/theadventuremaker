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
#include "Position.h"

using namespace std;
class Character;
class ScreenObject;
class Screen {
    Position size;
	Character* player;
	vector<ScreenObject*> screenObjects;
	string name, backgroundPath;
    float sizeFactor;
	int stopY;
public:
	Screen(const string &name, const int &width, const int &height, const int &stopY, const float &sizeFactor, const string &texturePath);

	void setWidth(const int &x);
	void setHeight(const int &y);
    void setStopY(const int &stopY);
    void setSizeFactor(const float &sizeFactor);
	void setTexture(const string &texturePath);
	void addPlayer(Character* character);
	void addScreenObject(ScreenObject* screenObject);

	int getWidth() const;
	int getHeight() const;
	string getName() const;
    float getSizeFactor() const;
	int getStopY() const;
	Character* getPlayer() const;
	vector<ScreenObject*> getScreenObjects() const;
	string getBackgroundPath() const;

    void sortScreenObjects();
};

#endif	/* SCREEN_H */
