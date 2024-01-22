driver: driver.o Date.o
	g++ -o driver driver.o Date.o
driver.o: driver.cpp Date.h
	g++ -c driver.cpp -std=c++11 -pedantic -Wall
Date.o: Date.cpp Date.h
	g++ -c Date.cpp -std=c++11 -pedantic -Wall