#ifndef SCREEN_H
#define	SCREEN_H
#include <stdlib.h>
#include <iostream>
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
	void setImagePath(string path);
	string getImagePath();
private:
	int sizeX, sizeY, offsetX, offsetY;
	string imagePath;
};

#endif	/* SCREEN_H */