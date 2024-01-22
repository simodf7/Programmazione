CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Node.h LinkedList.h Position.h LStack.h
OBJ = main.o Maze.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)