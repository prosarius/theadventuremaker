all:
	g++ -o main Animation.cpp Character.cpp Image.cpp Position.cpp Screen.cpp ScreenItem.cpp ScreenLayer.cpp ScreenObject.cpp main.cpp -O2 -std=c++11