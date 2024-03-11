#include "Canvas.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void main()
{
    Canvas d(70, 70);
    d.DrawCircle(25, 25, 10, '*');
    d.FillCircle(25, 25, 7, '*');
    d.Clear();
    d.DrawRect(40, 10, 55, 25, '-');
    d.FillRect(40, 30, 50, 45, '-');
    d.Print();
    d.Clear();
    d.SetPoint(15, 15, ' ');
    d.DrawLine(0, 0, 49, 49, '1');
    d.Print();
    d.Clear();
}