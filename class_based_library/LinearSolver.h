#pragma once
#include"MyMatrix.h"

float** LU_Decompose_Algorithm(float** A, int row_length, int colum_length);
MyMatrix LU_Decompose_Algorithm(MyMatrix& A);
float* Gauss_Elimination_Solve(MyMatrix& A, float* b);
MyMatrix LU_Solve(MyMatrix& A, float* b);
float** Cholesky_Decompose_Algorithm(float** A, int size);
MyMatrix Cholesky_Solve(MyMatrix& A, float* b);
MyMatrix Inverse_Matrix(const MyMatrix& A);
//int LUPDecompose(double** A, int N, double Tol, int* P);