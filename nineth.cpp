﻿// nineth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int main()
{
	using namespace std;
	srand(time(0));
    cout << "Enter n: ";
	int n;
	cin >> n;
	int verticalSum = 0, horizontalSum = 0;
	int **game_table = new int*[n];
	cout << "Before: \n";
	for (size_t i = 0; i < n; i++)
	{
		game_table[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			i == j ? game_table[i][j] = 0 : game_table[i][j] = rand() % 10 + 1;
			cout << game_table[i][j] << " ";
		}
		cout << endl;
	}
	cout << "After: \n";
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			horizontalSum += game_table[i][j];
			verticalSum += game_table[j][i];
		}
		game_table[i][i] = horizontalSum - verticalSum;
		horizontalSum = 0;
		verticalSum = 0;
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << game_table[i][j] << " ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < n; i++)
	{
		delete[] game_table[i];
	}
	delete[] game_table;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
