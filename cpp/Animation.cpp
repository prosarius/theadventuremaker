#include "../h/Animation.h"

using namespace std;
/* constructors */
Animation::Animation(string name, string image, int speed, ScreenObject* screenObject)
	: name(name), length(1), speed(speed), running(false), activeImage(0) {
	this->images.push_back(image);
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, vector<string> images, int speed, ScreenObject* screenObject)
	: name(name), speed(speed), running(false), activeImage(0), images(images) {
	this->length = images.size();
	this->addScreenObject(screenObject);
}

/* setters */
void Animation::addScreenObject(ScreenObject* object) {
	this->screenObjects.push_back(object);
}

void Animation::addImage(string image) {
	this->images.push_back(image);
	this->length++;
}
void Animation::addImages(vector<string> images) {
	for(auto texturePath: images)
		addImage(texturePath);
}
void Animation::setSpeed(int speed) {
	this->speed = speed;
}

/* getters */
int Animation::getLength() {
	return this->length;
}
vector<ScreenObject*> Animation::getScreenObjects() {
	return this->screenObjects;
}
string Animation::getActiveImage() {
	return this->images.at(floor(activeImage / this->speed));
}
int Animation::getSpeed() {
	return this->speed;
}

/* other methods */
void Animation::tick() {
	if(!this->running) return;
	this->activeImage++;
	this->activeImage %= this->images.size() * this->speed;
}
void Animation::startRunning() {
	this->running = true;
}
void Animation::stopRunning() {
	this->running = false;
	this->activeImage = 0;
}
