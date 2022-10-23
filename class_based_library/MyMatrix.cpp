// 설계한 행렬 클래스에 대한 구현을 여기에....
#include"MyMatrix.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include <cmath>  // 삼각함수는 radian scale

const float pi = 3.14159265358979;
// 기본 생성자
MyMatrix::MyMatrix() {
	row_length = 2;
	colum_length = 2;
	matrix_content = new float* [2];
	matrix_content[0] = new float[2];
	matrix_content[1] = new float[2];
}
// m X m 단위행렬 생성
MyMatrix::MyMatrix(int m) {
	row_length = m;
	colum_length = m;

	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++) {
		matrix_content[i] = new float[colum_length];
		for (int j = 0; j < colum_length; j++)
			matrix_content[i][j] = 0; //기본적으로는 0으로 초기화 함.
		matrix_content[i][i] = 1;
	}
	
}

// m X n 영행렬 생성
MyMatrix::MyMatrix(int m, int n) {
	row_length = m;
	colum_length = n;
	
	//동적 할당.
	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++) {
		matrix_content[i] = new float[colum_length];
		for (int j = 0; j < colum_length; j++)
			matrix_content[i][j] = 0; //기본적으로는 0으로 초기화 함.
	}
}

MyMatrix::MyMatrix(int n, float* input) {
	row_length = 1;
	colum_length = n;
	
	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++) {
		matrix_content[i] = new float[colum_length];
		for (int j = 0; j < colum_length; j++)
			matrix_content[i][j] = input[j]; 
	}
}

MyMatrix::MyMatrix(int m, int n, float** input) {
	row_length = m;
	colum_length = n;

	// 메모리 동적 할당.
	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++) {
		matrix_content[i] = new float[colum_length];
	}
	// 초기화
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++)
			matrix_content[i][j] = input[i][j];
	}
}

MyMatrix::MyMatrix(int m, int n, float input[]) {
	int x = 0;
	row_length = m;
	colum_length = n;
	//메모리 할당.
	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++)
		matrix_content[i] = new float[colum_length];
	//초기화
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			matrix_content[i][j] = input[x + j];
		}
		x = x + n;
	}
}
//정방행렬들
MyMatrix::MyMatrix(float row1[2], float row2[2]) {
	row_length = 2;
	colum_length = 2;
	//메모리 할당
	matrix_content = new float* [2];
	matrix_content[0] = new float[2];
	matrix_content[1] = new float[2];
	//초기화
	matrix_content[0][0] = row1[0];
	matrix_content[0][1] = row1[1];
	matrix_content[1][0] = row2[0];
	matrix_content[1][1] = row2[1];
}
MyMatrix::MyMatrix(float row1[3], float row2[3], float row3[3]) {
	row_length = 3;
	colum_length = 3;
	//메모리 할당
	matrix_content = new float* [3];
	matrix_content[0] = new float[3];
	matrix_content[1] = new float[3];
	matrix_content[2] = new float[3];
	//초기화
	matrix_content[0][0] = row1[0];
	matrix_content[0][1] = row1[1];
	matrix_content[0][2] = row1[2];
	matrix_content[1][0] = row2[0];
	matrix_content[1][1] = row2[1];
	matrix_content[1][2] = row2[2];
	matrix_content[2][0] = row2[0];
	matrix_content[2][1] = row2[1];
	matrix_content[2][2] = row2[2];
}

// 복사 생성자
MyMatrix::MyMatrix(const MyMatrix& matrix) {
	// 인수로 참조자를 받아옴.
	// deepcopy 필요함.
	row_length = matrix.row_length;
	colum_length = matrix.colum_length;

	//메모리 할당
	matrix_content = new float* [row_length];
	for (int i = 0; i < row_length; i++) {
		matrix_content[i] = new float[colum_length];
	}
	// 초기화
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			matrix_content[i][j] = matrix.matrix_content[i][j];
		}
	}
}
// 소멸자
MyMatrix::~MyMatrix() {
	if (matrix_content != NULL) {  // 중복 해제를 막는다.
		for (int i = 0; i < row_length; i++)
 			delete[] matrix_content[i];
		delete[] matrix_content;
		matrix_content = NULL; // 소멸 체크
	}
}

