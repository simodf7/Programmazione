CC = g++
DEPS = Date.h Lap.h Driver.h Championship.h
CFLAGS = -std=c++11
OBJ =  main.o Championship.o Date.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)