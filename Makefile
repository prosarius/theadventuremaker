TARGET =main
SOURCES =Animation.cc Character.cc Graphics.cc Point.cc Screen.cc ScreenItem.cc ScreenObject.cc Edge.cc Graph.cc main.cc
OBJECTS =$(SOURCES:.cc=.o)
DEPS =$(SOURCES:.cc=.d)
CFLAGS =-Wall -Wextra -Werror -Wmissing-declarations -O3 -std=c++11
LDFLAGS=-lSDL2 -lSDL2_image
LDFLAGS_MAC=-I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_image

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(LDFLAGS) -o $@ $^

%.o: cc/%.cc Makefile
	g++ -MMD -c $(CFLAGS) -o $@ $<

.PHONY : clean
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)




