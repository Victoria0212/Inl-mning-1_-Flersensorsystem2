#pragma once
#include <string>

//Skapa en measurement struct 
struct Measurement {
	std::string name; //som tempSensor
	std::string unit; //som C, %
	double value; //uppmätt värde 
	std::string timeStamp; 
};