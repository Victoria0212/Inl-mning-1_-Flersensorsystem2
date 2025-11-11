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
}

void MeasurementStorage::printAll() {
	for (auto m : measurements) {
		std::cout << "Name: " << m.name << std::endl
			<< "Enhet: " << m.unit << std::endl
			<< "Värde: " << m.value << std::endl
			<< "Tidsstämpel: " << m.timeStamp << std::endl;
	}
}
void MeasurementStorage::printStatistics() {
	std::cout << "Medelvärde: " << std::setprecision(2) << averageValue << std::endl;
	std::cout << "Maxvärde: " << maxValue << std::endl;
	std::cout << "Minvärde: " << minValue << std::endl;
	std::cout << "Antal mätvärden: " << numberOfMeasurement << std::endl;
	std::cout << "Standardavvikelse: " << std::setprecision(2) << standardDeviation << std::endl;
}

void MeasurementStorage::saveAllToFile(std::string filename) {
	std::ofstream file(filename + ".csv");

	// Läs in inmatning
	for (auto m : measurements) {

		// Skriv in datan till filen
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