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
}
void Screen::addScreenObject(ScreenObject* screenObject) {
	this->screenObjects.push_back(screenObject);
	screenObject->setScreen(this);
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

/* other methods */

void Screen::sortScreenObjects() {
    sort(this->screenObjects.begin(), this->screenObjects.end(), ScreenObject::greaterThan);
}

bool Screen::isWalkable(float x, float y) const {
    if(this->collidesWith(x, y))
        return false;
    return true;
}

Position Screen::getNearestPosition(float x, float y) const {
    ScreenObject* obj = this->collidesWith(x, y);
    if(!obj)
        return Position(x, y);

    Position target(x, y);
    Position retPos = target.getNearestPosition(0, obj->getPosX() - (obj->getHitboxWidth() / 2), true);

    Position temp = target.getNearestPosition(0, obj->getPosX() + (obj->getHitboxWidth() / 2), true);
    if((target - temp) < (target - retPos))
        retPos = temp;

    temp = target.getNearestPosition(0, obj->getPosY() - (obj->getHitboxHeight() / 2));
    if((target - temp) < (target - retPos))
        retPos = temp;

    temp = target.getNearestPosition(0, obj->getPosY() + (obj->getHitboxHeight() / 2));
    if((target - temp) < (target - retPos))
        retPos = temp;

    return retPos;
}

ScreenObject* Screen::collidesWith(float x, float y) const {
    for(auto obj: this->screenObjects)
        if(obj->collides(x, y))
            return obj;
    return NULL;
}
