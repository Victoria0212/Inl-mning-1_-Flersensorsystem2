#include "sensor.h"
#include <cstdlib>

//
Sensor::Sensor(std::string inputUnit,
    std::string inputName,
    double inputMin,
    double inputMax)
{
    unit = inputUnit;
    name = inputName;
    minValue = inputMin;
    maxValue = inputMax;
}

double Sensor::read() {
    //Detta ger oss ett någorlunda random värde inom vårt intervall
    int range = maxValue - minValue + 1;
    int num = std::rand() % range + minValue;
    return num;
}

