#include<iostream>
#include<cmath>
#include"MyMatrix.h"
// �޸� ���� ���� Ŭ���� �������� �����α׷��� �ʿ���.

// Singular Filter
// ����� determinant�� 0�̸� ��� ����� �Ұ�����, fail!


// Scaling Algorithm
// ����� ��Ұ� �ʹ� 0�� ������, �ſ� ū ���� ���ؼ� ��ô�� �ٲ��ش�. - ������ ������.


// Gauss_Elimination
// A����� ���콺 �Ұ��ϴ� ���
// �������� Ǯ�̿ʹ� ����, ���� ���� ������ Ǯ�̿� LU, cholesky � ����
// factor�� 2���� �迭�� ��Ƽ� return��
float** LU_Decompose_Algorithm(float** A, int row_length, int colum_length) {
	// A�� upper triangle matrix�� ��ȯ�ؾ���.
	// A�� ���� ��� ������ Lower triangular matrix�� return��.
	float Big_pivot;
	float* temp_row;
	// ���� ���� �����Ҵ�.
	float** Low = new float* [row_length];  // ���ذ�� ������ L ���
	for (int i = 0; i < row_length; i++) {
		Low[i] = new float[row_length]; 
		for (int j = 0; j < row_length; j++) {
			Low[i][j] = 0;
		}
		Low[i][i] = 1;
	}
	// ���콺 �Ұ�
	for (int i = 0; i < row_length - 1; i++) { // �ǹ� �������� ���� ����, i
		// Pivoting
 		Big_pivot = A[i][i]; // �ǹ� ��Ҹ� ����
		for (int j = i + 1; j < row_length; j++) {
			if (fabs(Big_pivot) < fabs(A[j][i]) ) {  // ���� ū pivot ��Ҹ� ã�´ٸ�,
				Big_pivot = A[j][i];   //�����ϰ�
				temp_row = A[i];
				A[i] = A[j];
				A[j] = temp_row;  // �� ���� ��ȯ
			}
		}

		for (int j = i + 1; j < row_length; j++) { // �Ұ��� ���� ����, j
			// factor ����
			Low[j][i] = A[j][i] / A[i][i];  // A[i][i]�� 0�� ���� �ʵ��� �Ǻ��� �ʿ���.
			for (int k = i; k < colum_length; k++) {  // ���� index, k
				A[j][k] -= Low[j][i] * A[i][k]; //�Ұ�
			}
		}
	}
	return Low;
}

MyMatrix LU_Decompose_Algorithm(MyMatrix& A) {
	// A����� �޾Ƽ� A�� ���� �ٲٰ� L����� ����
	float Big_pivot;
	float* temp_row;
	
	MyMatrix L = MyMatrix(A.row_length, A.colum_length);
	L.matrix_content[0][0] = 1;
	// ���콺 �Ұ�
	for (int i = 0; i < A.row_length - 1; i++) { // �ǹ� �������� ���� ����, i
		// Pivoting
		Big_pivot = A.matrix_content[i][i]; // �ǹ� ��Ҹ� ����
		for (int j = i + 1; j < A.row_length; j++) {
			if (fabs(Big_pivot) < fabs(A.matrix_content[j][i])) {  // ���� ū pivot ��Ҹ� ã�´ٸ�,
				Big_pivot = A.matrix_content[j][i];   //�����ϰ�
				temp_row = A.matrix_content[i];
				A.matrix_content[i] = A.matrix_content[j];
				A.matrix_content[j] = temp_row;  // �� ���� ��ȯ
			}
		}

		for (int j = i + 1; j < A.row_length; j++) { // �Ұ��� ���� ����, j
			// factor ����
			L.matrix_content[j][i] = A.matrix_content[j][i] / A.matrix_content[i][i];  // A[i][i]�� 0�� ���� �ʵ��� �Ǻ��� �ʿ���.
			for (int k = i; k < A.colum_length; k++) {  // ���� index, k
				A.matrix_content[j][k] -= L.matrix_content[j][i] * A.matrix_content[i][k]; //�Ұ�
			}
		}
		L.matrix_content[i+1][i+1] = 1;
	}


	return L;
}


