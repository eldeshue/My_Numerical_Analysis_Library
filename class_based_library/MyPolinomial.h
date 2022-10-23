#pragma once
// 다항식을 클래스로 구현함
// 생성자는 인수로 1차원 배열을 받음.
// 배열의 순서는 높은 차수부터 시작하며, 각 원소는 계수가 된다.
// int order = 입력받은 배열의 크기, 식의 차수
// for(int i = order ; i < 0 ; i--);
#include "MyMath.h"
#include "MyMatrix.h"
// 행렬에서 상속

class MyPolinomial : public MyMatrix {
	// 필드 - 부모와 동일
	
public:
	// 메소드
	// 생성자
	MyPolinomial(int m, int n) : MyMatrix(m, n){};
	MyPolinomial(int m, int n, float** input) :MyMatrix(m, n, input){};
	// 복사 생성자
	MyPolinomial(const MyPolinomial& matrix) :MyMatrix(matrix) {};
	// 소멸자
	~MyPolinomial();
	// 다항식 계산
	MyMatrix Calculate(float input); // 하나의 변수

	// 다항식 미분
	MyPolinomial Differentiate();
	// 다항식 적분
	MyPolinomial Integrate(float* C);
	
};
