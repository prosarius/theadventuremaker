#include "../h/Screen.h"

Screen::Screen() {
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
}

int Screen::getSizeX(){
    return this->sizeX;
}
int Screen::getSizeY(){
    return this->sizeY;
}
void Screen::setSizeX(int x){
    this->sizeX = x;
}
void Screen::setSizeY(int y){
    this->sizeY = y;
}
void Screen::addLayer(string name = NULL){
	this->layers.push_back(ScreenLayer(name));
}
vector<ScreenLayer*> Screen::getAllLayers(){
	vector<ScreenLayer*> layers;
	for(int i = 0; i < this->layers.size(); i++){
		layers.push_back(&this->layers.at(i));
	}
	return layers;
}
vector<Character*> Screen::getAllCharacters(){
	vector<ScreenLayer*> layers = this->getAllLayers();
	vector<Character*> chars;
	for(int i = 0; i < layers.size(); i++){
		vector<Character*> layerChars = layers.at(i)->getAllCharacters();
		for(int j = 0; j < layerChars.size(); j++){
			chars.push_back(layerChars.at(j));
		}
	}
	return chars;
}
vector<string> Screen::getAllCharacterNames(){
	vector<ScreenLayer*> layers = this->getAllLayers();
	vector<string> names;
	for(int i = 0; i < layers.size(); i++){
		vector<string> layerNames = layers.at(i)->getAllCharacterNames();
		for(int j = 0; j < layerNames.size(); j++){
			names.push_back(layerNames.at(j));
		}
	}
	return names;
}
vector<string> Screen::getAllLayerNames(){
	vector<string> names;
	for(int i = 0; i < this->layers.size(); i++){
		names.push_back(this->layers.at(i).getName());
	}
	return names;
}
ScreenLayer* Screen::getLayer(int index){
	return &this->layers[index];
}
ScreenLayer* Screen::getLastLayer(){
	return &this->layers.back();
}
