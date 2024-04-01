#include "RangeRover.h"
RangeRover::RangeRover()
{
	printf("RangeRover"); printf("\n");
	name = new char[strlen("RangeRover" + 1)];
	memcpy(name, "RangeRover", strlen("RangeRover") + 1);
	FCons = 15;
	FCapacity = 1500;
	ASpeed_Sunny = 150;
	ASpeed_Snow = 100;
	ASpeed_Rain = 250;
	this->set_ASpeed();
	this->set_result(0);
}

RangeRover::~RangeRover()
{
	printf("Am apelat destructorul pentru RangeRover\n");
	FCons = 0;
	FCapacity = 0;
	ASpeed_Sunny = 0;
	ASpeed_Snow = 0;
	ASpeed_Rain = 0;
	this->set_ASpeed();
	this->set_result(0);
}
char* RangeRover::getname()
{
	return this->name;
}
void RangeRover::printdata()
{
	printf("Am apelat functia printdata \n");
}
void RangeRover::set_ASpeed()
{
	this->ASpeed = (this->ASpeed_Rain + this->ASpeed_Snow + this->ASpeed_Sunny) / 3;
}
int RangeRover::get_FCapacity()
{
	return this->FCapacity;
}
int RangeRover::get_FCons()
{
	return this->FCons;
}
int RangeRover::get_ASpeed()
{
	return this->ASpeed;
}
int RangeRover::get_ASpeed_Rain()
{
	return this->ASpeed_Rain;
}
int RangeRover::get_ASpeed_Sunny()
{
	return this->ASpeed_Sunny;
}
int RangeRover::get_ASpeed_Snow()
{
	return this->ASpeed_Snow;
}
int RangeRover::get_result()
{
	return this->result;
}
void RangeRover::set_result(int n)
{
	this->result = n;
}