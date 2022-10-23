#include<iostream>
#include<cmath>
#include"MyMatrix.h"
// 메모리 제어 위한 클래스 형식으로 재프로그래밍 필요함.

// Singular Filter
// 행렬의 determinant가 0이면 행렬 계산이 불가능함, fail!


// Scaling Algorithm
// 행렬의 요소가 너무 0에 가까우면, 매우 큰 수를 곱해서 축척을 바꿔준다. - 에러를 제어함.


// Gauss_Elimination
// A행렬을 가우스 소거하는 행렬
// 방정식의 풀이와는 별개, 이후 연립 방정식 풀이에 LU, cholesky 등에 사용됨
// factor를 2차원 배열에 담아서 return함
float** LU_Decompose_Algorithm(float** A, int row_length, int colum_length) {
	// A는 upper triangle matrix로 전환해야함.
	// A의 분해 결과 생성된 Lower triangular matrix를 return함.
	float Big_pivot;
	float* temp_row;
	// 리턴 값을 동적할당.
	float** Low = new float* [row_length];  // 분해결과 생성된 L 행렬
	for (int i = 0; i < row_length; i++) {
		Low[i] = new float[row_length]; 
		for (int j = 0; j < row_length; j++) {
			Low[i][j] = 0;
		}
		Low[i][i] = 1;
	}
	// 가우스 소거
	for (int i = 0; i < row_length - 1; i++) { // 피벗 방정식인 행을 선택, i
		// Pivoting
 		Big_pivot = A[i][i]; // 피벗 요소를 저장
		for (int j = i + 1; j < row_length; j++) {
			if (fabs(Big_pivot) < fabs(A[j][i]) ) {  // 보다 큰 pivot 요소를 찾는다면,
				Big_pivot = A[j][i];   //저장하고
				temp_row = A[i];
				A[i] = A[j];
				A[j] = temp_row;  // 그 행을 교환
			}
		}

		for (int j = i + 1; j < row_length; j++) { // 소거할 행을 선택, j
			// factor 설정
			Low[j][i] = A[j][i] / A[i][i];  // A[i][i]가 0이 되지 않도록 피보팅 필요함.
			for (int k = i; k < colum_length; k++) {  // 열의 index, k
				A[j][k] -= Low[j][i] * A[i][k]; //소거
			}
		}
	}
	return Low;
}

MyMatrix LU_Decompose_Algorithm(MyMatrix& A) {
	// A행렬을 받아서 A의 값을 바꾸고 L행렬을 리턴
	float Big_pivot;
	float* temp_row;
	
	MyMatrix L = MyMatrix(A.row_length, A.colum_length);
	L.matrix_content[0][0] = 1;
	// 가우스 소거
	for (int i = 0; i < A.row_length - 1; i++) { // 피벗 방정식인 행을 선택, i
		// Pivoting
		Big_pivot = A.matrix_content[i][i]; // 피벗 요소를 저장
		for (int j = i + 1; j < A.row_length; j++) {
			if (fabs(Big_pivot) < fabs(A.matrix_content[j][i])) {  // 보다 큰 pivot 요소를 찾는다면,
				Big_pivot = A.matrix_content[j][i];   //저장하고
				temp_row = A.matrix_content[i];
				A.matrix_content[i] = A.matrix_content[j];
				A.matrix_content[j] = temp_row;  // 그 행을 교환
			}
		}

		for (int j = i + 1; j < A.row_length; j++) { // 소거할 행을 선택, j
			// factor 설정
			L.matrix_content[j][i] = A.matrix_content[j][i] / A.matrix_content[i][i];  // A[i][i]가 0이 되지 않도록 피보팅 필요함.
			for (int k = i; k < A.colum_length; k++) {  // 열의 index, k
				A.matrix_content[j][k] -= L.matrix_content[j][i] * A.matrix_content[i][k]; //소거
			}
		}
		L.matrix_content[i+1][i+1] = 1;
	}


	return L;
}


void Gauss_Jordan_Elimination_Solve() {
	// 소거 결과 A를 단위행렬로 

}

// 가우스 소거법으로 방정식 풀이
float* Gauss_Elimination_Solve(MyMatrix& A, float* b) {
	// 결과 행렬
	float* result = new float[A.row_length];
	// A행렬과 b벡터를 인수로 받음.
	// A행렬과 b를 합친 augmented matrix를 형성한다.
	float** augmented = new float* [A.row_length];
	for (int i = 0; i < A.row_length; i++) {
		augmented[i] = new float[A.colum_length + 1];
		for (int j = 0; j < A.colum_length; j++) {
			augmented[i][j] = A.matrix_content[i][j];  // 행렬 A
		}
		augmented[i][A.colum_length] = b[i]; // 첨가행렬, b
	}
	// 가우스 분해
	LU_Decompose_Algorithm(augmented, A.row_length, A.colum_length + 1);
	// 후진 대입
	// 후진 대입이므로, 맨 끝 값을 먼저 구해줌. 초기값
	result[A.row_length - 1] = augmented[A.row_length - 1][A.colum_length] / augmented[A.row_length - 1][A.colum_length - 1]; 
	for (int i = A.row_length - 2; i >= 0 ; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			augmented[j][A.colum_length] -= result[i + 1] * augmented[j][i + 1]; // 해당 행성분(i+1)을 미리 처리해둔다.
		}
		result[i] = augmented[i][A.colum_length] / augmented[i][i];  // 피벗 성분으로 나누어서 x값 구함.
	}
	return result;
}


