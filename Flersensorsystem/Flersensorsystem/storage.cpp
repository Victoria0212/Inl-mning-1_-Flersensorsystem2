#include "storage.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

void MeasurementStorage::printAll() {
	for (auto m : measurements) {
		std::cout << m.name << std::endl << m.unit << std::endl << m.value << std::endl << m.timeStamp << std::endl;
	}
}
void MeasurementStorage::saveAllToFile(std::string filename) {
	std::ofstream file(filename + ".csv");

	// Read the input
	for (auto m : measurements) {

		// Insert the data to file
		file << m.name << ","
			<< m.unit << ","
			<< m.value << ","
			<< m.timeStamp
			<< "\n";
	}

	file.close();
}
void MeasurementStorage::readFromFile(std::string filename) {
	std::string text;

	std::ifstream file(filename + ".csv");
	//Läs filen och skapa en measurement per rad
	while (getline(file, text)) {
		std::vector<std::string> values;
		std::stringstream line(text);
		std::string value;

		while (getline(line, value, ',')) {
			values.push_back(value);
		}

		Measurement m;
		m.name = values[0];
		m.unit = values[1];
		m.value = std::stod(values[2]);
		m.timeStamp = values[3];

		addMeasurement(m);
	}

	file.close();
}