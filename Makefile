all:
	g++ -o main cpp/Animation.cpp cpp/Character.cpp cpp/Image.cpp cpp/Position.cpp cpp/Screen.cpp cpp/ScreenItem.cpp cpp/ScreenLayer.cpp cpp/ScreenObject.cpp cpp/main.cpp -O2 -std=c++11
