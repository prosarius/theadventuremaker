#ifndef SCREEN_H
#define	SCREEN_H

#include <stdlib.h>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

#include "Graph.h"

#ifndef SCREENOBJECT_H
#include "Character.h"
#endif /* SCREENOBJECT_H */

#include "ScreenObject.h"
#include "Point.h"

using namespace std;
class Character;
class ScreenObject;
class Screen {
	string name;
    Point size;
	int stopY;
    float sizeFactor;
    string backgroundPath;
	Character* player;
	vector<ScreenObject*> screenObjects;

    ScreenObject* collidesWith(float x, float y) const;
    ScreenObject* collidesWith(Point from, Point to) const;
    Graph buildGraph(Point from, Point to, set<ScreenObject*> *collidingObjects) const;
public:
	Screen(const string &name, const int width, const int height, const int stopY, const float sizeFactor, const string &texturePath);

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
    bool isWalkable(float x, float y) const;
    Point getNearestPoint(float x, float y) const;
    list<Point> getShortestWay(Point from, Point to) const;
};

#endif	/* SCREEN_H */
