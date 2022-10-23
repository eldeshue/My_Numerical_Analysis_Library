
// �̺�, ���� �˰����� ����
#include <iostream>
#include "Derivative-Integral.h"

// �̺�



// ����
// �Ϲ����� ��� �Ŀ� ���ؼ� ������ �����Ϸ���, �Լ��� ���ڷ� ������ �ʿ䰡 �ִ�.
// �Լ� ������, f_x �� ���ڷ� �޴´�. f_x�Լ��� double���� �����ϸ�, double�� ������ ���ڷ� �ϴ� �Լ��̴�.
// �ʿ信 ���� ������ ����� �� �Լ��� �ۼ��ϰ�, �� �Լ��� �����ͷ� �Ͽ��� ���ڷ� �޴´�.

double trapezoidal(double(*f_x)(double), double a, double b, int n) {

	double h = (b - a) / n;
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += ((*f_x)(a + i * h) + (*f_x)(a + (i + 1) * h));
	}

	return sum * h / 2;
}

double Simpson13rule(double(*f_x)(double), double a, double b, int n) {

	double h = (b - a) / n;
	double sum = 0;
	// n�� 3�� ����� �ܿ쿡�� ������ ������ �����̴�.
	for (int i = 0; i < n / 3; i++) {
		sum += (*f_x)(a + h * (3 * i))
			+ 4 * (*f_x)(a + h * (3 * i + 1))			
			+ (*f_x)(a + h * (3 * i + 2));
	}

	return h / 3 * sum;
}


double Simpson38rule(double(*f_x)(double), double a, double b, int n) {

	double h = (b - a) / n;
	double sum = 0;
	// n�� 3�� ����� �ܿ쿡�� ������ ������ �����̴�.
	for (int i = 0; i < n / 3; i++) {
		sum += (*f_x)(a + h * (3 * i))
			+ 3 * (*f_x)(a + h * (3 * i + 1))
			+ 3 * (*f_x)(a + h * (3 * i + 2))
			+ (*f_x)(a + h * (3 * i + 3));
	}

	return 3 * h / 8 * sum;
}