void Gauss_Jordan_Elimination_Solve() {
	// �Ұ� ��� A�� ������ķ� 

}

// ���콺 �ҰŹ����� ������ Ǯ��
float* Gauss_Elimination_Solve(MyMatrix& A, float* b) {
	// ��� ���
	float* result = new float[A.row_length];
	// A��İ� b���͸� �μ��� ����.
	// A��İ� b�� ��ģ augmented matrix�� �����Ѵ�.
	float** augmented = new float* [A.row_length];
	for (int i = 0; i < A.row_length; i++) {
		augmented[i] = new float[A.colum_length + 1];
		for (int j = 0; j < A.colum_length; j++) {
			augmented[i][j] = A.matrix_content[i][j];  // ��� A
		}
		augmented[i][A.colum_length] = b[i]; // ÷�����, b
	}
	// ���콺 ����
	LU_Decompose_Algorithm(augmented, A.row_length, A.colum_length + 1);
	// ���� ����
	// ���� �����̹Ƿ�, �� �� ���� ���� ������. �ʱⰪ
	result[A.row_length - 1] = augmented[A.row_length - 1][A.colum_length] / augmented[A.row_length - 1][A.colum_length - 1]; 
	for (int i = A.row_length - 2; i >= 0 ; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			augmented[j][A.colum_length] -= result[i + 1] * augmented[j][i + 1]; // �ش� �༺��(i+1)�� �̸� ó���صд�.
		}
		result[i] = augmented[i][A.colum_length] / augmented[i][i];  // �ǹ� �������� ����� x�� ����.
	}
	return result;
}


MyMatrix LU_Solve(MyMatrix& A, float* b) {
    // LU ����
	MyMatrix L = LU_Decompose_Algorithm(A);
	// ���� ����, L & b
	MyMatrix D = MyMatrix(A.row_length, 1); // ������ D
	D.matrix_content[0][0] = b[0];
	for (int i = 1; i < A.row_length; i++) {
		for (int j = i; j < A.row_length; j++) {
			b[j] -= D.matrix_content[i - 1][0] * L.matrix_content[j][i - 1];
		}
		D.matrix_content[i][0] = b[i];
	}
	// ���� ����, U & D
	MyMatrix result = MyMatrix(A.row_length, 1); // ������ x
	result.matrix_content[A.row_length - 1][0] = D.matrix_content[A.row_length - 1][0] / A.matrix_content[A.row_length - 1][A.colum_length - 1];
	for (int i = A.row_length - 2; i >= 0; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			D.matrix_content[j][0] -= result.matrix_content[i + 1][0] * A.matrix_content[j][i + 1]; // �ش� �༺��(i+1)�� �̸� ó���صд�.
		}
		result.matrix_content[i][0] = D.matrix_content[i][0] / A.matrix_content[i][i];  // �ǹ� �������� ����� x�� ����.
	}
	return result;
}

