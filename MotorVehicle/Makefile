MotorVehicle: MotorVehicle.o Vehicle.o
	g++ -o MotorVehicle MotorVehicle.o Vehicle.o
Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -std=c++11 -c Vehicle.cpp
MotorVehicle.o: MotorVehicle.cpp Vehicle.h
	g++ -std=c++11 -c MotorVehicle.cpp