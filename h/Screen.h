#ifndef SCREEN_H
#define	SCREEN_H
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Character.h"
using namespace std;

class Character;
class Screen {
	int width, height;
	Character* player;
	vector<ScreenObject*> screenObjects;
	string name, backgroundPath;
	int stopY;
public:
	Screen(int width, int height);
	Screen(string name, int width, int height, string path);
	Screen(string name, int width, int height);
	void setWidth(int x);
	void setHeight(int y);
	void addPlayer(Character*);
	void addScreenObject(ScreenObject* screenObject);
	int getWidth();
	int getHeight();
	string getName();
	int getStopY();
	Character* getPlayer();
	//vector<Character*> getAllCharacters();
	//vector<string> getAllCharacterNames();
	void setTexture(string path);
	vector<ScreenObject*> getScreenObjects();
	string getBackgroundPath();
};

#endif	/* SCREEN_H */
