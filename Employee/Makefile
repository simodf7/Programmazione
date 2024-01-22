test: test.o employee.o date.o
	g++ -o test test.o employee.o date.o
test.o: test.cpp employee.h date.h
	g++ -std=c++11 -c test.cpp
employee.o: employee.cpp date.h
	g++ -std=c++11 -c employee.cpp

	