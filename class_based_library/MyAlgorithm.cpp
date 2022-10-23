#include <iostream>
#include <cmath>
#include "MyPolinomial.h"

// n�� ��������Ŀ� ���Ѽ�ġ�ؼ� �˰����� ������.
// ���� ���׽� Polynomial�� ���� 1�ุ ����. ���Ŀ� �߰������� �����ؼ� ������ �ʿ伺 ����.
// InitialGuess
int InitialGuess(float l, float u, MyPolinomial target) {
	if (target.Calculate(l).matrix_content[0][0] * target.Calculate(u).matrix_content[0][0] > 0) {
		//����, ��ȣ�� ����.
		std::cout << "Initial Guess failed." << std::endl;
		return 0;
	}
	else if (target.Calculate(l).matrix_content[0][0] * target.Calculate(u).matrix_content[0][0] == 0) {
		//����, �� �� �ϳ��� 0��.
		std::cout << "Calculation Success, Exact Value." << std::endl;
		if (target.Calculate(l).matrix_content[0][0] == 0) {
			return 1;
		}
		std::cout << "Initial Guess Success." << std::endl;
		return 1;
	}
}

//Bisection
// ����: ���Ѱ�, ���Ѱ�, �ִ� �ݺ���, ���ġ, ���Լ�.
// �������
float Bisection(float l, float u, int MaxStep, float Tol, MyPolinomial target ) {
	// ���� l ~ u�� initial guess
	// initial guess�� �̸� �غ��� ���� �����Ұ�.
	
	if (fabs(target.Calculate((l + u) / 2).matrix_content[0][0]) < Tol ) {
		//���ſ� ����
		std::cout << "Calculation Success, Converged Value." << std::endl;
		if (fabs(target.Calculate((l + u) / 2).matrix_content[0][0]) == 0) {
			std::cout << "Exact Value." << std::endl;
		}
		return (l + u) / 2;
	}
	else if (MaxStep == 0) {
		//���� ����, ���� Ż��
		std::cout << "Maximum step reached, Convergence has failed." << std::endl;
		return (l + u) / 2;
	}
	else {
		//���� �������� pass
		if (target.Calculate((l + u) / 2).matrix_content[0][0] * target.Calculate(l).matrix_content[0][0] > 0) { // l�� �߰����� ��ȣ�� ���ٸ�
			return Bisection(target.Calculate((l + u) / 2).matrix_content[0][0], u, MaxStep - 1, Tol, target); // u�� l�� ��������
		}
		return Bisection(l, target.Calculate((l + u) / 2).matrix_content[0][0], MaxStep - 1, Tol, target);
	}
}

//Newton-Rapson
// ����: �ʱⰪ, ������, ��������, ���Լ�( ���Լ� ).
float Newton_Rapson(float initial, int MaxStep, float Tol, MyPolinomial target ) {

	if (fabs(target.Calculate(initial).matrix_content[0][0]) < Tol) {
		//���� ����
		std::cout << "Calculation Success, Converged Value." << std::endl;
		if (fabs(target.Calculate(initial).matrix_content[0][0]) == 0) {
			std::cout << "Exact Value." << std::endl;
		}
		return initial;
	}
	else if (MaxStep == 0) {
		//���� ����, ���� Ż��
		std::cout << "Maximum step reached, Convergence has failed." << std::endl;
		return initial;
	}
	else {
		//���� �������� pass
		// X_i+1 = X_i - f(X_i) / f'(X_i)
		return Newton_Rapson(initial - target.Calculate(initial).matrix_content[0][0] / target.Differentiate().Calculate(initial).matrix_content[0][0], MaxStep - 1, Tol, target);
	}
}
