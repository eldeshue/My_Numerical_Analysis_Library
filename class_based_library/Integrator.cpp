// 미분방정식의 풀이를 위해 Runge-Kutta 알고리즘을 이용한 적분기.
// 필요한 함수의 인자 : 풀이할 미분방정식 - 함수 포인터, 초기값 x&y, 목적값 , 적분할 구간의 크기(step size) 
#include<iostream>
#include<cmath>  //절댓값 함수
#include<algorithm>  //최대 최소 함수

// RK 1 - 오일러 적분기
double RK1_euler(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step ) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {		
		result += (*f_x)(input, result) * step_size;
		input += step_size;
	}

	return result;
}

// RK 2 - Heun's method
double RK2_Heun(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {
		double k_1 = (*f_x)(input, result);
		double k_2 = (*f_x)(input + step_size, result + k_1 * step_size);

		result += (k_1 / 2 + k_2 / 2) * step_size;
		input += step_size;
	}

	return result;
}

// RK 2 - MidPoint method
double RK2_MidPoint(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {
		double k_1 = (*f_x)(input, result);
		double k_2 = (*f_x)(input + step_size / 2, result + k_1 * step_size / 2);

		result += k_2 * step_size;
		input += step_size;
	}

	return result;
}

// RK 2 - Ralston's method
double RK2_Ralston(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {
		double k_1 = (*f_x)(input, result);
		double k_2 = (*f_x)(input + 3 / 4 * step_size, result + 3 / 4 * k_1 * step_size);

		result += (k_1 + k_2 * 2) / 3 * step_size;
		input += step_size;
	}

	return result;
}

// RK 3 
double RK3(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {
		double k_1 = (*f_x)(input, result);
		double k_2 = (*f_x)(input + step_size / 2, result + k_1 / 2 * step_size);
		double k_3 = (*f_x)(input + step_size, result - k_1 * step_size + k_2 * 2 * step_size);

		result += (k_1 + 4 * k_2 + k_3) / 6 * step_size;
		input += step_size;
	}

	return result;
}
// RK 4
double RK4(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step) {
	// 스텝의 크기
	double step_size = (target_x - init_x) / number_of_step;
	double result = init_y;
	double input = init_x;

	for (int i = 0; i < number_of_step; i++) {
		double k_1 = (*f_x)(input, result);
		double k_2 = (*f_x)(input + step_size / 2, result + k_1 / 2 * step_size);
		double k_3 = (*f_x)(input + step_size / 2, result + k_2 / 2 * step_size);
		double k_4 = (*f_x)(input + step_size , result + k_3 * step_size);

		result += (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6 * step_size;
		input += step_size;
	}

	return result;
}