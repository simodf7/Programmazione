CC = g++
DEPS = Book.h Borrow.h Date.h Library.h
CFLAGS = -std=c++11
OBJ =  main.o Book.o Date.o Library.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
