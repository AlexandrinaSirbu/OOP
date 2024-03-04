#include "student.h"
#include <iostream>
using namespace std;

void student::SetName(char x)
{
	this->Name = x;
}

void student::SetGradeMath(float x)
{
	if ((x > 1) && (x <= 10))
		this->GradeMath = x;
}

void student::SetGradeEngl(float x)
{
	if ((x > 1) && (x <= 10))
		this->GradeEngl = x;
}

void student::SetGradeHist(float x)
{
	if ((x > 1) && (x <= 10))
		this->GradeHist = x;
}

char student::GetName()
{
	return this->Name;
}

float student::GetGradeMath()
{
	return this->GradeMath;
}

float student::GetGradeEngl()
{
	return this->GradeEngl;
}

float student::GetGradeHist()
{
	return this->GradeHist;
}

void student::SetGradeAverage()
{
	this->GradeAverage = (this->GetGradeMath() + this->GetGradeEngl() + this->GetGradeHist()) / 3;
}

float student::GetGradeAverage()
{
	return this->GradeAverage;
}