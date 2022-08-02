// Graphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <istream>
#include <math.h>
using namespace std;

//Создание графа
int** create_Graph(int n)
{
	int** G;
	G = new int* [n];
	for (int i = 0; i < n; i++)
		G[i] = new int[n];
	return G;
}
//Удаление графа
void delete_Graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete G[i];
	}
	delete G;
}
//вывести граф в консоль
void Print_Graph(int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << G[i][j] << ' ';
			if (j == n - 1)
				std::cout << std::endl;
		}
	}
}
//подсчитать степень вершин графа
int* deg_G(int* deg_mas, int** G, int n)
{
	for (int i = 0; i < n; i++)
	{
		deg_mas[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (G[i][j] == 1)
				deg_mas[i] += 1;
		}
	}
	return deg_mas;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;//количество вершин графа

	//открытие потока для чтения
	ifstream file;
	file.open("C:/Users/Home/Desktop/Graph.txt", ios::in);

	//Подсчет вершин в графе
	while (1) {
		int buf = 0;
		file >> buf;
		if ((buf == 0) || (buf == 1)) n++;
		if (file.get()=='\n') break;
	}
	cout << "число вершин в графе - " << n << endl << endl;
	cout << "матрица смежности графа:" << endl<<endl;

	int** G = create_Graph(n);//выделение памяти под граф
	int* deg = new int[n];//выделение памяти под массив степеней вершин графа

	//считывание из файла матрицы смежности в граф G
	file.seekg(0, ios::beg);//установка указателя в начало файла
	int i = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int buf = 0;
			file >> buf;
			if ((buf == 0) || (buf == 1))
				G[i][j] = buf;
		}
	}
	file.close();//закрытие потока
	
	Print_Graph(G, n);//вывести граф в консоль
	deg_G(deg, G, n);//подсчет степеней вершин графа

	//вывод массива степеней в консоль
	cout << endl;
	cout << "Степени вершин графа, начиная с 1:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << deg[i] << " ";
	}
	return 0;
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
