#include "global.h"
#include <iostream>
using namespace std;

int CompName(student& s1, student& s2)
{
    char n1 = s1.GetName();
    char n2 = s2.GetName();
    return strcmp(&n1, &n2);
}

int CompGradeMath(student& s1, student& s2)
{
    if (s1.GetGradeMath() >= s2.GetGradeMath()) return 1; else return -1;
}

int CompGradeEngl(student& s1, student& s2)
{
    if (s1.GetGradeEngl() >= s2.GetGradeEngl()) return 1; else return -1;
}

int CompGradeHist(student& s1, student& s2)
{
    if (s1.GetGradeHist() >= s2.GetGradeHist()) return 1; else return -1;
}

int CompGradeAverage(student& s1, student& s2)
{
    if (s1.GetGradeAverage() >= s2.GetGradeAverage()) return 1; else return -1;
}