float** Cholesky_Decompose_Algorithm(float** A, int size) {
	// A�� ������ �������, size
	// �밢 ������ 0���� ������ fail... ���� ���Ҽ��� �����ϴ� �˰��� �ʿ���.
	// ���Ҽ��� �����Ѵٸ�, ��Ʈ ��� ����� � ������ �����ϴ°�??
	// ��Ī��� Ȯ��
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] != A[j][i]) { // ���� �ٸ��� 
				std::cout << " The Matrix is not symmetric, Can not apply Choleky Decomposition. " << std::endl;
				return NULL;
			} 
		}
	}
	
	float** result = new float* [size];
	for (int i = 0; i < size; i++) {
		result[i] = new float[size];
		for (int j = 0; j < size; j++)
			result[i][j] = 0; // 0���� �ʱ�ȭ
	}
	//�ʱ�ġ ���
	if (A[0][0] == 0) { // �밢 ������ 0�� �Ǵ� ��츦 ����ó��
		std::cout << " The Matrix has 0 piviot element, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}
	result[0][0] = sqrt(A[0][0]);
	result[1][0] = A[1][0] / result[0][0];
	result[1][1] = sqrt(A[1][1] - result[1][0] * result[1][0]);
	for (int i = 2; i < size; i++) { // i�� L ����
		float temp = 0.0;// �ʱ�ȭ
		for (int j = 0; j < i; j++) {  // i�� j���� L���� ����, �밢 ������ ����
			for (int k = 0; k < j; k++) { //  ������ �ϴ� ���� ���ϱ� ���� ��
				temp += result[j][k] * result[i][k];
			}
			result[i][j] = (A[i][j] - temp) / result[j][j];
			temp = 0; //�ٽ� �ʱ�ȭ
		}
		// �밢 ���� i,i ����
		for (int j = 0; j < i; j++) {
			temp += result[i][j] * result[i][j];
		}
		if (A[i][i] - temp == 0) { // �밢 ������ 0�� �Ǵ� ��츦 ����ó��
			std::cout << " The Matrix has 0 piviot element, cannot apply Choleky Decomposition. " << std::endl;
			return NULL;
		}
		result[i][i] = sqrt(A[i][i] - temp);  // cmath���� ȣ��
	}
	// L�� ��Ī�ؼ� U����
	return result;
}

