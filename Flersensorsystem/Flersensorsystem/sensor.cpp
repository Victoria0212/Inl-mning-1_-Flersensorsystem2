#include "sensor.h"
#include <cstdlib>
#include "measurement.h"
#include <ctime>
#include <iostream>
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
    
    //Skapa ett measurement
    struct Measurement m1;

    // Lägg till ett värde i 
    m1.name = name;
    m1.unit = unit;
    m1.value = num;

    time_t ts = time(0);
    struct tm datetime;
    localtime_s(&datetime, &ts);
    std::string time = std::to_string(datetime.tm_hour) + std::to_string(datetime.tm_min) + std::to_string(datetime.tm_sec);
    
    m1.timeStamp = time;

    //anrop till funktionen
    storage.addMeasurement(m1);

    return num;
}

