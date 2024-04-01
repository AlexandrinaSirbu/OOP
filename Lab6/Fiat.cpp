#include "Fiat.h"
Fiat::Fiat()
{
	printf("Fiat"); printf("\n");
	name = new char[strlen("Fiat" + 1)];
	memcpy(name, "Fiat", strlen("Fiat") + 1);
	FCons = 100;
	FCapacity = 10000;
	ASpeed_Sunny = 300;
	ASpeed_Snow = 250;
	ASpeed_Rain = 270;
	this->set_ASpeed();
	this->set_result(0);
}

Fiat::~Fiat()
{
	printf("Am apelat destructorul pentru Dacia\n");
	FCons = 0;
	FCapacity = 0;
	ASpeed_Sunny = 0;
	ASpeed_Snow = 0;
	ASpeed_Rain = 0;
	this->set_ASpeed();
	this->set_result(0);
}
char* Fiat::getname()
{
	return this->name;
}
void Fiat::printdata()
{
	printf("Am apelat functia printdata \n");
}
void Fiat::set_ASpeed()
{
	this->ASpeed = (this->ASpeed_Rain + this->ASpeed_Snow + this->ASpeed_Sunny) / 3;
}
int Fiat::get_FCapacity()
{
	return this->FCapacity;
}
int Fiat::get_FCons()
{
	return this->FCons;
}
int Fiat::get_ASpeed()
{
	return this->ASpeed;
}
int Fiat::get_ASpeed_Rain()
{
	return this->ASpeed_Rain;
}
int Fiat::get_ASpeed_Sunny()
{
	return this->ASpeed_Sunny;
}
int Fiat::get_ASpeed_Snow()
{
	return this->ASpeed_Snow;
}
int Fiat::get_result()
{
	return this->result;
}
void Fiat::set_result(int n)
{
	this->result = n;
}