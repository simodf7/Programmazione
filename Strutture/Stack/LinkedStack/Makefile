CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Node.h LinkedList.h LinkedList.cpp LStack.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)