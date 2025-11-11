#pragma once
#include "measurement.h"
#include <vector>

// Gör en klass som samlar mätningar och kan skriva ut dem.
class MeasurementStorage {
public:
	//Lägger till mätning i listan
	void addMeasurement(const Measurement& measurement);
	
	int numberOfMeasurement;
	double averageValue;
	double minValue;
	double maxValue;
	double standardDeviation;

	//Skriver ut alla mätningar
    void printAll();

	void saveAllToFile(std::string filename);

	void readFromFile(std::string filename);

private:
    std::vector<Measurement> measurements; // här sparas allt

};