#pragma once
#include "sensor.h"

class HumiditySensor : public Sensor {
public:
	HumiditySensor(std::string name, //deklarera konstruktorn
		double minValue,
		double maxValue);

	std::string name() const override;
	std::string unit() const override;
	double read() override;

private:
	std::string _name;
	std::string _unit;
	double _minValue;
	double _maxValue;
};
