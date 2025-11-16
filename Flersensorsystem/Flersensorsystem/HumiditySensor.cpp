#include "HumiditySensor.h"
#include <cstdlib>
#include "measurement.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "storage.h"

HumiditySensor::HumiditySensor(std::string inputName,
    double inputMin,
    double inputMax)
{
    _unit = "%";
    _name = inputName;
    _minValue = inputMin;
    _maxValue = inputMax;
    _storage = MeasurementStorage();
}

std::string HumiditySensor::name() const {
    return _name;
}
std::string HumiditySensor::unit() const {
    return _unit;
}

double HumiditySensor::read() {
    //Detta ger oss ett någorlunda random värde inom vårt intervall
    int range = _maxValue - _minValue + 1;
    int num = std::rand() % range + _minValue;

    //Skapa ett measurement och ge dess attribut värden
    struct Measurement m1;

    m1.name = _name;
    m1.unit = _unit;
    m1.value = num;

    //Skapar ett timestamp
    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::string timestamp = oss.str();
    m1.timeStamp = timestamp;

    //anrop till funktionen
    _storage.addMeasurement(m1);

    return num;
}
void HumiditySensor::printStatistics() {
    std::cout << "Sensor: " << _name << std::endl;
    _storage.printStatistics();
}
void HumiditySensor::printAll() {
    _storage.printAll();

}