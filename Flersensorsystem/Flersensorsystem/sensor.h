#pragma once
#include <string>
#include "storage.h"
// Deklarera abstrakta klassen sensor
class Sensor {
public:
	virtual double read() = 0; // virtuell funktion
	virtual void printStatistics() = 0;
	virtual void printAll() = 0;
	virtual std::string unit() const = 0;
	virtual std::string name() const = 0;

	Sensor() {}
	virtual ~Sensor() { }// virtuell destruktor	
};
// Lägg dessa i egen fil sedan

//class HumiditySensor : public Sensor {};

//class PressureSensor : public Sensor {};


//class Sensor { // klassen
//public:
//	std::string unit; //attribut (enhet som Celcius)
//	std::string name; //attribut (namn som TempSensor)
//	double minValue; //attribut (min-värde för simulering)
//	double maxValue; //attribut (max-värde för simluering)
//	MeasurementStorage storage; //attribut (storage objekt för sparning av mätvärden)
//
//	double read(); // read() ska returnera ett slumpmässigt flyttal inom minValue, maxValue
//
//	//deklarera konstruktor. Den sätter alla fält
//	Sensor(std::string unit,
//		   std::string name,
//		   double minValue,
//		   double maxValue);
//
//
//};