#pragma once
// �������� ȸ����ȯ�� �����Ѵ�.
// ������ MyMatrix�� ����Ѵ�.
// ���ʰ� �Ǵ� ���� ȸ�� ����� 3�� ������.
// �ﰢ�Լ� ���̺귯�� �ʿ�.
#include "MyMatrix.h"
#include <string>

class Rotation_Matrix : public MyMatrix {
	//�ʵ�
	std::string MyAngleType;
	char MyRotateType[3];
	float MyAngle[3];
public:
	//�޼ҵ� 
	//������
	Rotation_Matrix(std::string AngleType, char RotateType[3], float angle[3]);
	//���������
	Rotation_Matrix(const Rotation_Matrix& input);
	//�Ҹ���
	~Rotation_Matrix();
	//����� �������̵�
	MyMatrix Inverse();
};

float* Rotate_X(float angle); //x�� ȸ�� 
float* Rotate_Y(float angle); //y�� ȸ��
float* Rotate_Z(float angle); //z�� ȸ��