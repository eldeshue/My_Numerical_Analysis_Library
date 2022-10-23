#include "MyMath.h"
// 다양한 수학적 알고리즘 및 방정식을 정의함.

float Power(float base, int exponent) { //a가 밑, n이 지수. 
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
	// result  값
	// power  승수, 지수의 분모
	// target 수렴 대상, 밑
	// decimal 소수점 아래 자리수
	while (Power(result, power) < target) {
		result = result + Power(0.1, decimal);
	}
	if (Power(result, power) > target) {
		result = result - Power(0.1, decimal);
	}
	return result;
}

float Root(float target, int power, int accuracy) {
	// a가 밑
	// n이 지수의 분모
	// accuracy가 목표로 하는 정확도, 소수점 아래 자리수.
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

//꼬리재귀 예제
int MyFactorial(int n, int ans ) { 
	if (n == 1) { 
		return ans;
	} 
	return MyFactorial(n - 1, n * ans); //꼬리재귀의 요점은 호출시 순수한 값의 전달, 추가 계산 없음. stack-overflow를 막기 위함.
}
