#pragma once
//Dense Matrix로 구현됨. 훗날 sparse matrix로도 새로 구현할 필요 있음.
//앞으로 구성할 여러 클래스의 기반이 될 primitive class임.
class MyMatrix {
	//필드
	// //행렬을 이루는, 2차원 행렬. 원소의 타입은 float.
public:
	//행렬의 크기
	int row_length;
	int colum_length;
	float** matrix_content;

	//생성자
	// m X n 행렬, 동적 배열을 통한 임의의 행렬
	MyMatrix();
	MyMatrix(int m); // 단위행렬 생성
	MyMatrix(int m, int n); // 영행렬 생성
	MyMatrix(int n, float* input);
	MyMatrix(int m, int n, float** input);
	MyMatrix(int m, int n, float input[]);
	MyMatrix(float row1[2], float row2[2]);
	MyMatrix(float row1[3], float row2[3], float row3[3]);
	//어떻게 하면 2차원 배열을 입력으로 받을 수 있을까???

	//복사 생성자
	MyMatrix(const MyMatrix& matrix);

	// 소멸자
	~MyMatrix();

	//출력 메소드
	void ShowMatrix();
	//기타메소드
	void Clear(); // 행렬을 모두 0으로 초기화
	void Clear_One();  // 행렬을 모두 1로 초기화 

	//행렬 선 대칭, 전치
	MyMatrix TransPose();

	//역행렬 구하기
	// 행렬이 정방형인 경우에만 해당함, 크기가 2X2 또는 3X3인 경우. 이후에는 LU로 해결함.
	MyMatrix Inverse();
	// 자신의 일부를 원소로 하는 새로운 행렬
	MyMatrix SubMatrix(int row_l, int row_u, int colum_l, int colum_u);
	
	
	
	//연산자 오버라이드.
	// 자신(*this)을 리턴하는 연산자
	MyMatrix& operator=(const MyMatrix& matrix);
	MyMatrix& operator+=(const MyMatrix& matrix);
	MyMatrix& operator-=(const MyMatrix& matrix);
	MyMatrix& operator*=(const MyMatrix& matrix);
	// 행렬의 원소에 접근하는 연산자, [][]오버로딩
	
	// 클래스 외부의 함수가 클래스의 보호된 멤버에 접근할 수 있도록 friend 설정함.
	friend MyMatrix operator+(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator-(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator*(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator*(float n, const MyMatrix& matrix);
	friend MyMatrix operator*(const MyMatrix& matrix, float n);
	friend MyMatrix operator/(const MyMatrix& matrix, float n);
};

// 자신을 리턴하지 않는 연산자.
// 행렬간의 기본적인 연산자
MyMatrix operator+(const MyMatrix& matrix1, const MyMatrix& matrix2);
MyMatrix operator-(const MyMatrix& matrix1, const MyMatrix& matrix2);
//행렬의 행렬곲
MyMatrix operator*(const MyMatrix& matrix1, const MyMatrix& matrix2);
//행렬의 정수곲
MyMatrix operator*(float n, const MyMatrix& matrix);
MyMatrix operator/(const MyMatrix& matrix, float n);
