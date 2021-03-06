// Метод секущих.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double F(double x)
{
	//return x - 5 * pow(sin(x), 2) - 5;
	//return pow(x, 3) - 18 * x - 83;
	return pow(x, 5) - pow(x, 4) - 6*pow(x, 3);
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	double a, b, res, y, e = 0.001;
	ifstream in("Tochki.txt");
	if (in.is_open())
	{
		in >> a;
		in >> b;
		in.close();
	}
	else
	{
		cout << "Файл не найден.";
	}
	if (F(a)*F(b) <= 0)
	{
		while (fabs(a - b) > e)
		{
			res = b - (((b - a)* F(b)) / (F(b) - F(a)));
			a = b;
			b = res;
		}
		cout.setf(ios::fixed);
		cout << "x = " << a << endl;
	}
	else
	cout << "f(a)*f(b) > 0 => метод не применим" << endl;
	system("pause");
	return 0;
}