CC = g++
CFLAGS = -std=c++11
DEPS = Conto.h Date.h
OBJS = main.o Conto.o Date.o


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)