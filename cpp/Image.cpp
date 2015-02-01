#include "../h/Image.h"

Image::Image(std::string path): path(path) {
}

void Image::addAnimation(Animation* animation){
	this->animations.push_back(animation);
}
