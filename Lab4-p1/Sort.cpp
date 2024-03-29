#include "Sort.h"
#include < stdio.h >  
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <string.h>
using namespace std;

Sort::Sort(int NumberOfElements, int min, int max)
{
    this->NumberOfElements = NumberOfElements;
    this->array = (int*)(malloc(NumberOfElements * sizeof(int)));
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < NumberOfElements; i++)
    {
        this->array[i] = min + rand() % (min - max + 1);
    }
}

Sort::Sort(int* vector, int NumberOfElements)
{
    this->NumberOfElements = NumberOfElements;
    this->array = (int*)(malloc(NumberOfElements * sizeof(int)));
    for (int i = 0; i < NumberOfElements; i++)
    {
        this->array[i] = vector[i];
    }
}

Sort::Sort(int count, ...)
{
    this->array = (int*)(malloc(count * sizeof(int)));
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
    {
        this->array[i] = va_arg(vl, int);
    }
    va_end(vl);
    this->NumberOfElements = count;
}

Sort::Sort(char* string)
{
    int n = 1;
    this->array = (int*)(malloc(n * sizeof(int)));
    char* number;
    char* next_number;
    int i = 0;
    number = strtok_s(string, ",", &next_number);
    while (number)
    {
        this->array[i] = atoi(number);
        i++;
        n++;
        this->array = (int*)(realloc(array, n * sizeof(int)));
        number = strtok_s(NULL, ",", &next_number);
    }
    this->NumberOfElements = n - 1;
}

Sort::Sort(std::initializer_list<int> initList) : NumberOfElements(initList.size())
{
    this->array = new int[NumberOfElements];
    int i = 0;
    for (auto it = initList.begin(); it != initList.end(); ++it)
    {
        this->array[i++] = *it;
    }
}



void Sort::InsertSort(bool ascendent)
{
    for (int step = 1; step < NumberOfElements; step++)
    {
        int key = array[step];
        int j = step - 1;
        // Adjust the condition based on the boolean argument
        while ((ascendent && key < array[j]) || (!ascendent && key > array[j]) && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, bool ascendent)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if ((ascendent && arr[j] < pivot) || (!ascendent && arr[j] > pivot))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, ascendent);
        quickSort(arr, low, pi - 1, ascendent);
        quickSort(arr, pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    quickSort(this->array, 0, this->NumberOfElements - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j;
    for (i = 0; i < this->NumberOfElements - 1; i++)
        for (j = 0; j < this->NumberOfElements - i - 1; j++)
            // Adjust the condition based on the boolean argument
            if ((ascendent && array[j] > array[j + 1]) || (!ascendent && array[j] < array[j + 1]))
                swap(&array[j], &array[j + 1]);
}

void Sort::Print()
{
    int i;
    for (i = 0; i < NumberOfElements; i++)
        cout << array[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return this->NumberOfElements;
}

int Sort::GetElementFromIndex(int index)
{
    return this->array[index];
}