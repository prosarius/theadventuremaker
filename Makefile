SOURCES = Animation.cpp Character.cpp Image.cpp Position.cpp Screen.cpp ScreenItem.cpp ScreenObject.cpp Graphics.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
all : $(OBJECTS)
	g++ $(OBJECTS) -Wall -o2 -o main -lSDL2 -lSDL2_image
%.o : cpp/%.cpp
	g++ -c $< -std=c++11

.PHONY : clean
clean :
	rm -rf main *.o
