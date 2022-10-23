// 기계공학 수치해석 공부를 위한 프로젝트.
// 작성자 곽도훈, 2016100678.
#include <iostream>
#include <string>
#include <cmath>

#include "MyMatrix.h"
#include "MyMath.h"
//#include "MyComplexNumber.h"
#include "Rotation_Matrix.h"
#include "MyPolinomial.h"
#include "LinearSolver.h"
#include "Integrator.h"
#include "Derivative-Integral.h"


// 테스트용 ODE 함수
double test_func(double x, double y);
double test_func1(double x);

// 여기서는 설계한 행렬 클래스에 대한 테스트를 진행한다.
int main()
{
    /*
    //  오일러 각 회전 변환 행렬 test
    std::string Angletype = "Fixed";
    char RotateType[3] = { 'X', 'Y', 'Z' };
    float Angle[3] = { 30,30,30 };
    Rotation_Matrix test = Rotation_Matrix(Angletype, RotateType, Angle);
    test.ShowMatrix();
    test.Inverse().ShowMatrix();
    */
    /*
    // 다항식 test
    float row1[3] = { 3, 8, 10 };
    float row2[3] = { 0, 7, 8 };
    float row3[3] = { 2, 0, 10 };
    float* test_input[3] = {row1, row2, row3};
    float C[3] = { 10, 8, 9 };
    MyPolinomial test = MyPolinomial(3, 3, test_input);
    test.ShowMatrix();
    test.Calculate(0).ShowMatrix();
    test.Differentiate().ShowMatrix();
    test.Integrate(C).ShowMatrix();
    */

    // 가우스 소거법 리니어 솔버

    /*
    // LU
    float row1[3] = { 3, -0.1, -0.2 };
    float row2[3] = { 0.1, 7, -0.3 };
    float row3[3] = { 0.3, -0.2, 10 };
    float b[3] = { 7.85, -19.3, 71.4};
    */
    /* //cholesky example
    float row1[4] = { 9, 0, -27, 18 };
    float row2[4] = { 0, 9, -9, -27 };
    float row3[4] = { -27, -9, 99, -27 };
    float row4[4] = { 18, -27, -27, 121 };
    float b[4] = { -9, 5, 7, 11}; 
   
    float row1[4] = { 1, -1, -1, -1 };
    float row2[4] = {-1, 2, 2, 2 };
    float row3[4] = { -1, 2, 3, 1 };
    float row4[4] = { -1, 2, 1, 4 };
    float b[4] = { -1, 1, 6, -7};
   
   */

    /*
    // Cholesky
    float row1[4] = { 1, -1, -1, -1 };
    float row2[4] = {-1, 2, 2, 2 };
    float row3[4] = { -1, 2, 3, 1 };
    float row4[4] = { -1, 2, 1, 4 };
    float b[4] = { -1, 1, 6, -7};

    float* input1[4] = {row1, row2, row3, row4};
    MyMatrix test0 = MyMatrix(4, 4, input1);
    test0.ShowMatrix();
    MyMatrix mini = test0.SubMatrix(1, 2, 1, 2);
    mini.ShowMatrix();
    //test.~MyMatrix();
    //float** test = LU_Decompose_Algorithm(input1, 4, 4);
    */
    
    /*
    float** test = Cholesky_Decompose_Algorithm(input1, 4);
    
    // 계산 결과
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << test[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    
    */

    //float* X = Gauss_Elimination_Solve(test, b);
    //float* X = LU_Solve(test0, b);
    //float* X = Cholesky_Solve(test, b);
    /*
    for (int i = 0; i < 4; i++) {
        std::cout << X[i] << "  ";
    }
    std::cout << std::endl;
    */

    /*
    double result = RK4(test_func, 0, 1, 0.5, 1);
    std::cout << "계산결과는 = " << result << std::endl;
    */

    const double pi = 3.1415926535;

    double result = trapezoidal(test_func1, 0, pi/2, 16);
    std::cout << "계산결과는 = " << result << std::endl;

}


double test_func(double x, double y) {
    return 0 - 2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

double test_func1(double x) {
    return exp(x) * sin(x);
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
