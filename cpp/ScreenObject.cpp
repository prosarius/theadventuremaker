#include "../h/ScreenObject.h"

using namespace std;
/* Constructors */
ScreenObject::ScreenObject(string name, int width, int height, int x, int y, string texturePath)
	: name(name), width(width), height(height), position(x, y), screen(NULL) {
	this->animations.push_back(Animation("", texturePath, 60, this));
	this->setDefaultAnimation();
}

/* private functions */
void ScreenObject::setDefaultAnimation() {
	this->activeAnimation = &(this->animations.front());
}

/* setter */
void ScreenObject::addAnimation(Animation animation) {
	this->animations.push_back(animation);
	animation.addScreenObject(this);
}
void ScreenObject::addAnimation(string texturePath, int speed) {
	this->animations.push_back(Animation("", texturePath, speed, this));
}
void ScreenObject::addAnimation(vector<string> texturePaths, int speed) {
	this->animations.push_back(Animation("", texturePaths, speed, this));
}
void ScreenObject::addAnimations(vector<Animation> animations) {
	for(auto animation: animations) {
		animation.addScreenObject(this);
		this->animations.push_back(animation);
	}
}

void ScreenObject::setName(string name) {
	this->name = name;
}
void ScreenObject::setScreen(Screen* screen) {
	this->screen = screen;
}


/* getter */
Animation* ScreenObject::getActiveAnimation() {
	return this->activeAnimation;
}
string ScreenObject::getName() {
	return this->name;
}
int ScreenObject::getPosX() {
	return this->position.getX();
}
int ScreenObject::getPosY() {
	return this->position.getY();
}
int ScreenObject::getWidth() {
	return this->width;
}
int ScreenObject::getHeight() {
	return this->height;
}
Screen* ScreenObject::getScreen() {
	return this->screen;
}