void MyMatrix::ShowMatrix() {
	for (int i = 0; i < 3 * colum_length; i++)	std::cout << "--";
	std::cout << std::endl;
	std::cout << row_length << " X " << colum_length << " Matrix." << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			std::cout << std::setw(10) << matrix_content[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 3* colum_length; i++)	std::cout << "--";
	std::cout << std::endl;
}

void MyMatrix::Clear() {
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			matrix_content[i][j] = 0;
		}
	}
}

void MyMatrix::Clear_One() {
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			matrix_content[i][j] = 1;
		}
	}
}

MyMatrix MyMatrix::TransPose() {
	MyMatrix Temp = MyMatrix(this->colum_length, this->row_length);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			Temp.matrix_content[i][j] = matrix_content[j][i];
		}
	}	
	return Temp;
}
MyMatrix MyMatrix::Inverse() {
	if (row_length == colum_length && colum_length == 2) {
		MyMatrix Temp = MyMatrix(2, 2);
		float det = matrix_content[0][0] * matrix_content[1][1] - matrix_content[0][1] * matrix_content[1][0];
		Temp.matrix_content[0][0] = matrix_content[1][1] / det;
		Temp.matrix_content[1][1] = matrix_content[0][0] / det;
		Temp.matrix_content[0][1] = -1 * matrix_content[0][1] / det;
		Temp.matrix_content[1][0] = -1 * matrix_content[1][0] / det;
		return Temp;
	}
	else if (row_length == colum_length && colum_length == 3) {
		MyMatrix Temp = MyMatrix(3, 3);
		float det = matrix_content[0][0] * (matrix_content[1][1] * matrix_content[2][2] - matrix_content[1][2] * matrix_content[2][1])
			      - matrix_content[0][1] * (matrix_content[1][0] * matrix_content[2][2] - matrix_content[1][2] * matrix_content[2][0])
			      + matrix_content[0][2] * (matrix_content[1][0] * matrix_content[2][1] - matrix_content[1][1] * matrix_content[2][0]);
		Temp.matrix_content[0][0] = (matrix_content[1][1] * matrix_content[2][2] - matrix_content[1][2] * matrix_content[2][1]) / det;
		Temp.matrix_content[0][1] = (matrix_content[0][2] * matrix_content[2][1] - matrix_content[0][1] * matrix_content[2][2]) / det;
		Temp.matrix_content[0][2] = (matrix_content[0][1] * matrix_content[1][2] - matrix_content[0][2] * matrix_content[1][1]) / det;
		Temp.matrix_content[1][0] = (matrix_content[1][2] * matrix_content[2][0] - matrix_content[1][0] * matrix_content[2][2]) / det;
		Temp.matrix_content[1][1] = (matrix_content[0][0] * matrix_content[2][2] - matrix_content[0][2] * matrix_content[2][0]) / det;
		Temp.matrix_content[1][2] = (matrix_content[0][2] * matrix_content[1][0] - matrix_content[0][0] * matrix_content[1][2]) / det;
		Temp.matrix_content[2][0] = (matrix_content[1][0] * matrix_content[2][1] - matrix_content[1][1] * matrix_content[2][0]) / det;
		Temp.matrix_content[2][1] = (matrix_content[0][1] * matrix_content[2][0] - matrix_content[0][0] * matrix_content[2][1]) / det;
		Temp.matrix_content[2][2] = (matrix_content[0][0] * matrix_content[1][1] - matrix_content[0][1] * matrix_content[1][0]) / det;
		return Temp;
	}
	else {
		std::cout << "Invalid Inverse Matrix." << std::endl;
		return *this;
	}
}

MyMatrix MyMatrix::SubMatrix(int row_l, int row_u, int colum_l, int colum_u) {
	int row_new = row_u - row_l + 1;
	int colum_new = colum_u - colum_l + 1;
	MyMatrix Temp = MyMatrix(row_new, colum_new);
	//초기화
	for (int i = 0; i < row_new; i++) {
		for (int j = 0; j < colum_new; j++) {
			Temp.matrix_content[i][j] = matrix_content[row_l + i][colum_l + j];
		}
	}
	return Temp;
}


