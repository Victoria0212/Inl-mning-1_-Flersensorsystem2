#include <iostream>
#include "sensor.h"
#include "storage.h"
#include "measurement.h"
#include <limits>
#include <vector>
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "PressureSensor.h"
#include <memory>

int main()
{
	std::vector<std::unique_ptr<Sensor>> sensors;
	//Skapa 3 sensorer och lägg till i listan
	sensors.push_back(std::make_unique<TemperatureSensor>("tempSensor", 0, 100));
	sensors.push_back(std::make_unique<HumiditySensor>("humiditySensor", 0, 80));
	sensors.push_back(std::make_unique<PressureSensor>("pressureSensor", 0, 100));

	bool runMenu = true;
	int choice;

	//Skapa meny
	while (runMenu)
	{
		std::cout << "1) Läs in nya mätvärden från alla sensorer\n";
		std::cout << "2) Visa statistik per sensor\n";
		std::cout << "3) Visa alla mätvärden\n";
		std::cout << "4) Konfigurera tröskelregler\n";
		std::cout << "5) Visa larm\n";
		std::cout << "6) Spara alla mätvärden till CSV-fil\n";
		std::cout << "7) Läs in mätvärden från CSV-fil\n";
		std::cout << "8) Avsluta\n";
		std::cin >> choice;


		//Hantera fel inmatning
		if (std::cin.fail()) {
			std::cout << "Ogiltigt val. Försök igen!\n";
			std::cin.clear();                                // Återställ felflaggor
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Rensa bufferten
			continue;
		}
		if (choice < 1 || choice > 8) {
			std::cout << "Felaktigt val. Välj mellan 1-6\n";
			continue;
		}

		double limit;
		bool over;
		std::string overStr;

		//Hantera menyval
		switch (choice) {
		case 1:
			for (auto& s : sensors) {
				s->read();
			}
			std::cout << "Nya mätvärden inlästa\n";
			break;
		case 2:
			for (auto& s : sensors) {
				s->printStatistics();
			}
			break;
		case 3:
			for (auto& s : sensors) {
				s->printAll();
			}
			break;
		case 4:
			for (auto& s : sensors) {
				std::cout << "Sensor: " << s->name() << std::endl << "Välj threshold värden." << std::endl;
				std::cout << "Sätt limit" << std::endl;

				while (true) {
					std::cin >> limit;

					//Hantera fel inmatning
					if (std::cin.fail()) {
						std::cout << "Ogiltigt värde. Försök igen!\n";
						std::cin.clear();                                // Återställ felflaggor
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Rensa bufferten
						continue;
					}
					break;
				}

				std::cout << "Ska det var 'over'? (J/N)" << std::endl;
				while (true) {

					std::cin >> overStr;

					if (!(overStr == "J" || overStr == "N")) {
						std::cout << "Ogiltigt värde. Försök igen!\n";
						std::cin.clear();                                // Återställ felflaggor
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Rensa bufferten
						continue;
					}
					break;
				}

				if (overStr == "J") {
					over = true;
				}
				else {
					over = false;
				}

				s->addThreshold(limit, over);
			}
			break;
		case 5:
			for (auto& s : sensors) {
				s->printAlarms();
			}
			break;
		case 6:
			for (auto& s : sensors) {
				s->saveAllToFile();
			}
			break;
		case 7:
			for (auto& s : sensors) {
				s->readFromFile();
			} 
			break;
		case 8:
			runMenu = false;
			break;
		}
	}
}