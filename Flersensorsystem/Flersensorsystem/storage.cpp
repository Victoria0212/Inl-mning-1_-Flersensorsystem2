#include "storage.h"
#include <iostream>
#include <iomanip>

void MeasurementStorage::addMeasurement(const Measurement& measurement) {
	measurements.push_back(measurement);
	numberOfMeasurement++; //ökar antal mätvärden räknare (++)
	double sum = 0;
	double min = measurement.value;
	double max = measurement.value;

	for (auto m : measurements){ //loopar över våra mätvärden
		//Summera värdern
		sum += m.value;
		//Hitta min värdet
		if (m.value < min) {
			min = m.value;
		}
		//Hitta max värdet
		if (m.value > max) {
			max = m.value;
		}
	}
	//Räkna ut medelvärde
	averageValue = sum / numberOfMeasurement;

	minValue = min;
	maxValue = max;

	//Räkna ut standardavvikelsen
	double var = 0;
	for (auto m : measurements) {
		var += (m.value - averageValue) * (m.value - averageValue);
	}
	var /= numberOfMeasurement;
	standardDeviation = sqrt(var);

	//std::cout 
	//	<< std::setprecision(4)
	//	<< "\n Mätvärde: " << measurement.value
	//	<< "\n Antal mätvärden: " << numberOfMeasurement
	//	<< "\n Medelvärde: " << averageValue;
}

