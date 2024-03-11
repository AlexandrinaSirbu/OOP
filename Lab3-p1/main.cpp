#include "Math.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	Math m;
	cout << m.Add(5, 3) << endl;
	cout << m.Add(5, 3, 4) << endl;
	cout << m.Add(5.3, 1.5) << endl;
	cout << m.Add(5.3, 1.5, 2.0) << endl;
	cout << m.Mul(4, 2) << endl;
	cout << m.Mul(4, 2, 6) << endl;
	cout << m.Mul(4.1, 5.3) << endl;
	cout << m.Mul(4.1, 5.3, 2.1) << endl;
	cout << m.Add(3, 5, 4, 8) << endl;
	cout << m.Add("5", "7") << endl;

	return 0;
}