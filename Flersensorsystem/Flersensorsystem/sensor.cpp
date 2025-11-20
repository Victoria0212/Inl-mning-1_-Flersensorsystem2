#include "sensor.h"
#include "SystemController.h"
#include <iostream>

void Sensor::printStatistics() {
	std::cout << "Sensor: " << name() << std::endl;
	_storage.printStatistics();
}
void Sensor::printAll() {
	_storage.printAll();
}

void Sensor::addThreshold(double limit, bool over) {
	Threshold t;
	t.limit = limit;
	t.over = over;
	t.sensorName = name();

	_threshold = t;
}


void Sensor::makeAlarm(Threshold t, std::string name, std::string timestamp, double value) {
	struct Alarm alarm;
	alarm.sensorName = name;
	alarm.threshold = t;
	alarm.timeStamp = timestamp;
	alarm.value = value;

	_alarms.push_back(alarm);
}

void Sensor::printAlarms() {
	for (auto a : _alarms) {
		std::cout << a.sensorName << " Uppmättvärde: " << a.value << "; Gränsvärde: " << a.threshold.limit << "; " << a.timeStamp << std::endl;
	}
}
void Sensor::saveAllToFile()
{
	_storage.saveAllToFile(name());
}
void Sensor::readFromFile()
{
	_storage.readFromFile(name());
}
void Sensor::printExceedingMeasurements() {
	_storage.printExceedingMeasurements();
}
