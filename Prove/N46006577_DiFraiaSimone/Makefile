CC = g++
DEPS = Persona.h Comunita.h
CFLAGS = -std=c++11
OBJ =  main.o Persona.o Comunita.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
