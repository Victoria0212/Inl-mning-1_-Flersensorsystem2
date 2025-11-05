#pragma once
#include <string>

//steg 1: Deklarera klassen sensor

class Sensor { // klassen
public:
	std::string unit; //attribut (enhet som Celcius)
	std::string name; //attribut (namn som TempSensor)
	double minValue; //attribut (min-värde för simulering)
	double maxValue; //attribut (max-värde för simluering)
	double read(); // // read() ska returnera ett slumpmässigt flyttal inom minValue, maxValue

	//deklarera konstruktor. Den sätter alla fält
	Sensor(std::string unit,
		   std::string name,
		   double minValue,
		   double maxValue);
};