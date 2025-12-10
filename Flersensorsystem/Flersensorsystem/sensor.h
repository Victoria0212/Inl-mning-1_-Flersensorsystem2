#pragma once
#include <string>
#include "storage.h"
#include "SystemController.h"
#include <vector>
// Deklarera abstrakta klassen sensor
class Sensor {
public:
	virtual double read() = 0; // virtuell funktion.
	virtual std::string unit() const = 0;
	virtual std::string name() const = 0;

	//Vi gör inte dessa funktioner virtuella för att dess funktion är oberoende vilket subklass det är. Utförandet i funktionen kommer vara samma.
	void addThreshold(double limit, bool over);
	void printStatistics();
	void printAll();
	void printAlarms();
	void saveAllToFile();
	void readFromFile();
	void printExceedingMeasurements();
	Sensor() {}
	virtual ~Sensor() { }// virtuell destruktor	

protected:
	void makeAlarm(Threshold t, std::string name, std::string timestamp, double value);
	Threshold _threshold;
	MeasurementStorage _storage;

private:
	std::vector<Alarm> _alarms;
};