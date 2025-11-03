#include <string>
// skapa classer för sensorerna för 2 st. En för temperatur och en för luftfuktighet.
// Om jag vill göra en till, vindhastighet.


class Sensor {
public:
	std::string enhet;
	double simuleringsintervall;
	std::string namn;
	double read();
	double minValue;
	double maxValue;
};

double Sensor::read() {

	return minValue;
}