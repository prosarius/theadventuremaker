#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Screen.h"
#include "Character.h"

class Graphics {
	Screen* screen;
	map<string, SDL_Texture*> textures;
	SDL_Event* mainEvent;
	SDL_Window* window;
	SDL_Renderer* renderer;
    bool debug;

	SDL_Texture* getTextureFromPath(const string &texturePath);
	void draw();
	void drawScreenObject(ScreenObject* screenObject);
	void drawBackground();
	void clear();
	void present();
public:
	Graphics(Screen* screen);
	~Graphics();
	void run();
};

#endif	/* GRAPHICS_H */
