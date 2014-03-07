/* 
 * File:   Screen.cpp
 * Author: morion
 * 
 * Created on 7. März 2014, 21:34
 */

#include "Screen.h"

#include <iostream>

Screen::Screen() {
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
}

string Screen::getImagePath(){
    return this->imagePath;
}
int Screen::getSizeX(){
    return this->sizeX;
}
int Screen::getSizeY(){
    return this->sizeY;
}
void Screen::setImagePath(string path){
    this->imagePath = path;
}
void Screen::setSizeX(int x){
    this->sizeX = x;
}
void Screen::setSizeY(int y){
    this->sizeY = y;
}