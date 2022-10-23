#include "MyMath.h"
// �پ��� ������ �˰��� �� �������� ������.

float Power(float base, int exponent) { //a�� ��, n�� ����. 
	float result = 1.0;
	if (exponent == 0) return result;

	if (exponent < 0) {
		for (int i = 0; i < -exponent; i++)
			result *= base;

		return 1/result;
	}

	for (int i = 0; i < exponent; i++)
		result *= base;

	return result;
}

float exp(int exponent) {
	return Power(2.7182818284, exponent);
}

float decimal_step(float& result, int power, float target, int decimal) {
	// result  ��
	// power  �¼�, ������ �и�
	// target ���� ���, ��
	// decimal �Ҽ��� �Ʒ� �ڸ���
	while (Power(result, power) < target) {
		result = result + Power(0.1, decimal);
	}
	if (Power(result, power) > target) {
		result = result - Power(0.1, decimal);
	}
	return result;
}

float Root(float target, int power, int accuracy) {
	// a�� ��
	// n�� ������ �и�
	// accuracy�� ��ǥ�� �ϴ� ��Ȯ��, �Ҽ��� �Ʒ� �ڸ���.
	float result = 0;
	
	for (int i = 0; i <= accuracy; i++) {
		result = decimal_step(result, power, target, i);
	}
	
	return result;
}

/*
float log_taylor() {


}
*/

//������� ����
int MyFactorial(int n, int ans ) { 
	if (n == 1) { 
		return ans;
	} 
	return MyFactorial(n - 1, n * ans); //��������� ������ ȣ��� ������ ���� ����, �߰� ��� ����. stack-overflow�� ���� ����.
}
