#include "pch.h"
#include <iostream>
#include <vector>
#include <conio.h>


void printArray(std::vector<int>arr);
void printArray(std::vector<std::vector<int>>arr);
int getMin(std::vector<int>arr);


int main()
{
	unsigned short n, a;
	std::cout << "Input amount of elements: ";
	std::cin >> n;
	system("CLS");

	std::vector<int>arr1(n);
	short int start = -1, end = -1;
	int sum = 0;
	for (a = 0; a < n; a++)
	{
		std::cout << "Inpuy arr(" << a + 1 << "): ";
		std::cin >> arr1[a];
		system("CLS");
		if ((start == -1) && (arr1[a] > 0))
			start = a;
		else
			if (arr1[a] < 0)
				end = a;

		if ((start >= 0) && ((end == -1) || (end == a)))
			sum += arr1[a];
	}

	if ((start >= 0) && (end >= 1))
		std::cout << "Sum = " << sum;
	else
		if (start == -1)
			std::cout << "Нет положительныъ чисел";
		else if (end == -1)
			std::cout << "Нет отрицательных чисел";

	/////////////////////////////////////////////////////////////////////
	std::cout << "\n\nPress any key to continue and to go throgh Exercise 2";
	_getch();
	system("CLS");
	/////////////////////////////////////////////////////////////////////

	unsigned short m, b;

	std::cout << "Input amount of lines: ";
	std::cin >> n;
	system("CLS");
	std::cout << "Input amount of columns: ";
	std::cin >> m;
	system("CLS");

	std::vector<std::vector<int>>arr2(n);
	for (a = 0; a < n; a++)
	{
		arr2[a].resize(m);
		for (b = 0; b < m; b++)
		{
			std::cout << "Input arr(" << a + 1 << ", " << b + 1 << "): ";
			std::cin >> arr2[a][b];
			system("CLS");
		}
	}

	std::cout << "Stock array:\n";
	printArray(arr2);

	for (a = 0; a < (n - 1); a++)
		for (b = 0; b < (n - 1); b++)
			if (getMin(arr2[b]) > getMin(arr2[b + 1]))
				std::swap(arr2[b], arr2[b + 1]);

	std::cout << "\n\nSorted array:\n";
	printArray(arr2);

	return 0;
}


void printArray(std::vector<int>arr)
{
	for (unsigned short i = 0; i < arr.size(); i++)
		std::cout << arr[i] << '\t';
}


void printArray(std::vector<std::vector<int>>arr)
{
	for (unsigned short i = 0; i < arr.size(); i++)
	{
		printArray(arr[i]);
		std::cout << '\n';
	}
}


int getMin(std::vector<int>arr)
{
	int min = arr[0];
	for (unsigned short i = 1; i < arr.size(); i++)
		if (arr[i] < min)
			min = arr[0];

	return min;
}