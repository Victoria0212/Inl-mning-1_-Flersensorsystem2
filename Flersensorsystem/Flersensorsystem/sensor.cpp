#include "sensor.h"
#include <cstdlib>
#include "measurement.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "storage.h"

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
    storage = MeasurementStorage();
}

double Sensor::read() {
    //Detta ger oss ett någorlunda random värde inom vårt intervall
    int range = maxValue - minValue + 1;
    int num = std::rand() % range + minValue;
    
    //Skapa ett measurement och ge dess attribut värden
    struct Measurement m1;

    m1.name = name;
    m1.unit = unit;
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
    storage.addMeasurement(m1);

    return num;
}

