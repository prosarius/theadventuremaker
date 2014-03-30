/* 
 * File:   ScreenLayer.cpp
 * Author: morion
 * 
 * Created on 30. März 2014, 20:19
 */

#include "ScreenLayer.h"

ScreenLayer::ScreenLayer() {
}

ScreenLayer::ScreenLayer(const ScreenLayer& orig) {
}

ScreenLayer::~ScreenLayer() {
}
void ScreenLayer::addCharacter(Character* character){
	this->characters.push_back(character);
}
void ScreenLayer::addItem(ScreenItem* item){
	this->items.push_back(item);
}

