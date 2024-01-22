CC = g++
DEPS = Student.h Subject.h University.h
CFLAGS = -std=c++11
OBJ =  main.o University.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
