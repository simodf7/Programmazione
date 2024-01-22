CC = g++
DEPS = Fabric.h RettTable.h RTable.h TTable.h Table.h
CFLAGS = -std=c++11
OBJ =  main.o Fabric.o Table.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

