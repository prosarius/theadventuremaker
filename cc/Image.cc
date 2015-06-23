#include "../h/Image.h"

Image::Image(std::string texturePath): texturePath(texturePath) {
}

void Image::addAnimation(Animation* animation){
	this->animations.push_back(animation);
}
