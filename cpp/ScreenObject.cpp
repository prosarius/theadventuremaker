#include "../h/ScreenObject.h"

ScreenObject::ScreenObject() {
}

ScreenObject::ScreenObject(const ScreenObject& orig){
}

ScreenObject::~ScreenObject() {
}
void ScreenObject::addAnimation(Animation animation){
	this->animations.push_back(animation);
}
