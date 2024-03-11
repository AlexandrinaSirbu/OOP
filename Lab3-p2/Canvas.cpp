#include "Canvas.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    this->matrix = (char**)(malloc(height * sizeof(char*)));
    for (int i = 0; i < height; i++)
        this->matrix[i] = (char*)(malloc(width * sizeof(char)));

    this->Clear();
}

void Canvas::Clear()
{
    for (int x = 0; x < this->width; x++)
    {
        for (int y = 0; y < this->height; y++)
        {
            SetPoint(x, y, ' ');
        }
    }
}

void Canvas::Print()
{
    for (int x = 0; x < this->width; x++)
    {
        for (int y = 0; y < this->height; y++)
        {
            cout << this->matrix[x][y];
        }
        cout << endl;
    }
}

int f(int i, int j, int x0, int y0, int r)
{
    return pow((i - x0), 2) + pow((j - y0), 2) - pow(r, 2) < 0;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    if ((x >= 0) && (x < this->width) && (y >= 0) && (y < this->height))
        for (int i = x - ray; i <= x + ray; i++)
        {
            for (int j = y - ray; j <= y + ray; j++)
            {
                int d = (j - x) * (j - x) + (i - y) * (i - y);
                if (d >= (ray - 1) * (ray - 1) && d <= (ray + 1) * (ray + 1))
                    SetPoint(i, j, ch);

                else
                    SetPoint(i, j, ' ');
            }
        }
    else exit(0);
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    if ((x >= 0) && (x < this->width) && (y >= 0) && (y < this->height))
        for (int i = x - ray; i <= x + ray; i++)
        {
            for (int j = y - ray; j <= y + ray; j++)
            {
                if (f(i, j, x, y, ray))
                {
                    SetPoint(i, j, ch);
                }
            }
        }
    else exit(0);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    if ((left >= 0) && (right < this->width) && (bottom >= 0) && (top < this->height))
        for (int i = top; i <= bottom; i++)
        {
            for (int j = left; j <= right; j++)
            {
                if (i == top || i == bottom || j == left || j == right)
                    SetPoint(i, j, ch);
            }
        }
    else exit(0);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    if ((left >= 0) && (right < this->width) && (bottom >= 0) && (top < this->height))
        for (int x = top; x <= bottom; x++)
            for (int y = left; y <= right; y++)
                this->SetPoint(x, y, ch);
    else exit(0);
}

void Canvas::SetPoint(int x, int y, char ch)
{
    this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int m_new = 2 * (y2 - y1);
    int anew = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        this->SetPoint(x, y, ch);
        anew += m_new;
        if (anew >= 0)
        {
            y++;
            anew -= 2 * (x2 - x1);
        }
    }
}