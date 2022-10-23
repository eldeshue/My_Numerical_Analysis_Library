// �������� ȸ����ȯ�� �����Ѵ�.
// ������ MyMatrix�� ����Ѵ�.
#include<iostream>
#include<string>
#include "Rotation_Matrix.h"
#include <cmath>  // �ﰢ�Լ��� radian scale

// �ﰢ�Լ� ����� ���� �������� pi
const float pi = 3.14159265358979;

Rotation_Matrix::Rotation_Matrix(std::string AngleType, char RotateType[3], float angle[3]) : MyMatrix(3, 3) {
	MyMatrix element[3]; // �迭�� ���Ҵ� ���� ȸ�� ��ȯ ���
	if (AngleType == "Fixed") { // ������, ���� �״�� ȸ��(��� ��)

	}
	else if (AngleType == "Euler") { // ���Ϸ���, ȸ�� ���� ����
		char temp = RotateType[0];
		RotateType[0] = RotateType[2];
		RotateType[2] = temp;
	}
	else { // �߸��� �Է��� ���, ���� ���
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
	// �ʵ��� �ʱ�ȭ
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
	// �θ� Ŭ������ �Ҹ��ڰ� �̹� ȣ���, �ߺ����� �ۼ��� �ʿ� ����.
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

// �ӽ÷� ���ص� �Լ�, ���� ��� ������ ���η� ��ȯ�Ұ�.
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