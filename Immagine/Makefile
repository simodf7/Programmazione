CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Immagine.h
OBJ = main.o Immagine.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ ${CFLAGS}