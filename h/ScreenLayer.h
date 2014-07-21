#ifndef SCREENLAYER_H
#define	SCREENLAYER_H
#include <vector>
#include <stdlib.h>
#include "Character.h"
#include "ScreenItem.h"
#include "Image.h"
#include "Screen.h"
using namespace std;
class ScreenLayer {
public:
	ScreenLayer();
	ScreenLayer(string name = NULL);
	string getName();
	void setName(string name);
	vector<Character*> getAllCharacters();
	vector<string> getAllCharacterNames();
	virtual ~ScreenLayer();
	void setScreen(Screen* screen);
	Screen* getScreen();
	void addCharacter(Character* character);
	void addItem(ScreenItem* item);
private:
	Screen* screen;
	string name;
	Image background;
	vector<Character*> characters;
	vector<ScreenItem*> items;	
};

#endif	/* SCREENLAYER_H */

