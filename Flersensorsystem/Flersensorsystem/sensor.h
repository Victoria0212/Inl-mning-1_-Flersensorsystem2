#pragma once
#include <string>
#include "storage.h"
#include "SystemController.h"
#include <vector>
// Deklarera abstrakta klassen sensor
class Sensor {
public:
	virtual double read() = 0; // virtuell funktion.  Varför gör vi denna virtual? Det är ingen skillnad på read implementationen??
	virtual std::string unit() const = 0;
	virtual std::string name() const = 0;

	void addThreshold(double limit, bool over);
	void printStatistics();
	void printAll();
	void printAlarms();
	void saveAllToFile();
	void readFromFile();

	Sensor() {}
	virtual ~Sensor() { }// virtuell destruktor	

protected:
	void makeAlarm(Threshold t, std::string name, std::string timestamp, double value);
	Threshold _threshold;
	MeasurementStorage _storage;

private:
	std::vector<Alarm> _alarms;
};