CC = g++
DEPS = Rilevamento.h Date.h VettoreRilev.h
CFLAGS = -std=c++11
OBJ =  main.o Date.o VettoreRilev.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
