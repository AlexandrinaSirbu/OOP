#include "Math.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

int Math::Add(int x1, int x2)
{
	return x1 + x2;
}

int Math::Add(int x1, int x2, int x3)
{
	return x1 + x2 + x3;
}

int Math::Add(double x1, double x2)
{
	return x1 + x2;
}

int Math::Add(double x1, double x2, double x3)
{
	return x1 + x2 + x3;
}

int Math::Mul(int x1, int x2)
{
	return x1 * x2;
}

int Math::Mul(int x1, int x2, int x3)
{
	return x1 * x2 * x3;
}

int Math::Mul(double x1, double x2)
{
	return x1 * x2;
}

int Math::Mul(double x1, double x2, double x3)
{
	return x1 * x2 * x3;
}

int Math::Add(int count, ...)
{
	int i, sum = 0;
	int val;
	va_list vl;
	va_start(vl, count);
	for (i = 0; i < count; i++)
	{
		val = va_arg(vl, int);
		sum += val;
	}
	va_end(vl);
	return sum;
}

char* Math::Add(const char* x1, const char* x2)
{
	if ((x1 == nullptr) || (x2 == nullptr)) return nullptr;
	int newSize = strlen(x1) + strlen(x2) + 1;
	char* c = (char*)malloc(newSize);
	//memset(c, 0, newSize);

	int result = atoi(x1) + atoi(x2);

	_itoa_s(result, c, sizeof(c), 10);

	return c;
}