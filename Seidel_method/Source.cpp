#include "NumberSolution.h"
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");

	// Параметры по умолчанию
	int		N_max = 100000;			// Максимальное число итераций
	int		S = 0;					// Счетчик итераций
	double	eps = 0.0000001;		// Параметр требуемой точности
	double	eps_max = 0;			// Достигнутая точность
	double	n = 3., m = 3.;			// Сетка
	double** V = NULL;				// Искомый вектор 
	double	a, b, c, d;				// Границы области определния уравнения

	//Границы по x и y
	a = 0;
	b = 2;
	c = 0;
	d = 1;

	system("cls");
	cout << "Размерность сетки: " << n << " x " << m << endl << endl;

	cout << "Введите параметр требуемой точности: ";
	cin >> eps;
	cout << endl;
	if (eps <= 0) {
		cout << "Некорректное значение параметра!" << endl;
		return 0;
	}
	system("cls");

	V = MemoryAllocator(n + 1, m + 1);
	FillStartSolution(V, n, m, a, b, c, d);
	ZeidelsMethod(V, n, m, a, b, c, d, eps, N_max, eps_max, S);
	cout << "Итоговое численное решение имеет вид " << endl;
	ShowSolution(V, n, m);

	// выводить истинное решение
	//double h = (b - a) / n;
	//double k = (d - c) / m;
	//Формула правой части не робит
	//FillRightSide(F, n, m, a, c, h, k);
	//cout << F[0][0];

	//Справка
	cout << endl << "#############################################################" << endl << endl;

	cout << "Параметры задачи" << endl;
	cout << "Размерность сетки: (" << n << ", " << m << ")" << endl;
	cout << "X: [" << a << "; " << b << "], Y: [" << c << "; " << d << "]" << endl;
	cout << "Шаг сетки по оси Ox: h = " << (b - a) / n << endl;
	cout << "Шаг сетки по оси Oy: k = " << (d - c) / m << endl << endl;

	cout << "Критерии остановки" << endl;
	cout << "Максимальное кол-во шагов: " << N_max << endl;
	cout << "Заданная точность: " << eps << endl << endl;

	cout.precision(10);
	cout << "Результаты" << endl;
	cout << "Выполнено шагов: " << S << endl;
	cout << "Точность на выходе: " << eps_max << endl;
	cout << "Невязка на выходе: " << DiscrepancyOfSolution(V, n, m, a, b, c, d) << endl;
	cout << "Общая погрешность решения: " << CheckNumSolution(V, n, m, a, b, c, d) << endl;

	cout << endl << "#############################################################" << endl << endl;
	//cout << " * Разность общей погрешности и достигнутой точности " << abs(CheckNumSolution(V, n, m, a, b, c, d) - eps_max) << endl << endl;

	MemoryCleaner(V, n);

	return 0;
}