// 다항식을 구현함
// MyMatrix를 상속받음.
// 입력은 2차원 배열로 받음.
// 배열의 순서는 높은 차수부터 시작하며, 각 원소는 계수가 된다.
// int colum_length = 입력받은 배열의 크기, 식의 차수
// for(int i = colum_length ; i <= 0 ; i--);
#include <iostream>
#include "MyMatrix.h"
#include "MyPolinomial.h"
#include "MyMath.h"

// 소멸자
MyPolinomial::~MyPolinomial() {
	
}

// 다항식 계산
MyMatrix MyPolinomial::Calculate(float input) { // 하나의 변수
	MyMatrix ans = MyMatrix(row_length, 1);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length ; j++) {
			ans.matrix_content[i][0] = ans.matrix_content[i][0] + matrix_content[i][j] * Power(input, colum_length-1-j);
		}
	}
	return ans;
}

// 다항식 미분
MyPolinomial MyPolinomial::Differentiate() {
	int new_order = colum_length - 1;
	MyPolinomial result = MyPolinomial(row_length, new_order);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < new_order; j++) {
			result.matrix_content[i][j] = (new_order - j) * matrix_content[i][j];
		}
	}
	
	return result;
}
// 다항식 적분
MyPolinomial MyPolinomial::Integrate(float* C) {
	MyPolinomial result = MyPolinomial(row_length, colum_length + 1);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			result.matrix_content[i][j] = matrix_content[i][j] / (colum_length - j);
		}
		result.matrix_content[i][colum_length] = C[i];
	}
	return result;
}
