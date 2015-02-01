#include "../h/Animation.h"

using namespace std;
Animation::Animation(ScreenObject* screenObject) : name(name), length(0), speed(60), running(false) {
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, ScreenObject* screenObject) : name(name), length(0), speed(60), running(false), activeImage(0) {
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, string image, ScreenObject* screenObject) : name(name), length(1), speed(60), running(false), activeImage(0) {
	this->images.push_back(image);
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, vector<string> images, ScreenObject* screenObject) : name(name), speed(60), running(false), activeImage(0), images(images) {
	this->length = images.size();
	this->addScreenObject(screenObject);
}

void Animation::addScreenObject(ScreenObject* object) {
	this->screenObjects.push_back(object);
}

void Animation::addImage(string image) {
	this->images.push_back(image);
	this->length++;
}
void Animation::tick() {
	if(!this->running) return;
	this->activeImage++;
	this->activeImage %= this->images.size() * this->speed;
}
/*void Animation::removeImage(string image) {
	this->images.remove(image);
	//image->removeAnimation(this);
	this->length--;
}
*/
void Animation::addImages(vector<string> images) {
	for(auto path: images)
		addImage(path);
}
int Animation::getLength() {
	return this->length;
}
vector<ScreenObject*> Animation::getScreenObjects() {
	return this->screenObjects;
}
string Animation::getActiveImage() {
	return this->images.at(floor(activeImage / this->speed));
}
void Animation::startRunning() {
	this->running = true;
}
void Animation::stopRunning() {
	this->running = false;
	this->activeImage = 0;
}
