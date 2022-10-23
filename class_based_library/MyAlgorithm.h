#pragma once
//수치해석 알고리즘을 구현함.
#include "MyMath.h" // 여러 방정식 및 수학적 함수들.
#include "MyPolinomial.h"
//InitialGuess
int InitialGuess(float l, float u, MyPolinomial target);
//Bisection
float Bisection(float l, float u, int MaxStep, float Tol, MyPolinomial target);

//Newton-Rapson
float Newton_Rapson(float initial, int MaxStep, float Tol, MyPolinomial target)