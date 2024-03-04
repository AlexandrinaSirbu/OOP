#include "NumberList.h"
#include <iostream>
using namespace std;
void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10) return false;
	else {
		numbers[count] = x;
		count++;
		return true;
	}
}

void NumberList::Sort()
{
	int i, j, aux;
	for (i = 0; i < count - 1; i++)
		for (j = 0; j < count - i - 1; j++)
			if (numbers[j] > numbers[j + 1])
			{
				aux = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = aux;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
	cout << endl;
}