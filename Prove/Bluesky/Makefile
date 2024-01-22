CC = g++
DEPS = City.h Date.h Rilevamento.h Rilevatore.h
CFLAGS = -std=c++11
OBJ =  main.o Date.o City.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
