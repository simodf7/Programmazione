CC=g++
CFLAGS=-std=c++11
DEPS= Warehouse.h 
OBJ = Warehouse.o  main.o

%.o:%.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)