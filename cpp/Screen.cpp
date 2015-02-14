#include "../h/Screen.h"

using namespace std;
Screen::Screen(string name, int width, int height, int stopY, string texturePath)
   	: name(name), width(width), height(height), stopY(stopY), backgroundPath(texturePath) {
}
int Screen::getWidth() {
    return this->width;
}
int Screen::getHeight() {
    return this->height;
}
void Screen::setWidth(int x) {
    this->width = x;
}
void Screen::setHeight(int y) {
    this->height = y;
}
string Screen::getName() {
	return name;
}
int Screen::getStopY() {
	return this->stopY;
}
void Screen::addPlayer(Character* character) {
	/* test if already added */
	if(find(this->screenObjects.begin(), this->screenObjects.end(), character) == this->screenObjects.end())
		this->screenObjects.push_back(character);
	this->player = character;
	character->setScreen(this);
}
Character* Screen::getPlayer() {
	return this->player;
}
void Screen::addScreenObject(ScreenObject* screenObject) {
	this->screenObjects.push_back(screenObject);
}
vector<ScreenObject*> Screen::getScreenObjects() {
	return this->screenObjects;
}
string Screen::getBackgroundPath() {
	return this->backgroundPath;
}
