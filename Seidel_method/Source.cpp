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

	// ��������� �� ���������
	int		N_max = 100000;			// ������������ ����� ��������
	int		S = 0;					// ������� ��������
	double	eps = 0.0000001;		// �������� ��������� ��������
	double	eps_max = 0;			// ����������� ��������
	double	n = 3., m = 3.;			// �����
	double** V = NULL;				// ������� ������ 
	double	a, b, c, d;				// ������� ������� ���������� ���������

	//������� �� x � y
	a = 0;
	b = 2;
	c = 0;
	d = 1;

	system("cls");
	cout << "����������� �����: " << n << " x " << m << endl << endl;

	cout << "������� �������� ��������� ��������: ";
	cin >> eps;
	cout << endl;
	if (eps <= 0) {
		cout << "������������ �������� ���������!" << endl;
		return 0;
	}
	system("cls");

	V = MemoryAllocator(n + 1, m + 1);
	FillStartSolution(V, n, m, a, b, c, d);
	ZeidelsMethod(V, n, m, a, b, c, d, eps, N_max, eps_max, S);
	cout << "�������� ��������� ������� ����� ��� " << endl;
	ShowSolution(V, n, m);

	// �������� �������� �������
	//double h = (b - a) / n;
	//double k = (d - c) / m;
	//������� ������ ����� �� �����
	//FillRightSide(F, n, m, a, c, h, k);
	//cout << F[0][0];

	//�������
	cout << endl << "#############################################################" << endl << endl;

	cout << "��������� ������" << endl;
	cout << "����������� �����: (" << n << ", " << m << ")" << endl;
	cout << "X: [" << a << "; " << b << "], Y: [" << c << "; " << d << "]" << endl;
	cout << "��� ����� �� ��� Ox: h = " << (b - a) / n << endl;
	cout << "��� ����� �� ��� Oy: k = " << (d - c) / m << endl << endl;

	cout << "�������� ���������" << endl;
	cout << "������������ ���-�� �����: " << N_max << endl;
	cout << "�������� ��������: " << eps << endl << endl;

	cout.precision(10);
	cout << "����������" << endl;
	cout << "��������� �����: " << S << endl;
	cout << "�������� �� ������: " << eps_max << endl;
	cout << "������� �� ������: " << DiscrepancyOfSolution(V, n, m, a, b, c, d) << endl;
	cout << "����� ����������� �������: " << CheckNumSolution(V, n, m, a, b, c, d) << endl;

	cout << endl << "#############################################################" << endl << endl;
	//cout << " * �������� ����� ����������� � ����������� �������� " << abs(CheckNumSolution(V, n, m, a, b, c, d) - eps_max) << endl << endl;

	MemoryCleaner(V, n);

	return 0;
}