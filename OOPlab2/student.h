#pragma once
class student
{
private:
	char Name;
	float GradeMath;
	float GradeEngl;
	float GradeHist;
	float GradeAverage;
public:
	void SetName(char x);
	void SetGradeMath(float x);
	void SetGradeEngl(float x);
	void SetGradeHist(float x);
	void SetGradeAverage();
	char GetName();
	float GetGradeMath();
	float GetGradeEngl();
	float GetGradeHist();
	float GetGradeAverage();
};