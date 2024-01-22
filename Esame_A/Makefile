CC = g++
DEPS = Citta.h Paese.h
CFLAGS = -std=c++11
OBJ =  main.o Paese.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
