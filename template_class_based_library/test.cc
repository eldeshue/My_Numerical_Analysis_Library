/*
* Matlib = Matrix + Library
* ������ ��ġ�ؼ� ���̺귯���� MyMatlab������Ʈ�� template�� Ȱ���Ͽ� ������
*/

#include<iostream>
#include"Dense_Matrix.h"
#include"Linear_Solver.h"

int main() {
	// �ռ� �ۼ��� ������ ���̺귯���� ���Ͽ� �׽�Ʈ ���̽��� ������

	// test for Dense_Matrix library.
	//int data1[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	//int data2[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//int data3[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//Dense_Matrix<int, 3, 3> test1(data1);
	//Dense_Matrix<int, 3, 3> test2(data2);
	//Dense_Matrix<int, 3, 4> test3(data3); // ���ο� Ÿ���� ���ǰ� �Ұ����ϴ�???
	//
	//Dense_Matrix<int, 3, 4> test4 = test1 * test3;
	//Dense_Matrix<int, 3, 3> test5 = test1 * Dense_Matrix<int, 3, 3>(3);
	//Dense_Matrix<int, 3, 3> test6 = test1 + test2;
	//test4.show();
	//test5.show();
	//
	//test4.eye();
	//test4.show();

	// Thomas algorithm test 1
	//double data_A[3][3] = { {3,-1,0}, {-1,3,-1}, {0,-1,3} };
	//double data_B[3][1] = { -1, 7, 7 };
	
	// Thomas algorithm test 2
	//double data_A[3][3] = { {2.04,-1,0}, {-1,2.04,-1}, {0,-1,2.04} };
	//double data_B[3][1] = { 48.8, 0.8, 0.8 };	
	/*
	Dense_Matrix<double, 3, 3> A(data_A);
	Dense_Matrix<double, 3, 1> B(data_B);
	Dense_Matrix<double, 3, 1> test = Thomas_Algorithm(A, B);

	test.show();
	*/

	// Thomas algorithm test 3
	double data_A[7][7] = {
		{-2.25, 1, 0, 0, 0, 0, 0},
		{1, -2.25, 1, 0, 0, 0, 0},
		{0, 1, -2.25, 1, 0, 0, 0},
		{0, 0, 1, -2.25, 1, 0, 0},
		{0, 0, 0, 1, -2.25, 1, 0},
		{0, 0, 0, 0, 1, -2.25, 1},
		{0, 0, 0, 0, 0,  1, -2.25}
	};
	double data_B[7][1] = {0, 0, 0, 0, 0, 0, 100};
	Dense_Matrix<double, 7, 7> A(data_A);
	Dense_Matrix<double, 7, 1> B(data_B);
	Dense_Matrix<double, 7, 1> test = Thomas_Algorithm(A, B);

	test.show();
	//*/

}