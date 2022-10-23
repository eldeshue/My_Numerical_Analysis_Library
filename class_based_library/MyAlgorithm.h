#pragma once
//��ġ�ؼ� �˰����� ������.
#include "MyMath.h" // ���� ������ �� ������ �Լ���.
#include "MyPolinomial.h"
//InitialGuess
int InitialGuess(float l, float u, MyPolinomial target);
//Bisection
float Bisection(float l, float u, int MaxStep, float Tol, MyPolinomial target);

//Newton-Rapson
float Newton_Rapson(float initial, int MaxStep, float Tol, MyPolinomial target)