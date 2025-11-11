#include <iostream>
#include "sensor.h"
#include "storage.h"
#include "measurement.h"
#include <limits>

int main()
{
   // Skapa två olika sensorer. En temp och en luftfuktighet.
	Sensor temperature("C", "tempSensor", 10, 35);
	Sensor humidity("%", "humiditySensor", 0, 80);

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
			temperature.read();
			humidity.read();
			std::cout << "Nya mätvärden inlästa\n";
			break;
		case 2:
			std::cout << "Temperature:" << std::endl;
			temperature.storage.printStatistics();
			std::cout << "Humidity:" << std::endl;
			humidity.storage.printStatistics();
			break;
		case 3:
			std::cout << "Temperature:" << std::endl;
			temperature.storage.printAll();
			std::cout << "Humidity:" << std::endl;
			humidity.storage.printAll();
			break;
		case 4:
			temperature.storage.saveAllToFile("temperature");
			humidity.storage.saveAllToFile("humidity");
			break;
		case 5:
			temperature.storage.readFromFile("temperature");
			humidity.storage.readFromFile("humidity");
			break;
		case 6:
			runMenu = false;
			break;
		}
	}
}