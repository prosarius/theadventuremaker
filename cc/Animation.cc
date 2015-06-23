#include "../h/Animation.h"

using namespace std;
/* constructors */
Animation::Animation(const string &name, const string &image, const int &speed, ScreenObject* screenObject)
	: name(name), length(1), speed(speed), running(false), activeImage(0) {
	this->images.push_back(image);
	this->addScreenObject(screenObject);
}
Animation::Animation(const string &name, const vector<string> &images, const int &speed, ScreenObject* screenObject)
	: name(name), speed(speed), running(false), activeImage(0), images(images) {
	this->length = images.size();
	this->addScreenObject(screenObject);
}

/* setters */
void Animation::addScreenObject(ScreenObject* object) {
	this->screenObjects.push_back(object);
}

void Animation::addImage(const string &image) {
	this->images.push_back(image);
	this->length++;
}
void Animation::addImages(const vector<string> &images) {
	for(auto texturePath: images)
		addImage(texturePath);
}
void Animation::setSpeed(const int &speed) {
	this->speed = speed;
}

/* getters */
int Animation::getLength() const {
	return this->length;
}
vector<ScreenObject*> Animation::getScreenObjects() const {
	return this->screenObjects;
}
string Animation::getActiveImage() const {
	return this->images.at(floor(activeImage / this->speed));
}
int Animation::getSpeed() const {
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
