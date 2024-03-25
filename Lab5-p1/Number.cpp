#include "Number.h"
#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


Number::Number(const char* value, int base) 
{
	if (base < 2 || base>16)
		return;
	this->base = base;
	strcpy(this->number, value);
}

Number::Number(const Number& n) //copy
{
	this->base = n.base;
	strcpy(this->number, n.number);
}

Number::Number(int nr) //sets base 10 and converts the int to string
{
	base = 10;
	_itoa(nr, this->number, 10);
}

Number::~Number() 
{
	strcpy(this->number, " ");
	this->base = 0;
}

Number::Number(Number&& n) //move
{
	strcpy(this->number, n.number);
	this->base = n.base;
	strcpy(n.number, "");
	this->base = 0;
}

void Number::Print()
{
	cout << this->number << " in base " << this->base << "\n";
}

int Number::GetDigitsCount()
{
	return int(strlen(this->number));
}

int Number::GetBase()
{
	return this->base;
}

char Number::operator[](int index)
{
	return this->number[index];
}

void Number::SwitchBase(int newBase)
{
	int Numar, Baza;
	Numar = atoi(number);
	Baza = base;
	int Rest, Format = 0, P = 1;
	while (Numar != 0)
	{
		Rest = Numar % 10;
		Numar /= 10;
		Format = Format + Rest * P;
		P *= Baza;
	}
	_itoa(Format, number, newBase);
	this->base = newBase;
}

/*
void Number::SwitchBase(int newBase)
{
	int Format = 0, P = 1;
	int len = strlen(this->number);
	for (int i = len - 1; i >= 0; --i) {
		int digit;
		if (isdigit(this->number[i]))
			digit = this->number[i] - '0';
		else if (isalpha(this->number[i]))
			digit = toupper(this->number[i]) - 'A' + 10;
		else {
			cout << "Invalid character in number!" << endl;
			return;
		}
		Format += digit * P;
		P *= base;
	}

	// Convert Format to the new base
	int index = 0;
	while (Format > 0) {
		int remainder = Format % newBase;
		char digitChar;
		if (remainder < 10)
			digitChar = remainder + '0';
		else
			digitChar = remainder - 10 + 'A';
		this->number[index++] = digitChar;
		Format /= newBase;
	}
	this->number[index] = '\0';
	reverse(this->number, this->number + index);

	this->base = newBase;
}
*/

Number& Number::operator=(Number ex)
{
	strcpy(this->number, ex.number);
	this->base = ex.base;
	return (*this);
}

Number& Number::operator=(int numar)
{
	if (base < 2 || base>16)
		base = 10;
	_itoa(numar, number, base);
	return (*this);
}

Number& Number::operator=(const char* numar)
{
	strcpy(this->number, numar);
	return (*this);
}

Number& Number::operator+=(Number ex)
{
	int baza1 = base, baza2 = ex.base;
	if (baza1 > baza2)
		ex.SwitchBase(baza1);
	else
		(*this).SwitchBase(baza2);
	int numar = atoi(number) + atoi(ex.number);
	(*this).SwitchBase(baza1);
	ex.SwitchBase(baza2);
	_itoa(numar, number, base);
	return (*this);
}

Number& Number::operator--() //pre-decrement
{
	strcpy(this->number,this->number + 1);
	return(*this);
}

Number& Number::operator--(int) //post-decrement
{
	this->number[strlen(this->number) - 1] = '\0';
	return *this;
}

bool Number::operator>(Number ex)
{
	int a = this->base;
	(*this).SwitchBase(10);
	int b = ex.base;
	ex.SwitchBase(10);
	bool result = a > b;
	(*this).SwitchBase(a);
	ex.SwitchBase(b);
	return(result);
}