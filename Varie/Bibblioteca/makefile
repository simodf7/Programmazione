CC=g++
CFLAGS=-std=c++11
DEPS=  Library.h Borrow.h Book.h Date\Date.h
OBJ = driver.o Library.o Borrow.o Book.o Date\Date.o

%.o:%.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)