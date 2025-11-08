#include <iostream>
#include "sensor.h"
#include "storage.h"
#include "measurement.h"

int main()
{
   // Skapa två olika sensorer. En temp och en luftfuktighet.
	Sensor temperature("C", "tempSensor", 10, 35);
	Sensor humidity("%", "humiditySensor", 0, 80);

	// Kalla på read()
	temperature.read();
	temperature.read();
	temperature.read();
	temperature.read();
	temperature.read();
	temperature.read();
	temperature.read();
	temperature.read();
	

	humidity.read();
} 