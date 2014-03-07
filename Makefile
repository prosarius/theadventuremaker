ARGS= -std=c++0x

all: Screen.o main.o
	g++ Screen.o main.o -o main ${ARGS}

main.o: main.cpp
	g++ -c main.cpp ${ARGS}

Screen.o: Screen.cpp
	g++ -c Screen.cpp ${ARGS}

clean:
	rm -rf *.o main
