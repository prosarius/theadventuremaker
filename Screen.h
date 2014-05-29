#ifndef SCREEN_H
#define	SCREEN_H
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Character.h"
#include "ScreenLayer.h"
using namespace std;
class Screen {
public:
	Screen();
	Screen(const Screen& orig);
	virtual ~Screen();
	void setSizeX(int x);
	void setSizeY(int y);
	int getSizeX();
	int getSizeY();
	void addLayer(string name);
	vector<ScreenLayer*> getAllLayers();
	vector<Character*> getAllCharacters();
	vector<string> getAllLayerNames();
	vector<string> getAllCharacterNames();
	ScreenLayer* getLayer(int index);
	ScreenLayer* getLastLayer();
private:
	int sizeX, sizeY, offsetX, offsetY;
	vector<ScreenLayer> layers;
};

#endif	/* SCREEN_H */