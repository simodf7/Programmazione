testTime: testTime.o time.o
	g++ -o testTime testTime.o time.o
testTime.o: testTime.cpp time.h 
	g++ -std=c++11 -c testTime.cpp
time.o: time.cpp time.h
	g++ -std=c++11 -c time.cpp