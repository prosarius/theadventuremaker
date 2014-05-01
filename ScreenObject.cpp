/* 
 * File:   screenObject.cpp
 * Author: morion
 * 
 * Created on 28. März 2014, 20:13
 */

#include "ScreenObject.h"

ScreenObject::ScreenObject() {
}

ScreenObject::ScreenObject(const ScreenObject& orig){
}

ScreenObject::~ScreenObject() {
}
void ScreenObject::addAnimation(Animation animation){
	this->animations.push_back(animation);
}
