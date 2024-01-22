CC = g++
DEPS = Date.h Ups.h ForeignPackage.h Package.h
CFLAGS = -std=c++11
OBJ =  main.o Ups.o Date.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
