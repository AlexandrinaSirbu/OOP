#pragma once

#include <initializer_list>
class Sort
{
    int* array;
    int NumberOfElements;
public:
    Sort(int NumberOfElements, int min, int max);
    Sort(int* array, int NumberOfElements);
    Sort(int count, ...);
    Sort(char* string);
    Sort(std::initializer_list<int> initList);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};