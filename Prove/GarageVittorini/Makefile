CC = g++
DEPS = Motore.h Garage.h Automobile.h Motocicletta.h
CFLAGS = -std=c++11
OBJ =  main.o Garage.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
