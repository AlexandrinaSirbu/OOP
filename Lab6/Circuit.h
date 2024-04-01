#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
	Car** vectordate;
	Weather weather;
	int nrCars;
	int Length;
public:
	Circuit();
	Weather get_Weather();
	void SetLength(int Length);
	void SetWeather(Weather weather);
	bool AddCar(Car* pointerCar);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};