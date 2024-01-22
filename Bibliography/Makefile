CC = g++
CFLAGS = -std=c++11
DEPS = Publication.h Book.h PaperArticle.h PaperConf.h
OBJS = Driver.o Publication.o Book.o PaperArticle.o PaperConf.o 


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Driver: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)