MyMatrix Cholesky_Decompose_Algorithm(const MyMatrix& A) {
	if (A.row_length != A.colum_length) { // ���� �ٸ��� 
		std::cout << " The Matrix is not square, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}

	for (int i = 0; i < A.row_length; i++) {
		for (int j = 0; j < A.row_length; j++) {
			if (A.matrix_content[i][j] != A.matrix_content[j][i]) { // ���� �ٸ��� 
				std::cout << " The Matrix is not symmetric, Can not apply Choleky Decomposition. " << std::endl;
				return NULL;
			}
		}
	}

	MyMatrix result = MyMatrix(A.row_length, A.colum_length);

	//�ʱ�ġ ���
	if (A.matrix_content[0][0] == 0) { // �밢 ������ 0�� �Ǵ� ��츦 ����ó��
		std::cout << " The Matrix has 0 piviot element, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}
	result.matrix_content[0][0] = sqrt(A.matrix_content[0][0]);
	result.matrix_content[1][0] = A.matrix_content[1][0] / result.matrix_content[0][0];
	result.matrix_content[1][1] = sqrt(A.matrix_content[1][1] - result.matrix_content[1][0] * result.matrix_content[1][0]);
	for (int i = 2; i < A.row_length; i++) { // i�� L ����
		float temp = 0.0;// �ʱ�ȭ
		for (int j = 0; j < i; j++) {  // i�� j���� L���� ����, �밢 ������ ����
			for (int k = 0; k < j; k++) { //  ������ �ϴ� ���� ���ϱ� ���� ��
				temp += result.matrix_content[j][k] * result.matrix_content[i][k];
			}
			result.matrix_content[i][j] = (A.matrix_content[i][j] - temp) / result.matrix_content[j][j];
			temp = 0; //�ٽ� �ʱ�ȭ
		}
		// �밢 ���� i,i ����
		for (int j = 0; j < i; j++) {
			temp += result.matrix_content[i][j] * result.matrix_content[i][j];
		}
		if (A.matrix_content[i][i] - temp == 0) { // �밢 ������ 0�� �Ǵ� ��츦 ����ó��
			std::cout << " The Matrix has 0 piviot element, cannot apply Choleky Decomposition. " << std::endl;
			return NULL;
		}
		result.matrix_content[i][i] = sqrt(A.matrix_content[i][i] - temp);  // cmath���� ȣ��
	}
	// L�� ��Ī�ؼ� U����
	return result;
}

MyMatrix Cholesky_Solve(const MyMatrix& A, float* b) {
	// ��Ī��� �ͷ���Ű �޼ҵ�
	// �Ǻ��� ���ʿ�
	// ���� ���ǵ�(positive - definite) ��Ī���
	
	// �ͷ���Ű ����
	MyMatrix L = Cholesky_Decompose_Algorithm(A);
	MyMatrix U = MyMatrix(A.row_length, A.colum_length);
	// L�� ���� U�� ȹ��
	for (int i = 0; i < A.row_length; i++) {
		for (int j = 0; j < A.row_length; j++) {
			U.matrix_content[i][j] = L.matrix_content[j][i];
		}
	}
	// ���� ����
	MyMatrix D = MyMatrix(A.row_length, 1); // ������  D
	D.matrix_content[0][0] = b[0] / L.matrix_content[0][0];
	for (int i = 1; i < A.row_length; i++) { 
		for (int j = i; j < A.row_length; j++) { // j�� �ݺ�
			b[j] -= D.matrix_content[i - 1][0] * L.matrix_content[j][i - 1];
		}
		D.matrix_content[i][0] = b[i] / L.matrix_content[i][i];
	}
	
	// ���� ����, U & D
	MyMatrix result = MyMatrix(A.row_length, 1); // ������ x
	result.matrix_content[A.row_length - 1][0] = D.matrix_content[A.row_length - 1][0] / U.matrix_content[A.row_length - 1][A.colum_length - 1];
	for (int i = A.row_length - 2; i >= 0; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			D.matrix_content[j][0] -= result.matrix_content[i + 1][0] * U.matrix_content[j][i + 1]; // �ش� �༺��(i+1)�� �̸� ó���صд�.
		}
		result.matrix_content[i][0] = D.matrix_content[i][0] / U.matrix_content[i][i];  // �ǹ� �������� ����� x�� ����.
	}
	return result;
}

// ����� ���ϱ�
// LU�� �ݺ��ؼ� ����.
MyMatrix Inverse_Matrix(const MyMatrix& A) {
	MyMatrix result = MyMatrix(A.row_length, A.colum_length);


	return result;
}


// L-U Example.
// ���� ���� �������� Ǯ���ϴ� ��ġ�ؼ� �˰���
// A�� ���ش��
// N�� ����
// Tol�� ����ġ, degenerate�� Ȯ��
int LUPDecompose(double** A, int N, double Tol, int* P) { // LU ���� �˰���
	int i, j, k, imax;
	double maxA, * ptr, absA;

	for (i = 0; i <= N; i++)
		P[i] = i; // ���� �۹����̼� ��� ����

	for (i = 0; i < N; i++) {
		maxA = 0.0;
		imax = i;
		for (k = i; k < N; k++) {  // �˻� �˰���
			if ((absA = fabs(A[k][i])) > maxA) {
				maxA = absA;
				imax = k;
			}
		}

		if (maxA < Tol) return 0;  // �˻���� �ǹ��� �ִ밪�� Tol���� �����Ƿ� ����, ��� ��ȭ.

		if (imax != i) { // imax == k�� ���, 
			//�Ǻ��� P
			j = P[i];
			P[i] = P[imax];
			P[imax] = j;   // P[i]�� P[imax]�� ��ü

			// A�� ���� pivoting
			ptr = A[i];
			A[i] = A[imax];
			A[imax] = ptr; //���� ��ü

			// �Ǻ��� ����??
			P[N]++;
		}

		for (j = i + 1; j < N; j++) {
			A[j][i] /= A[i][i];  //�밢 �������� ������.
			for (k = i + 1; k < N; k++) {
				A[j][k] -= A[j][i] * A[i][k];
			}
		}
		return 1; // ���� �Ϸ�.
	}

}

