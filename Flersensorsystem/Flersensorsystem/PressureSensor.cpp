#include "PressureSensor.h"
#include <cstdlib>
#include "measurement.h"
#include <iostream>
#include "storage.h"
#include "utils.h"

PressureSensor::PressureSensor(std::string inputName,
    double inputMin,
    double inputMax)
{
    _unit = "hPa";
    _name = inputName;
    _minValue = inputMin;
    _maxValue = inputMax;
    _storage = MeasurementStorage();
}

std::string PressureSensor::name() const {
    return _name;
}
std::string PressureSensor::unit() const {
    return _unit;
}

double PressureSensor::read() {
    //Detta ger oss ett någorlunda random värde inom vårt intervall
    int range = _maxValue - _minValue + 1;
    int num = std::rand() % range + _minValue;

    //Skapa ett measurement och ge dess attribut värden
    struct Measurement m1;

    m1.name = _name;
    m1.unit = _unit;
    m1.value = num;
    m1.threshold = "Nej";

    //Skapar ett timestamp
    std::string ts = getTimestamp();
    m1.timeStamp = ts;
    //anrop till funktionen
    _storage.addMeasurement(m1);

    //Check threshold
    if (_threshold.over == true && num > _threshold.limit) {
        makeAlarm(_threshold, _name, ts, num);
        m1.threshold = "Ja";
    }
    if (_threshold.over == false && num < _threshold.limit) {
        makeAlarm(_threshold, _name, ts, num);
        m1.threshold = "Ja";
    }

    return num;
}
