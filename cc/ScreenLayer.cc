#include "../h/ScreenLayer.h"
#include <iostream>

ScreenLayer::ScreenLayer() {
}
string ScreenLayer::getName(){
	return this->name;
}
void ScreenLayer::setName(string name){
	this->name = name;
}
void ScreenLayer::setScreen(Screen* screen){
	this->screen = screen;
}
Screen* ScreenLayer::getScreen(){
	return this->screen;
}
vector<Character*> ScreenLayer::getAllCharacters(){
	vector<Character*> chars;
	for(int i = 0; i < this->characters.size(); i++){
		chars.push_back(this->characters.at(i));
	}
	return chars;
}
vector<string> ScreenLayer::getAllCharacterNames(){
	vector<string> names;
	for(int i = 0; i < this->characters.size(); i++){
		names.push_back(this->characters.at(i)->getName());
	}
	return names;
}
void ScreenLayer::addCharacter(Character* character){
	this->characters.push_back(character);
}
void ScreenLayer::addItem(ScreenItem* item){
	this->items.push_back(item);
}

