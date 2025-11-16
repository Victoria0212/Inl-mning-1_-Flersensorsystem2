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
   // Skapa två olika sensorer. En temp och en luftfuktighet.
	//Sensor temperature("C", "tempSensor", 10, 35);
	//Sensor humidity("%", "humiditySensor", 0, 80);

	std::vector<std::unique_ptr<Sensor>> sensors; 
	
	sensors.push_back(std::make_unique<TemperatureSensor>("tempSensor", 0, 100));
	sensors.push_back(std::make_unique<HumiditySensor>("humiditySensor", 0, 80));
	sensors.push_back(std::make_unique<PressureSensor>("pressureSensor", 0, 100));


	bool runMenu = true;
	int choice;

	//Skapa meny
	while (runMenu)
	{
        std::cout << "1) Läs in nya mätvärden\n";
	    std::cout << "2) Visa statistik per sensor\n";
		std::cout << "3) Visa alla mätvärden\n";
		std::cout << "4) Spara alla mätvärden till CSV-fil\n";
		std::cout << "5) Läs in mätvärden från CSV-fil\n";
		std::cout << "6) Avsluta\n";
		std::cin >> choice;

		//Hantera fel inmatning
		if (std::cin.fail()) {
			std::cout << "Ogiltigt val. Försök igen!\n";
			std::cin.clear();                                // Återställ felflaggor
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Rensa bufferten
			continue;
		}
		if (choice < 1 || choice > 6) {
			std::cout << "Felaktigt val. Välj mellan 1-6\n";
			continue;
		}

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

			//std::cout << "Temperature:" << std::endl;
			//temperature.storage.printStatistics();
			//std::cout << "Humidity:" << std::endl;
			//humidity.storage.printStatistics();
			break;
		case 3:
			for (auto& s : sensors) {
				s->printAll();
			}
			break;
		case 4:
			//temperature.storage.saveAllToFile("temperature");
			//humidity.storage.saveAllToFile("humidity");
			break;
		case 5:
			//temperature.storage.readFromFile("temperature");
			//humidity.storage.readFromFile("humidity");
			break;
		case 6:
			runMenu = false;
			break;
		}
	}
}