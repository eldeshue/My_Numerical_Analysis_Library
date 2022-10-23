// ������ �˰����� ������

#include<iostream>
#include"MyInterPolation.h"

//���� ����ǥ ��� �Լ�
//��� ��� ����� ����ǥ�� 2���� �迭�� ���·� �����.
double** Divide_Difference(int length, double* x, double* f) {
	// size�� ���� ����
	// x�迭�� �Է°�, f�迭�� �����
	// ����� �迭�� �Ҵ��ؾ� ��.
	double** result = new double* [length];
	for (int i = 0; i < length; i++)
		result[i] = new double[length - i]; // ���� �������� ������ �Ƕ�̵��� ���·� �پ���.
	// �ʱⰪ
	for (int i = 0; i < length; i++)
		result[0][i] = f[i];
	// Recursive
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < length - i; j++) {
			//�и� ��� �����ϴ°�?
			result[i][j] = (result[i - 1][j] - result[i - 1][j + 1]) / (x[j] - x[j + i]);
		}
	}

	return result;
}
