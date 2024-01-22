CC = g++
DEPS = BST.h BSTNode.h
CFLAGS = -std=c++11
OBJ =  main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
