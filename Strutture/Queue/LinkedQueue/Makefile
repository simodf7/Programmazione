CC = g++
CFLAGS = -std=c++11
DEPS = LQueue.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)