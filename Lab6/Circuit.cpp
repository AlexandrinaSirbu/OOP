#include "Circuit.h"
#include <iostream>
using namespace std;
Circuit::Circuit()
{
	int max_cars = 5;
	this->vectordate = (Car**)(malloc(max_cars * sizeof(Car*)));
	this->nrCars = 0;
	this->Length = 100;
}

void Circuit::SetLength(int Length)
{
	this->Length = Length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

bool Circuit::AddCar(Car* pointerCar)
{
	this->vectordate[this->nrCars] = pointerCar;
	++nrCars;
	return true;
}

void Circuit::Race()
{
	for (int i = 0; i < this->nrCars; i++)
		if ((this->vectordate[i])->get_FCapacity() < ((this->vectordate[i])->get_FCons() * this->Length))
			(this->vectordate[i])->set_result(0);
		else
			(this->vectordate[i])->set_result(1);
}

Weather Circuit::get_Weather()
{
	return this->weather;
}

void Circuit::ShowFinalRanks()
{
	int i, j;
	Car* aux;
	for (i = 0; i < nrCars - 1; i++)
		for (j = 0; j < nrCars - i - 1; j++)
			if ((this->vectordate[i])->get_FCapacity() > ((this->vectordate[i])->get_FCons() / this->Length))
				switch (this->get_Weather())
				{
				case Rain:
					if ((this->vectordate[i])->get_ASpeed_Rain() > (this->vectordate[i + 1])->get_ASpeed_Rain())
					{
						aux = this->vectordate[i];
						this->vectordate[i] = this->vectordate[i + 1];
						this->vectordate[i + 1] = aux;
					}
				case Snow:
					if ((this->vectordate[i])->get_ASpeed_Snow() > (this->vectordate[i + 1])->get_ASpeed_Snow())
					{
						aux = this->vectordate[i];
						this->vectordate[i] = this->vectordate[i + 1];
						this->vectordate[i + 1] = aux;
					}
				case Sunny:
					if ((this->vectordate[i])->get_ASpeed_Sunny() > (this->vectordate[i + 1])->get_ASpeed_Sunny())
					{
						aux = this->vectordate[i];
						this->vectordate[i] = this->vectordate[i + 1];
						this->vectordate[i + 1] = aux;
					}
				}
	for (i = 0; i < nrCars; i++)
	{
		printf("masina "); cout << (this->vectordate[i])->getname(); printf(" a ajuns a-"); cout << nrCars - i; printf("\n");
	}
	printf("\n");
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < nrCars; i++)
	{
		if ((this->vectordate[i])->get_result() != 1)
		{
			cout << "masina ";  cout << (this->vectordate[i])->getname(); printf(" nu finiseaza!!!\n");
		}
	}
}