CC = g++
DEPS = Biscotto.h Eba.h
CFLAGS = -std=c++11
OBJ =  main.o Eba.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)