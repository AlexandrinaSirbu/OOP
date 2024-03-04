#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
	NumberList p;
	p.Init();
	p.Add(5);
	p.Add(55);
	p.Add(6);
	p.Add(1);
	p.Print();
	p.Sort();
	p.Print();

	p.Add(14);
	p.Add(10);
	p.Add(7);
	p.Add(1);
	p.Sort();
	p.Print();

	p.Add(5);
	p.Add(55);
	p.Add(6);
	p.Add(1);
	p.Sort();
	p.Print();

	return 0;
}