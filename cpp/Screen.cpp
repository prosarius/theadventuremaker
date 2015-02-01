#include "../h/Screen.h"

using namespace std;
Screen::Screen(int width, int height) : width(width), height(height) {
}
Screen::Screen(string name, int width, int height)
	: name(name), width(width), height(height) {
}
Screen::Screen(string name, int width, int height, string backgroundPath)
   	: name(name), width(width), height(height), backgroundPath(backgroundPath) {
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
std::string Screen::getName() {
	return name;
}
void Screen::addPlayer(Character* character) {
	if(find(this->screenObjects.begin(), this->screenObjects.end(), character) == this->screenObjects.end())
		this->screenObjects.push_back(character);
	this->player = character;
}
Character* Screen::getPlayer() {
	return this->player;
}
void Screen::addScreenObject(ScreenObject* screenObject) {
	this->screenObjects.push_back(screenObject);
}
/*
vector<Character*> Screen::getAllCharacters() {
	return this->characters;
}
*/
/*
vector<string> Screen::getAllCharacterNames() {
	vector<string> names;
	for(Character* character: this->characters) {
			names.push_back(character->getName());
	}
	return names;
}
*/
vector<ScreenObject*> Screen::getScreenObjects() {
	return this->screenObjects;
}
string Screen::getBackgroundPath() {
	return this->backgroundPath;
}
