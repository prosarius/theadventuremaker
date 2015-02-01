#include "../h/Animation.h"

using namespace std;
Animation::Animation(ScreenObject* screenObject) : name(name), length(0) {
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, ScreenObject* screenObject) : name(name), length(0), activeImage(0) {
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, string image, ScreenObject* screenObject) : name(name), length(1), activeImage(0) {
	this->images.push_back(image);
	this->addScreenObject(screenObject);
}
Animation::Animation(string name, vector<string> images, ScreenObject* screenObject) : name(name), activeImage(0), images(images) {
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
	this->activeImage++;
	this->activeImage %= this->images.size();
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
	return this->images.at(activeImage);
}
