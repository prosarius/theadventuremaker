#include "../h/ScreenObject.h"

using namespace std;
ScreenObject::ScreenObject(int width, int height) : name(""), width(width), height(height) {
}
ScreenObject::ScreenObject(string name, int width, int height) : name(name), width(width), height(height) {
}
ScreenObject::ScreenObject(string name, int width, int height, string path) : name(name), width(width), height(height), position(100, 500) {
	this->animations.push_back(Animation("", path, this));
	this->setDefaultAnimation();
}
ScreenObject::ScreenObject(string name, int width, int height, vector<string> paths) : name(name), width(width), height(height) {
	this->animations.push_back(Animation("", paths, this));
	this->setDefaultAnimation();
}
ScreenObject::ScreenObject(string name, int width, int height, Animation animation) : name(name), width(width), height(height) {
	this->animations.push_back(animation);
	animation.addScreenObject(this);
	this->setDefaultAnimation();
}
ScreenObject::ScreenObject(string name, int width, int height, vector<Animation> animations) : name(name), width(width), height(height), animations(animations) {
	for(auto animation: animations)
		animation.addScreenObject(this);
	this->setDefaultAnimation();
}
ScreenObject::ScreenObject(string name, int width, int height, vector<vector<string>> paths) : name(name), width(width), height(height) {
	for(auto path: paths)
		this->animations.push_back(Animation("", path, this));
	this->setDefaultAnimation();
}

void ScreenObject::setDefaultAnimation(){
	this->activeAnimation = &(this->animations.front());
}

Animation* ScreenObject::addAnimation() {
	this->animations.push_back(Animation("", this));
}
Animation* ScreenObject::addAnimation(Animation animation) {
	this->animations.push_back(animation);
	animation.addScreenObject(this);
}
Animation* ScreenObject::addAnimation(string path) {
	this->animations.push_back(Animation("", path, this));
}
Animation* ScreenObject::addAnimation(vector<string> paths) {
	this->animations.push_back(Animation("", paths, this));
}
void ScreenObject::addAnimations(vector<Animation> animations) {
	for(auto animation: animations) {
		animation.addScreenObject(this);
		this->animations.push_back(animation);
	}
}
void ScreenObject::addAnimations(vector<vector<string>> paths) {
	for(auto animationPaths: paths)
		this->animations.push_back(Animation("", animationPaths, this));
}

void ScreenObject::setName(string name) {
	this->name = name;
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
Animation* ScreenObject::getActiveAnimation(){
	return this->activeAnimation;
}
