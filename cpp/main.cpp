#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../h/Screen.h"
#include "../h/Graphics.h"
#include "../h/Character.h"

int main(int argc, char** argv) {
	Screen screen("Wald", 1600, 900, 300, "screens/garten.jpg");
	Character strichmann("Strichmann", 100, 200, 100, 500, "characters/strichmann.png", 2);
	cout << strichmann.getPosX() << endl;
	strichmann.getActiveAnimation()->addImage("characters/strichmann1.png");
	strichmann.getActiveAnimation()->addImage("characters/strichmann2.png");
	screen.addScreenObject(&strichmann);
	screen.addPlayer(&strichmann);

	Graphics graphics(&screen);
	graphics.run();
	return 0;
}