MyMatrix LU_Solve(MyMatrix& A, float* b) {
    // LU 분해
	MyMatrix L = LU_Decompose_Algorithm(A);
	// 전진 대입, L & b
	MyMatrix D = MyMatrix(A.row_length, 1); // 열벡터 D
	D.matrix_content[0][0] = b[0];
	for (int i = 1; i < A.row_length; i++) {
		for (int j = i; j < A.row_length; j++) {
			b[j] -= D.matrix_content[i - 1][0] * L.matrix_content[j][i - 1];
		}
		D.matrix_content[i][0] = b[i];
	}
	// 후진 대입, U & D
	MyMatrix result = MyMatrix(A.row_length, 1); // 열벡터 x
	result.matrix_content[A.row_length - 1][0] = D.matrix_content[A.row_length - 1][0] / A.matrix_content[A.row_length - 1][A.colum_length - 1];
	for (int i = A.row_length - 2; i >= 0; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			D.matrix_content[j][0] -= result.matrix_content[i + 1][0] * A.matrix_content[j][i + 1]; // 해당 행성분(i+1)을 미리 처리해둔다.
		}
		result.matrix_content[i][0] = D.matrix_content[i][0] / A.matrix_content[i][i];  // 피벗 성분으로 나누어서 x값 구함.
	}
	return result;
}

float** Cholesky_Decompose_Algorithm(float** A, int size) {
	// A는 무조건 정방행렬, size
	// 대각 성분이 0보다 작으면 fail... 이후 복소수를 포함하는 알고리즘 필요함.
	// 복소수를 포함한다면, 루트 계산 결과를 어떤 식으로 연결하는가??
	// 대칭행렬 확인
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] != A[j][i]) { // 서로 다르면 
				std::cout << " The Matrix is not symmetric, Can not apply Choleky Decomposition. " << std::endl;
				return NULL;
			} 
		}
	}
	
	float** result = new float* [size];
	for (int i = 0; i < size; i++) {
		result[i] = new float[size];
		for (int j = 0; j < size; j++)
			result[i][j] = 0; // 0으로 초기화
	}
	//초기치 계산
	if (A[0][0] == 0) { // 대각 성분이 0이 되는 경우를 예외처리
		std::cout << " The Matrix has 0 piviot element, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}
	result[0][0] = sqrt(A[0][0]);
	result[1][0] = A[1][0] / result[0][0];
	result[1][1] = sqrt(A[1][1] - result[1][0] * result[1][0]);
	for (int i = 2; i < size; i++) { // i행 L 구함
		float temp = 0.0;// 초기화
		for (int j = 0; j < i; j++) {  // i행 j열의 L값을 구함, 대각 성분은 제외
			for (int k = 0; k < j; k++) { //  빼고자 하는 값을 구하기 위한 값
				temp += result[j][k] * result[i][k];
			}
			result[i][j] = (A[i][j] - temp) / result[j][j];
			temp = 0; //다시 초기화
		}
		// 대각 성분 i,i 구함
		for (int j = 0; j < i; j++) {
			temp += result[i][j] * result[i][j];
		}
		if (A[i][i] - temp == 0) { // 대각 성분이 0이 되는 경우를 예외처리
			std::cout << " The Matrix has 0 piviot element, cannot apply Choleky Decomposition. " << std::endl;
			return NULL;
		}
		result[i][i] = sqrt(A[i][i] - temp);  // cmath에서 호출
	}
	// L을 대칭해서 U구함
	return result;
}

