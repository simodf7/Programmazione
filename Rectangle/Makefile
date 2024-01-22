driver: driver.o point.o rectangle.o
	g++ -o driver driver.o point.o rectangle.o
driver.o: driver.cpp rectangle.h
	g++ -std=c++11 -c driver.cpp
point.o: point.cpp point.h
	g++ -std=c++11 -c point.cpp
rectangle.o: rectangle.cpp rectangle.h point.h
	g++ -std=c++11 -c rectangle.cpp
	