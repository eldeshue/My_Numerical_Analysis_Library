// 보간법 알고리즘을 구현함

#include<iostream>
#include"MyInterPolation.h"

//분할 차분표 계산 함수
//계산 결과 얻어질 차분표는 2차원 배열의 형태로 저장됨.
double** Divide_Difference(int length, double* x, double* f) {
	// size는 점의 갯수
	// x배열은 입력값, f배열은 결과값
	// 출력할 배열을 할당해야 함.
	double** result = new double* [length];
	for (int i = 0; i < length; i++)
		result[i] = new double[length - i]; // 고차 차분으로 갈수록 피라미드의 형태로 줄어든다.
	// 초기값
	for (int i = 0; i < length; i++)
		result[0][i] = f[i];
	// Recursive
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < length - i; j++) {
			//분모를 어떻게 구현하는가?
			result[i][j] = (result[i - 1][j] - result[i - 1][j + 1]) / (x[j] - x[j + i]);
		}
	}

	return result;
}
