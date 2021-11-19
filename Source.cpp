#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int MaxMin(int** a, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 20;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	cout << "max = " << MaxMin(a, n);
	delete[] a;

	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int MaxMin(int** a, const int n)
{
	int* min = new int[n];
	for (int i = 0; i < n; i++)
	{
		min[i] = a[i][0];
		for (int j = 1; j < n; j++)
			if (a[i][j] < min[i])
				min[i] = a[i][j];
	}
	int max = min[0];
	for (int i = 1; i < n; i++)
		if (min[i] > max)
			max = min[i];
	delete[] min;
	return max;
}
