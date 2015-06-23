#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../h/Screen.h"
#include "../h/Graphics.h"
#include "../h/Character.h"

int main(void) {
	Screen screen("Wald", 1280, 800, 300, 0.5, "screens/garden.png");

	Character strichmann("Strichmann", 100, 200, 100, 500, "characters/strichmann.png", 2, 0.4, 0.95);
    strichmann.setSpeed(2);
	strichmann.getActiveAnimation()->addImage("characters/strichmann1.png");
	strichmann.getActiveAnimation()->addImage("characters/strichmann2.png");

    ScreenObject tree("Tree", 300, 699, 650, 580, "sprites/tree1.png", 0.5, 0.85, 150, 30);
    ScreenObject mower("Mover", 222, 200, 450, 620, "sprites/mower.png", 0.3,0.85, 100, 50);
    ScreenObject house("House", 650, 899, 1050, 600, "sprites/house.png", 0.55, 0.75, 400, 130);

	screen.addScreenObject(&strichmann);
	screen.addPlayer(&strichmann);
    screen.addScreenObject(&tree);
    screen.addScreenObject(&mower);
    screen.addScreenObject(&house);

	Graphics graphics(&screen);
	graphics.run();
	return 0;
}

