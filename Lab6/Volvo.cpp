#include "Volvo.h"
Volvo::Volvo()
{
	printf("Volvo"); printf("\n");
	name = new char[strlen("Volvo" + 1)];
	memcpy(name, "Volvo", strlen("Volvo") + 1);
	FCons = 20;
	FCapacity = 200;
	ASpeed_Sunny = 100;
	ASpeed_Snow = 105;
	ASpeed_Rain = 150;
	this->set_ASpeed();
	this->set_result(0);
}

Volvo::~Volvo()
{
	printf("Am apelat destructorul pentru Volvo\n");
	FCons = 0;
	FCapacity = 0;
	ASpeed_Sunny = 0;
	ASpeed_Snow = 0;
	ASpeed_Rain = 0;
	this->set_ASpeed();
	this->set_result(0);
}
char* Volvo::getname()
{
	return this->name;
}
void Volvo::printdata()
{
	printf("Am apelat functia printdata \n");
}
void Volvo::set_ASpeed()
{
	this->ASpeed = (this->ASpeed_Rain + this->ASpeed_Snow + this->ASpeed_Sunny) / 3;
}
int Volvo::get_FCapacity()
{
	return this->FCapacity;
}
int Volvo::get_FCons()
{
	return this->FCons;
}
int Volvo::get_ASpeed()
{
	return this->ASpeed;
}
int Volvo::get_ASpeed_Rain()
{
	return this->ASpeed_Rain;
}
int Volvo::get_ASpeed_Sunny()
{
	return this->ASpeed_Sunny;
}
int Volvo::get_ASpeed_Snow()
{
	return this->ASpeed_Snow;
}
int Volvo::get_result()
{
	return this->result;
}
void Volvo::set_result(int n)
{
	this->result = n;
}