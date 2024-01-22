CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = ClientData.h
OBJS = main.o ClientData.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< ${CFLAGS}

main: $(OBJS)
	$(CC) -o $@ $^ ${CFLAGS}



