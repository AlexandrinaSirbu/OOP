#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	~Volvo();
	char* getname();
	void printdata();
	void set_ASpeed();
	int get_FCapacity();
	int get_FCons();
	int get_ASpeed_Rain();
	int get_ASpeed_Sunny();
	int get_ASpeed_Snow();
	int get_ASpeed();
	int get_result();
	void set_result(int n);
};