#include "../h/Screen.h"

using namespace std;
Screen::Screen(const string &name, const int &width, const int &height, const int &stopY, const float &sizefactor, const string &texturePath)
   	: name(name), size(width, height), stopY(stopY), sizeFactor(sizeFactor), backgroundPath(texturePath) {
}

/* setters */
void Screen::setWidth(const int &x) {
    this->size.setX(x);
}
void Screen::setHeight(const int &y) {
    this->size.setY(y);
}
void Screen::setStopY(const int &stopY) {
    this->stopY = stopY;
}
void Screen::setSizeFactor(const float &sizeFactor) {
    this->sizeFactor = sizeFactor;
}
void Screen::addPlayer(Character* character) {
	/* test if already added */
	if(find(this->screenObjects.begin(), this->screenObjects.end(), character) == this->screenObjects.end())
		this->screenObjects.push_back(character);
	this->player = character;
	character->setScreen(this);
}
void Screen::addScreenObject(ScreenObject* screenObject) {
	this->screenObjects.push_back(screenObject);
}

/* getters */
int Screen::getWidth() const {
    return this->size.getX();
}
int Screen::getHeight() const {
    return this->size.getY();
}
string Screen::getName() const {
	return name;
}
int Screen::getStopY() const {
	return this->stopY;
}
Character* Screen::getPlayer() const {
	return this->player;
}
float Screen::getSizeFactor() const {
    return this->sizeFactor;
}
vector<ScreenObject*> Screen::getScreenObjects() const {
	return this->screenObjects;
}
string Screen::getBackgroundPath() const {
	return this->backgroundPath;
}
