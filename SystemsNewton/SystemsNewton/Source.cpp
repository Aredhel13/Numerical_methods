#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int n = 3;
double **c;

double F(int k, double *x)
{
	switch (k)
	{
	case 1:
		return x[1]*x[1] + x[2]*x[2] + x[3]*x[3] - 1;
	case 2:
		return 2 * x[1]*x[1] + x[2]*x[2] - 4 * x[3];
	case 3:
		return 3 * x[1]*x[1] - 4*x[2] + x[3]*x[3];
	default:
		break;
	}
};

double f(int f, int xi, double x)
{
	switch (f)
	{
	case 1:
		return 2 * x;
	case 2:
		switch (xi)
		{
		case 1:
			return 4 * x;
		case 2:
			return 2 * x;
		case 3:
			return 4;
		default:
			break;
		}
	case 3:
		switch (xi)
		{
		case 1:
			return 6 * x;
		case 2:
			return -4;
		case 3:
			return 2 * x;
		default:
			break;
		}
	default:
		break;
	}
};

double Multimatrix(double **a, double **b)
{
	c = new double*[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[j][k] * b[k][j];
		}
	}
};

double Det(double **a)
{
	double ** B = a;
	double det = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			double c = -B[j][i] / B[i][i]; 
			for (int k = i; k < n; k++)
				B[j][k] += B[i][k] * c;
		}
	double Det = 1;
	for (int i = 0; i < n; i++)
		Det *= B[i][i];
	return Det;
};

void Multi(double **m, double a) 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			m[i][j] *= a;
		}
};

void Obr(double **d)
{

}

int main()
{
	double x[n];
	ifstream in("Start.txt");
	if (in.is_open())
	{
		for (int i = 0; i < n; ++i)
			in >> x[i];
		in.close();
	}
	else
	{
		cout << "Файл не найден.";
	}
}