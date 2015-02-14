SOURCES = Animation.cpp Character.cpp Graphics.cpp Position.cpp Screen.cpp ScreenItem.cpp ScreenObject.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
all : $(OBJECTS)
	g++ $(OBJECTS) -Wall -o2 -o main -lSDL2 -lSDL2_image
main.o: cpp/main.cpp
	g++ -c cpp/main.cpp -std=c++11
%.o : cpp/%.cpp h/%.h
	g++ -c $< -std=c++11

.PHONY : clean
clean :
	rm -rf main *.o
