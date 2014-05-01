#ifndef SCREEN_H
#define	SCREEN_H
#include <stdlib.h>
#include <vector>
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
	void addLayer();
	ScreenLayer* getLayer(int index);
private:
	int sizeX, sizeY, offsetX, offsetY;
	vector<ScreenLayer> layers;
};

#endif	/* SCREEN_H */