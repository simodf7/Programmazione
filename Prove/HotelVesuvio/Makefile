CC = g++
DEPS = Booking.h Company.h Date.h Hotel.h
CFLAGS = -std=c++11
OBJ =  main.o Company.o Date.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
