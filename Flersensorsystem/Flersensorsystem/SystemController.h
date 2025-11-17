#pragma once
#include <string>
#include <vector>
#include <memory>
#include "sensor.h"


struct Threshold { //Inställning för när en sensor ska larma
	std::string sensorName;
	double limit; //// limit = gränsvärdet (tröskel)
	bool over;  // säger om vi ska larma på ÖVER eller UNDER gränsen
                // over == true  → larma när värdet är STÖRRE än limit  (value > limit)
                // over == false → larma när värdet är MINDRE än limit (value < limit)
};

struct Alarm { // när ett larm faktiskt hänt, när den bröt mot treshold
	std::string sensorName;
		double value; //det uppmätta värdet som gjorde att larmet gick
		Threshold threshold; //over = samma idé som i Threshold. Larmet gällde värdet < >...
		std::string timeStamp;
};

class Systemcontroller {
private:
	//Gör en lista med larm
	std::vector<std::unique_ptr<Alarm>> alarms;

	//
};


//Lägg till en Treshold variabel på alla sensorer.
//Skapa en addThreshold funktion på sensor som sätter sensorns treshold värde till den inskickade parameterns värde