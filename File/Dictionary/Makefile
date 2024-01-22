CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Dict.h Word.h
OBJS = main.o Dict.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< ${CFLAGS}

main: $(OBJS)
	$(CC) -o $@ $^ ${CFLAGS}

