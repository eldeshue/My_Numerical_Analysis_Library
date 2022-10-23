// 동역학의 회전변환을 구현한다.
// 기존의 MyMatrix를 상속한다.
#include<iostream>
#include<string>
#include "Rotation_Matrix.h"
#include <cmath>  // 삼각함수는 radian scale

// 삼각함수 사용을 위한 전역변수 pi
const float pi = 3.14159265358979;

Rotation_Matrix::Rotation_Matrix(std::string AngleType, char RotateType[3], float angle[3]) : MyMatrix(3, 3) {
	MyMatrix element[3]; // 배열의 원소는 단위 회전 변환 행렬
	if (AngleType == "Fixed") { // 고정각, 순서 그대로 회전(행렬 곱)

	}
	else if (AngleType == "Euler") { // 오일러각, 회전 순서 변경
		char temp = RotateType[0];
		RotateType[0] = RotateType[2];
		RotateType[2] = temp;
	}
	else { // 잘못된 입력인 경우, 생성 취소
		std::cout << "Invalid AngleType" << std::endl;
		for (int i = 0; i < row_length; i++)
			delete matrix_content[i];
		delete[] matrix_content;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (RotateType[i] == 'X') {
			MyMatrix temp = MyMatrix(3, 3, Rotate_X(angle[i]));
			//MyMatrix temp
			element[i] = temp;
		}
		else if (RotateType[i] == 'Y') {
			MyMatrix temp = MyMatrix(3, 3, Rotate_Y(angle[i]));
			element[i] = temp;
		}
		else if (RotateType[i] == 'Z') {
			MyMatrix temp = MyMatrix(3, 3, Rotate_Z(angle[i]));
			element[i] = temp;
		}
		else {
			std::cout << "Invalid RotateType" << std::endl;
			for (int i = 0; i < row_length; i++)
				delete matrix_content[i];
			delete[] matrix_content;
			return;
		}
	}
	element[0] = element[2] * element[1] * element[0];
	// 필드의 초기화
	MyAngleType = AngleType;
	for (int i = 0; i < 3; i++){
		MyRotateType[i] = RotateType[i];
		MyAngle[i] = angle[i];
	    for (int j = 0; j < 3; j++){
		    matrix_content[i][j] = element[0].matrix_content[i][j];
		}
	}
}

Rotation_Matrix::Rotation_Matrix(const Rotation_Matrix& input) : MyMatrix(input) {
	MyAngleType = input.MyAngleType;
	for (int i = 0; i < 3; i++) {
		MyRotateType[i] = input.MyRotateType[i];
		MyAngle[i] = input.MyAngle[i];
	}
}

Rotation_Matrix::~Rotation_Matrix() {
	// 부모 클래스의 소멸자가 이미 호출됨, 중복으로 작성할 필요 없음.
}

MyMatrix Rotation_Matrix::Inverse() {
	MyMatrix Temp = MyMatrix(this->colum_length, this->row_length);
	for (int i = 0; i < row_length; i++) {
		for (int j = 0; j < colum_length; j++) {
			Temp.matrix_content[i][j] = this->matrix_content[j][i];
		}
	}
	return Temp;
}

// 임시로 구해둔 함수, 이후 모두 생성자 내부로 전환할것.
float* Rotate_X(float angle) {
	float input[9] = { 
	1,                     0,                      0,
	0, cos(angle * pi / 180), -sin(angle * pi / 180),
	0, sin(angle * pi / 180),  cos(angle * pi / 180)
	};
	return input;
}
float* Rotate_Y(float angle) {
	float input[9] = {
	 cos(angle * pi / 180), 0,  sin(angle * pi / 180),
	                     0, 1,                      0,
	-sin(angle * pi / 180), 0,  cos(angle * pi / 180)
	};
	return input;
}
float* Rotate_Z(float angle) {
	float input[9] = {
	cos(angle * pi / 180), -sin(angle * pi / 180), 0,
	sin(angle * pi / 180),  cos(angle * pi / 180), 0,
	0,                     0,                      1
	};
	return input;
}