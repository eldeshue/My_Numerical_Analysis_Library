#pragma once
//Dense Matrix�� ������. �ʳ� sparse matrix�ε� ���� ������ �ʿ� ����.
//������ ������ ���� Ŭ������ ����� �� primitive class��.
class MyMatrix {
	//�ʵ�
	// //����� �̷��, 2���� ���. ������ Ÿ���� float.
public:
	//����� ũ��
	int row_length;
	int colum_length;
	float** matrix_content;

	//������
	// m X n ���, ���� �迭�� ���� ������ ���
	MyMatrix();
	MyMatrix(int m); // ������� ����
	MyMatrix(int m, int n); // ����� ����
	MyMatrix(int n, float* input);
	MyMatrix(int m, int n, float** input);
	MyMatrix(int m, int n, float input[]);
	MyMatrix(float row1[2], float row2[2]);
	MyMatrix(float row1[3], float row2[3], float row3[3]);
	//��� �ϸ� 2���� �迭�� �Է����� ���� �� ������???

	//���� ������
	MyMatrix(const MyMatrix& matrix);

	// �Ҹ���
	~MyMatrix();

	//��� �޼ҵ�
	void ShowMatrix();
	//��Ÿ�޼ҵ�
	void Clear(); // ����� ��� 0���� �ʱ�ȭ
	void Clear_One();  // ����� ��� 1�� �ʱ�ȭ 

	//��� �� ��Ī, ��ġ
	MyMatrix TransPose();

	//����� ���ϱ�
	// ����� �������� ��쿡�� �ش���, ũ�Ⱑ 2X2 �Ǵ� 3X3�� ���. ���Ŀ��� LU�� �ذ���.
	MyMatrix Inverse();
	// �ڽ��� �Ϻθ� ���ҷ� �ϴ� ���ο� ���
	MyMatrix SubMatrix(int row_l, int row_u, int colum_l, int colum_u);
	
	
	
	//������ �������̵�.
	// �ڽ�(*this)�� �����ϴ� ������
	MyMatrix& operator=(const MyMatrix& matrix);
	MyMatrix& operator+=(const MyMatrix& matrix);
	MyMatrix& operator-=(const MyMatrix& matrix);
	MyMatrix& operator*=(const MyMatrix& matrix);
	// ����� ���ҿ� �����ϴ� ������, [][]�����ε�
	
	// Ŭ���� �ܺ��� �Լ��� Ŭ������ ��ȣ�� ����� ������ �� �ֵ��� friend ������.
	friend MyMatrix operator+(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator-(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator*(const MyMatrix& matrix1, const MyMatrix& matrix2);
	friend MyMatrix operator*(float n, const MyMatrix& matrix);
	friend MyMatrix operator*(const MyMatrix& matrix, float n);
	friend MyMatrix operator/(const MyMatrix& matrix, float n);
};

// �ڽ��� �������� �ʴ� ������.
// ��İ��� �⺻���� ������
MyMatrix operator+(const MyMatrix& matrix1, const MyMatrix& matrix2);
MyMatrix operator-(const MyMatrix& matrix1, const MyMatrix& matrix2);
//����� ��ā�
MyMatrix operator*(const MyMatrix& matrix1, const MyMatrix& matrix2);
//����� ������
MyMatrix operator*(float n, const MyMatrix& matrix);
MyMatrix operator/(const MyMatrix& matrix, float n);
