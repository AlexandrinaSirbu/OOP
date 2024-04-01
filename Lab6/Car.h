#pragma once
#include <stdio.h>
#include <string.h>
class Car
{
protected:
	char* name;
	int result;
	int FCapacity;
	int FCons;
	int ASpeed;
	int ASpeed_Rain;
	int ASpeed_Sunny;
	int ASpeed_Snow;
public:
	virtual char* getname() = 0;
	virtual void printdata() = 0;
	virtual void set_ASpeed() = 0;
	virtual int get_FCapacity() = 0;
	virtual int get_FCons() = 0;
	virtual int get_ASpeed_Rain() = 0;
	virtual int get_ASpeed_Sunny() = 0;
	virtual int get_ASpeed_Snow() = 0;
	virtual int get_ASpeed() = 0;
	virtual int get_result() = 0;
	virtual void set_result(int n) = 0;
};