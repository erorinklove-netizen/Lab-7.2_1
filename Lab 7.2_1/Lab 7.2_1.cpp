// Lab 7.2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// <Якимів Наталія>
// Лабораторна робота №7.1
// Опрацювання матриці ітераційним способом
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int FindMaxOfRowMins(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int Low = -20, High = 50;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int result = FindMaxOfRowMins(a, k, n);
    cout << "Max of row minimums = " << result << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindMaxOfRowMins(int** a, const int k, const int n)
{
    int maxMin;

    // мінімум першого рядка
    int minRow = a[0][0];
    for (int j = 1; j < n; j++)
        if (a[0][j] < minRow)
            minRow = a[0][j];

    maxMin = minRow;

    // решта рядків
    for (int i = 1; i < k; i++)
    {
        minRow = a[i][0];
        for (int j = 1; j < n; j++)
            if (a[i][j] < minRow)
                minRow = a[i][j];

        if (minRow > maxMin)
            maxMin = minRow;
    }

    return maxMin;
}
