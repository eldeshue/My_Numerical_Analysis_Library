#pragma once
// 동역학의 회전변환을 구현한다.
// 기존의 MyMatrix를 상속한다.
// 기초가 되는 단축 회전 행렬을 3종 구현함.
// 삼각함수 라이브러리 필요.
#include "MyMatrix.h"
#include <string>

class Rotation_Matrix : public MyMatrix {
	//필드
	std::string MyAngleType;
	char MyRotateType[3];
	float MyAngle[3];
public:
	//메소드 
	//생성자
	Rotation_Matrix(std::string AngleType, char RotateType[3], float angle[3]);
	//복사생성자
	Rotation_Matrix(const Rotation_Matrix& input);
	//소멸자
	~Rotation_Matrix();
	//역행렬 오버라이딩
	MyMatrix Inverse();
};

float* Rotate_X(float angle); //x축 회전 
float* Rotate_Y(float angle); //y축 회전
float* Rotate_Z(float angle); //z축 회전