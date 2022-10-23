#include <iostream>
#include <cmath>
#include "MyPolinomial.h"

// n차 대수방정식에 대한수치해석 알고리즘을 구현함.
// 사용된 다항식 Polynomial은 현재 1행만 사용됨. 추후에 추가적으로 구현해서 개선할 필요성 존재.
// InitialGuess
int InitialGuess(float l, float u, MyPolinomial target) {
	if (target.Calculate(l).matrix_content[0][0] * target.Calculate(u).matrix_content[0][0] > 0) {
		//실패, 부호가 같음.
		std::cout << "Initial Guess failed." << std::endl;
		return 0;
	}
	else if (target.Calculate(l).matrix_content[0][0] * target.Calculate(u).matrix_content[0][0] == 0) {
		//성공, 둘 중 하나는 0값.
		std::cout << "Calculation Success, Exact Value." << std::endl;
		if (target.Calculate(l).matrix_content[0][0] == 0) {
			return 1;
		}
		std::cout << "Initial Guess Success." << std::endl;
		return 1;
	}
}

//Bisection
// 인자: 하한값, 상한값, 최대 반복수, 허용치, 원함수.
// 꼬리재귀
float Bisection(float l, float u, int MaxStep, float Tol, MyPolinomial target ) {
	// 영역 l ~ u가 initial guess
	// initial guess를 미리 해보고 나서 수행할것.
	
	if (fabs(target.Calculate((l + u) / 2).matrix_content[0][0]) < Tol ) {
		//수렴에 성공
		std::cout << "Calculation Success, Converged Value." << std::endl;
		if (fabs(target.Calculate((l + u) / 2).matrix_content[0][0]) == 0) {
			std::cout << "Exact Value." << std::endl;
		}
		return (l + u) / 2;
	}
	else if (MaxStep == 0) {
		//수렴 실패, 루프 탈출
		std::cout << "Maximum step reached, Convergence has failed." << std::endl;
		return (l + u) / 2;
	}
	else {
		//다음 스텝으로 pass
		if (target.Calculate((l + u) / 2).matrix_content[0][0] * target.Calculate(l).matrix_content[0][0] > 0) { // l과 중간값의 부호가 같다면
			return Bisection(target.Calculate((l + u) / 2).matrix_content[0][0], u, MaxStep - 1, Tol, target); // u와 l로 구간설정
		}
		return Bisection(l, target.Calculate((l + u) / 2).matrix_content[0][0], MaxStep - 1, Tol, target);
	}
}

//Newton-Rapson
// 인자: 초기값, 루프수, 수렴조건, 원함수( 도함수 ).
float Newton_Rapson(float initial, int MaxStep, float Tol, MyPolinomial target ) {

	if (fabs(target.Calculate(initial).matrix_content[0][0]) < Tol) {
		//수렴 성공
		std::cout << "Calculation Success, Converged Value." << std::endl;
		if (fabs(target.Calculate(initial).matrix_content[0][0]) == 0) {
			std::cout << "Exact Value." << std::endl;
		}
		return initial;
	}
	else if (MaxStep == 0) {
		//수렴 실패, 루프 탈출
		std::cout << "Maximum step reached, Convergence has failed." << std::endl;
		return initial;
	}
	else {
		//다음 스텝으로 pass
		// X_i+1 = X_i - f(X_i) / f'(X_i)
		return Newton_Rapson(initial - target.Calculate(initial).matrix_content[0][0] / target.Differentiate().Calculate(initial).matrix_content[0][0], MaxStep - 1, Tol, target);
	}
}
