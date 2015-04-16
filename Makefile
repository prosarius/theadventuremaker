SOURCES = Animation.cpp Character.cpp Graphics.cpp Position.cpp Screen.cpp ScreenItem.cpp ScreenObject.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
mac : $(OBJECTS)
	g++ $(OBJECTS) -Wall -g -o2 -o main -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_image
all : $(OBJECTS)
	g++ $(OBJECTS) -Wall -g -o2 -o main -lSDL2 -lSDL2_image
main.o: cpp/main.cpp
	g++ -c cpp/main.cpp -std=c++11
%.o : cpp/%.cpp h/%.h
	g++ -c $< -std=c++11

.PHONY : clean
clean :
	rm -rf main *.o
