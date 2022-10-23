
// 미분, 적분 알고리즘의 구현
#include <iostream>
#include "Derivative-Integral.h"

// 미분



// 적분
// 일반적인 모든 식에 대해서 적분을 수행하려면, 함수를 인자로 전달할 필요가 있다.
// 함수 포인터, f_x 를 인자로 받는다. f_x함수는 double형을 리턴하며, double형 변수를 인자로 하는 함수이다.
// 필요에 따라서 적분의 대상이 될 함수를 작성하고, 이 함수를 포인터로 하여서 인자로 받는다.

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
	// n이 3의 배수일 겨우에만 적용이 가능한 공식이다.
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
	// n이 3의 배수일 겨우에만 적용이 가능한 공식이다.
	for (int i = 0; i < n / 3; i++) {
		sum += (*f_x)(a + h * (3 * i))
			+ 3 * (*f_x)(a + h * (3 * i + 1))
			+ 3 * (*f_x)(a + h * (3 * i + 2))
			+ (*f_x)(a + h * (3 * i + 3));
	}

	return 3 * h / 8 * sum;
}