CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Complex.h
OBJS = Complex.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)