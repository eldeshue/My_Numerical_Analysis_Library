#pragma once
// ���׽��� Ŭ������ ������
// �����ڴ� �μ��� 1���� �迭�� ����.
// �迭�� ������ ���� �������� �����ϸ�, �� ���Ҵ� ����� �ȴ�.
// int order = �Է¹��� �迭�� ũ��, ���� ����
// for(int i = order ; i < 0 ; i--);
#include "MyMath.h"
#include "MyMatrix.h"
// ��Ŀ��� ���

class MyPolinomial : public MyMatrix {
	// �ʵ� - �θ�� ����
	
public:
	// �޼ҵ�
	// ������
	MyPolinomial(int m, int n) : MyMatrix(m, n){};
	MyPolinomial(int m, int n, float** input) :MyMatrix(m, n, input){};
	// ���� ������
	MyPolinomial(const MyPolinomial& matrix) :MyMatrix(matrix) {};
	// �Ҹ���
	~MyPolinomial();
	// ���׽� ���
	MyMatrix Calculate(float input); // �ϳ��� ����

	// ���׽� �̺�
	MyPolinomial Differentiate();
	// ���׽� ����
	MyPolinomial Integrate(float* C);
	
};
