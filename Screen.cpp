/* 
 * File:   Screen.cpp
 * Author: morion
 * 
 * Created on 7. März 2014, 21:34
 */

#include "Screen.h"

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
void Screen::addLayer(){
	this->layers.push_back(ScreenLayer());
}
ScreenLayer* Screen::getLayer(int index){
	return &this->layers[index];
}