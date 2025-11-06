#include <iostream>
#include "sensor.h"

int main()
{
   // Skapa två olika sensorer. En temp och en luftfuktighet.
	Sensor temperature("C", "tempSensor", 10, 35);
	Sensor humidity("%", "humiditySensor", 0, 80);

	// Kalla på read()
	std::cout << temperature.read();
	std::cout << "\n";
	std::cout << temperature.read();
	std::cout << "\n";
	std::cout << temperature.read();
	std::cout << "\n";
	std::cout << humidity.read();
} 