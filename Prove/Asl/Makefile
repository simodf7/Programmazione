CC = g++
DEPS = Asl.h Doctor.h Patient.h
CFLAGS = -std=c++11
OBJ =  main.o Asl.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
