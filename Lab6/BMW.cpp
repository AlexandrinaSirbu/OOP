#include "BMW.h"
BMW::BMW()
{
	printf("BMW"); printf("\n");
	name = new char[strlen("BMW" + 1)];
	memcpy(name, "BMW", strlen("BMW") + 1);
	FCons = 70;
	FCapacity = 700;
	ASpeed_Sunny = 370;
	ASpeed_Snow = 270;
	ASpeed_Rain = 170;
	this->set_ASpeed();
	this->set_result(0);
}

BMW::~BMW()
{
	delete[] name;
	printf("Am apelat destructorul pentru BMW\n");
	FCons = 0;
	FCapacity = 0;
	ASpeed_Sunny = 0;
	ASpeed_Snow = 0;
	ASpeed_Rain = 0;
	this->set_ASpeed();
	this->set_result(0);
}
char* BMW::getname()
{
	return this->name;
}
void BMW::printdata()
{
	printf("Am apelat functia printdata \n");
}
void BMW::set_ASpeed()
{
	this->ASpeed = (this->ASpeed_Rain + this->ASpeed_Snow + this->ASpeed_Sunny) / 3;
}
int BMW::get_FCapacity()
{
	return this->FCapacity;
}
int BMW::get_FCons()
{
	return this->FCons;
}
int BMW::get_ASpeed()
{
	return this->ASpeed;
}
int BMW::get_ASpeed_Rain()
{
	return this->ASpeed_Rain;
}
int BMW::get_ASpeed_Sunny()
{
	return this->ASpeed_Sunny;
}
int BMW::get_ASpeed_Snow()
{
	return this->ASpeed_Snow;
}
int BMW::get_result()
{
	return this->result;
}
void BMW::set_result(int n)
{
	this->result = n;
}