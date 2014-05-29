#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Screen.h"
using namespace std;

int main(int argc, char** argv) {
	Screen firstScreen = Screen();
	Character Maya("Maya Tänzi");
	Character Steve("Steven Kovenzi");
	Character buergfrau("des Bürgermeisters Frau");
	firstScreen.addLayer("layer1");
	firstScreen.addLayer("l2312312");
	firstScreen.addLayer("layer3");
	firstScreen.addLayer("best!");
	firstScreen.getLayer(2)->addCharacter(&Maya);
	firstScreen.getLayer(2)->addCharacter(&Steve);
	firstScreen.getLayer(0)->addCharacter(&buergfrau);
	
	cout << "Layer names" << endl;
	vector<string> screenNames = firstScreen.getAllLayerNames();
	for(int i = 0; i < screenNames.size(); i++){
		cout << screenNames.at(i) << "\t";
	}
	cout << endl;
	
	cout << "character names" << endl;
	vector<string> characterNames = firstScreen.getAllCharacterNames();
	for(int i = 0; i < characterNames.size(); i++){
		cout << characterNames.at(i) << "\t";
	}
	cout << endl;
	return 0;
}

