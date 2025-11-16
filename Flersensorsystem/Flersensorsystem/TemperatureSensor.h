#pragma once
#include "sensor.h"

class TemperatureSensor : public Sensor {
public:
	TemperatureSensor(std::string name, //deklarera konstruktorn
		double minValue,
		double maxValue);

	std::string name() const override;
	std::string unit() const override;
	double read() override;
	void printStatistics() override;
	void printAll() override;

private:
	std::string _name;
	std::string _unit;
	double _minValue;
	double _maxValue;
	MeasurementStorage _storage;
};