//할당 연산자 오버로딩.
MyMatrix& MyMatrix::operator=(const MyMatrix& matrix) {
	if (matrix.row_length > row_length || matrix.colum_length > colum_length) { //새로운 값이 더 용량이 크다면, 메모리 재할당. 그외에는 유지함.
		
		//할당한 메모리 삭제
		for (int i = 0; i < row_length; i++)
			delete[] matrix_content[i];
		delete[] matrix_content;
		//메모리 다시 할당
		matrix_content = new float* [matrix.row_length];
		for (int i = 0; i < matrix.row_length; i++) {
			matrix_content[i] = new float[matrix.colum_length];
		}
	}

	// 초기화
	for (int i = 0; i < matrix.row_length; i++) {
		for (int j = 0; j < matrix.colum_length; j++) {
			matrix_content[i][j] = matrix.matrix_content[i][j];
		}
	}
	row_length = matrix.row_length;
	colum_length = matrix.colum_length;
	return *this;
}

MyMatrix& MyMatrix::operator+=(const MyMatrix& matrix) {
	(*this) = (*this) + matrix;
	return *this;
}
MyMatrix& MyMatrix::operator-=(const MyMatrix& matrix) {
	(*this) = (*this) - matrix;
	return *this;
}
MyMatrix& MyMatrix::operator*=(const MyMatrix& matrix) {
	(*this) = matrix * (*this);
	return *this;
}

MyMatrix operator+(const MyMatrix& matrix1, const MyMatrix& matrix2) {
	MyMatrix temp = matrix1;
	if (matrix1.row_length == matrix2.row_length && matrix1.colum_length == matrix2.colum_length) {
		for (int i = 0; i < matrix1.row_length; i++) {
			for (int j = 0; j < matrix1.colum_length; j++)
				temp.matrix_content[i][j] = matrix1.matrix_content[i][j] + matrix2.matrix_content[i][j];
		}
	}
	else {
		std::cout << "Invalid Matrix Size, cannot opperate calculation" << std::endl;
	}
	return temp;
}
MyMatrix operator-(const MyMatrix& matrix1, const MyMatrix& matrix2) {
	MyMatrix temp = matrix1;
	if (matrix1.row_length == matrix2.row_length && matrix1.colum_length == matrix2.colum_length) {
		for (int i = 0; i < matrix1.row_length; i++) {
			for (int j = 0; j < matrix1.colum_length; j++)
				temp.matrix_content[i][j] = matrix1.matrix_content[i][j] - matrix2.matrix_content[i][j];
		}		
	}
	else {
		std::cout << "Invalid Matrix Size, cannot opperate calculation" << std::endl;
	}
	return temp;
}
MyMatrix operator*(const MyMatrix& matrix1, const MyMatrix& matrix2) {
	MyMatrix temp = MyMatrix(matrix1.row_length, matrix2.colum_length);
	if (matrix1.colum_length == matrix2.row_length) {
		for (int i = 0; i < matrix1.row_length; i++) {
			for (int j = 0; j < matrix2.colum_length; j++) {
				for (int k = 0; k < matrix1.colum_length; k++) {
					temp.matrix_content[i][j] += matrix1.matrix_content[i][k] * matrix2.matrix_content[k][j];
				}
			}
		}
	}
	else {
		std::cout << "Invalid Matrix Size, cannot opperate calculation" << std::endl;
	}
	return temp;
}

MyMatrix operator*(float n, const MyMatrix& matrix) {
	MyMatrix temp = matrix;
	for (int i = 0; i < matrix.row_length; i++) {
		for (int j = 0; j < matrix.colum_length; j++)
			temp.matrix_content[i][j] = n * matrix.matrix_content[i][j];
	}
	return temp;
}

MyMatrix operator*(const MyMatrix& matrix, float n) {
	MyMatrix temp = matrix;
	for (int i = 0; i < matrix.row_length; i++) {
		for (int j = 0; j < matrix.colum_length; j++)
			temp.matrix_content[i][j] = n * matrix.matrix_content[i][j];
	}
	return temp;
}

MyMatrix operator/(const MyMatrix& matrix, float n) {
	MyMatrix temp = matrix;
	for (int i = 0; i < matrix.row_length; i++) {
		for (int j = 0; j < matrix.colum_length; j++)
			temp.matrix_content[i][j] = matrix.matrix_content[i][j] / n;
	}
	return temp;
}
