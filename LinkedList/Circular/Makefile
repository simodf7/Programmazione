CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Node.h CLinkedList.h CLinkedList.cpp
OBJ = main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ ${CFLAGS}