MyMatrix Cholesky_Decompose_Algorithm(const MyMatrix& A) {
	if (A.row_length != A.colum_length) { // 서로 다르면 
		std::cout << " The Matrix is not square, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}

	for (int i = 0; i < A.row_length; i++) {
		for (int j = 0; j < A.row_length; j++) {
			if (A.matrix_content[i][j] != A.matrix_content[j][i]) { // 서로 다르면 
				std::cout << " The Matrix is not symmetric, Can not apply Choleky Decomposition. " << std::endl;
				return NULL;
			}
		}
	}

	MyMatrix result = MyMatrix(A.row_length, A.colum_length);

	//초기치 계산
	if (A.matrix_content[0][0] == 0) { // 대각 성분이 0이 되는 경우를 예외처리
		std::cout << " The Matrix has 0 piviot element, Can not apply Choleky Decomposition. " << std::endl;
		return NULL;
	}
	result.matrix_content[0][0] = sqrt(A.matrix_content[0][0]);
	result.matrix_content[1][0] = A.matrix_content[1][0] / result.matrix_content[0][0];
	result.matrix_content[1][1] = sqrt(A.matrix_content[1][1] - result.matrix_content[1][0] * result.matrix_content[1][0]);
	for (int i = 2; i < A.row_length; i++) { // i행 L 구함
		float temp = 0.0;// 초기화
		for (int j = 0; j < i; j++) {  // i행 j열의 L값을 구함, 대각 성분은 제외
			for (int k = 0; k < j; k++) { //  빼고자 하는 값을 구하기 위한 값
				temp += result.matrix_content[j][k] * result.matrix_content[i][k];
			}
			result.matrix_content[i][j] = (A.matrix_content[i][j] - temp) / result.matrix_content[j][j];
			temp = 0; //다시 초기화
		}
		// 대각 성분 i,i 구함
		for (int j = 0; j < i; j++) {
			temp += result.matrix_content[i][j] * result.matrix_content[i][j];
		}
		if (A.matrix_content[i][i] - temp == 0) { // 대각 성분이 0이 되는 경우를 예외처리
			std::cout << " The Matrix has 0 piviot element, cannot apply Choleky Decomposition. " << std::endl;
			return NULL;
		}
		result.matrix_content[i][i] = sqrt(A.matrix_content[i][i] - temp);  // cmath에서 호출
	}
	// L을 대칭해서 U구함
	return result;
}

MyMatrix Cholesky_Solve(const MyMatrix& A, float* b) {
	// 대칭행렬 촐레스키 메소드
	// 피보팅 불필요
	// 양의 정의된(positive - definite) 대칭행렬
	
	// 촐레스키 분해
	MyMatrix L = Cholesky_Decompose_Algorithm(A);
	MyMatrix U = MyMatrix(A.row_length, A.colum_length);
	// L로 부터 U를 획득
	for (int i = 0; i < A.row_length; i++) {
		for (int j = 0; j < A.row_length; j++) {
			U.matrix_content[i][j] = L.matrix_content[j][i];
		}
	}
	// 전진 대입
	MyMatrix D = MyMatrix(A.row_length, 1); // 열벡터  D
	D.matrix_content[0][0] = b[0] / L.matrix_content[0][0];
	for (int i = 1; i < A.row_length; i++) { 
		for (int j = i; j < A.row_length; j++) { // j행 반복
			b[j] -= D.matrix_content[i - 1][0] * L.matrix_content[j][i - 1];
		}
		D.matrix_content[i][0] = b[i] / L.matrix_content[i][i];
	}
	
	// 후진 대입, U & D
	MyMatrix result = MyMatrix(A.row_length, 1); // 열벡터 x
	result.matrix_content[A.row_length - 1][0] = D.matrix_content[A.row_length - 1][0] / U.matrix_content[A.row_length - 1][A.colum_length - 1];
	for (int i = A.row_length - 2; i >= 0; i--) {
		for (int j = A.row_length - 2; j >= 0; j--) {
			D.matrix_content[j][0] -= result.matrix_content[i + 1][0] * U.matrix_content[j][i + 1]; // 해당 행성분(i+1)을 미리 처리해둔다.
		}
		result.matrix_content[i][0] = D.matrix_content[i][0] / U.matrix_content[i][i];  // 피벗 성분으로 나누어서 x값 구함.
	}
	return result;
}

// 역행렬 구하기
// LU를 반복해서 구함.
MyMatrix Inverse_Matrix(const MyMatrix& A) {
	MyMatrix result = MyMatrix(A.row_length, A.colum_length);


	return result;
}


// L-U Example.
// 선형 연립 방정식을 풀이하는 수치해석 알고리즘
// A가 분해대상
// N이 차수
// Tol이 허용수치, degenerate를 확인
int LUPDecompose(double** A, int N, double Tol, int* P) { // LU 분해 알고리즘
	int i, j, k, imax;
	double maxA, * ptr, absA;

	for (i = 0; i <= N; i++)
		P[i] = i; // 단위 퍼뮤테이션 행렬 생성

	for (i = 0; i < N; i++) {
		maxA = 0.0;
		imax = i;
		for (k = i; k < N; k++) {  // 검색 알고리즘
			if ((absA = fabs(A[k][i])) > maxA) {
				maxA = absA;
				imax = k;
			}
		}

		if (maxA < Tol) return 0;  // 검색결과 피벗의 최대값이 Tol보다 작으므로 실패, 행렬 퇴화.

		if (imax != i) { // imax == k인 경우, 
			//피보팅 P
			j = P[i];
			P[i] = P[imax];
			P[imax] = j;   // P[i]와 P[imax]를 교체

			// A의 행을 pivoting
			ptr = A[i];
			A[i] = A[imax];
			A[imax] = ptr; //행을 교체

			// 피봇을 샌다??
			P[N]++;
		}

		for (j = i + 1; j < N; j++) {
			A[j][i] /= A[i][i];  //대각 성분으로 나눈다.
			for (k = i + 1; k < N; k++) {
				A[j][k] -= A[j][i] * A[i][k];
			}
		}
		return 1; // 분해 완료.
	}

}

