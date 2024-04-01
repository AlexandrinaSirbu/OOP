#include "Seat.h"
Seat::Seat()
{
	printf("Seat"); printf("\n");
	name = new char[strlen("Seat" + 1)];
	memcpy(name, "Seat", strlen("Seat") + 1);
	FCons = 100;
	FCapacity = 10000;
	ASpeed_Sunny = 100;
	ASpeed_Snow = 70;
	ASpeed_Rain = 200;
	this->set_ASpeed();
	this->set_result(0);
}

Seat::~Seat()
{
	printf("Am apelat destructorul pentru Seat\n");
	FCons = 0;
	FCapacity = 0;
	ASpeed_Sunny = 0;
	ASpeed_Snow = 0;
	ASpeed_Rain = 0;
	this->set_ASpeed();
	this->set_result(0);
}
char* Seat::getname()
{
	return this->name;
}
void Seat::printdata()
{
	printf("Am apelat functia printdata \n");
}
void Seat::set_ASpeed()
{
	this->ASpeed = (this->ASpeed_Rain + this->ASpeed_Snow + this->ASpeed_Sunny) / 3;
}
int Seat::get_FCapacity()
{
	return this->FCapacity;
}
int Seat::get_FCons()
{
	return this->FCons;
}
int Seat::get_ASpeed()
{
	return this->ASpeed;
}
int Seat::get_ASpeed_Rain()
{
	return this->ASpeed_Rain;
}
int Seat::get_ASpeed_Sunny()
{
	return this->ASpeed_Sunny;
}
int Seat::get_ASpeed_Snow()
{
	return this->ASpeed_Snow;
}
int Seat::get_result()
{
	return this->result;
}
void Seat::set_result(int n)
{
	this->result = n;
}