CC = g++
DEPS = Posto.h Teatro.h
CFLAGS = -std=c++11
OBJ =  main.o Teatro.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
