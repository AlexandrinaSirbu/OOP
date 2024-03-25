#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include  <cstdlib> 
class Number
{
	char number[50];
	int base;
public:
	Number(const char* value, int base);
	Number(int nr);
	~Number();

	Number(const Number& n);
	Number(Number&& n);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
	char operator[](int index);

	Number& operator=(Number ex);
	Number& operator=(int number);
	Number& operator=(const char* number);
	Number& operator+=(Number ex);

	friend Number operator+(Number ex1, Number ex2) {
		int b1 = ex1.base, b2 = ex2.base;
		if (ex2.base != 10 && ex1.base != 10)
		{
			ex1.SwitchBase(10);
			ex2.SwitchBase(10);
		}
		else
		{
			_itoa(atoi(ex1.number) + atoi(ex2.number), ex1.number, 10);
		}
		ex1.SwitchBase(ex1.base);
		ex2.SwitchBase(ex2.base);
		return (ex1);
	}


	friend Number operator-(Number ex1, Number ex2) {
		int b1 = ex1.base, b2 = ex2.base;
		if (ex2.base != 10 && ex1.base != 10)
		{
			ex1.SwitchBase(10);
			ex2.SwitchBase(10);
		}
		else
		{
			_itoa(atoi(ex1.number) - atoi(ex2.number), ex1.number, 10);
		}
		ex1.SwitchBase(ex1.base);
		ex2.SwitchBase(ex2.base);
		return (ex1);
	}
	Number& operator--();
	Number& operator--(int number);

	bool operator>(Number ex);

};