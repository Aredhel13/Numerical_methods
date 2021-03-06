#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

double *r, **a, *x;
int n, m, i = 0;

void Progonka(double **A, double *f, double *y, int n) {
	double *al = new double[n - 1], *b = new double[n - 1];
	// вычисляем alpha_0 и beta_0
	al[0] = -1.0*A[0][1] / A[0][0];
	b[0] = f[0] / A[0][0];
	// вычисляем alpha_i и beta_i
	for (int i = 1; i < n - 1; i++) {
		al[i] = -1.0*A[i][i + 1] / (A[i][i] + A[i][i - 1] * al[i - 1]);
		b[i] = (f[i] - b[i - 1] * A[i][i - 1]) / (A[i][i] + A[i][i - 1] * al[i - 1]);
	}
	// вычисляем y_n
	y[n - 1] = (f[n - 1] - A[n - 1][n - 2] * b[n - 2]) / (A[n - 1][n - 1] + A[n - 1][n - 2] * al[n - 2]);
	// вычисляем y_i
	for (int i = n - 2; i >= 0; i--)
		y[i] = al[i] * y[i + 1] + b[i];

	cout << "Решение:\n" << endl;
	for (int i = 0; i < n; i++)
		cout << "x[" << i + 1 << "]=" << y[i] << endl;

	delete[] al;
	delete[] b;
	delete[] y;

}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//Создаем файловый поток и связываем его с файлом
	ifstream in("mas2.txt");

	if (in.is_open())
	{
		//Если открытие файла прошло успешно
		int c_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			in.get(symbol);
			if (symbol == ' ')
				c_space++;
			if (symbol == '\n') break;
		}

		in.seekg(0, ios::beg);
		in.clear();

		m = c_space + 1;	//число чисел в строке (на единицу больше, чем пробелов)
		n = c_space;	//размер матрицы(n*n) без вектора значений
		r = new double[n];
		a = new double*[n];
		for (int i = 0; i < n; i++)
			a[i] = new double[n];
		int i = 0;
		//Считаем матрицу из файла
		while (!in.eof())
		{
			for (int j = 0; j < n; j++)
				in >> a[i][j];
			in >> r[i];
			i++;
		}

		cout << endl;
		//Выведем матрицу
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << "\t";
			cout << "\n";
		}

		in.close();//под конец закроем файла
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не найден.";
	}

	double **A = new double*[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			A[i][j] = a[i][j];
			if (abs(j - i) > 1 && A[i][j] != 0.0)
				cout << "ОШИБКА! Вы ввели не трёхдиагональную матрицу\n";
		}
	double *x = new double[n];
	Progonka(A, r, x, n);
	system("pause>nul");
	return 0;
}
