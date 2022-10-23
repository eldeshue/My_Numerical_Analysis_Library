// ���׽��� ������
// MyMatrix�� ��ӹ���.
// �Է��� 2���� �迭�� ����.
// �迭�� ������ ���� �������� �����ϸ�, �� ���Ҵ� ����� �ȴ�.
// int colum_length = �Է¹��� �迭�� ũ��, ���� ����
// for(int i = colum_length ; i <= 0 ; i--);
#include <iostream>
#include "MyMatrix.h"
#include "MyPolinomial.h"
#include "MyMath.h"

// �Ҹ���
MyPolinomial::~MyPolinomial() {
	
}

// ���׽� ���
MyMatrix MyPolinomial::Calculate(float input) { // �ϳ��� ����
	MyMatrix ans = MyMatrix(row_length, 1);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length ; j++) {
			ans.matrix_content[i][0] = ans.matrix_content[i][0] + matrix_content[i][j] * Power(input, colum_length-1-j);
		}
	}
	return ans;
}

// ���׽� �̺�
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
// ���׽� ����
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
