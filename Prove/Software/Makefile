CC = g++
DEPS = Task.h Date.h Programmer.h Project.h
CFLAGS = -std=c++11
OBJ =  main.o Project.o Date.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
