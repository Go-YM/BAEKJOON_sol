#include <iostream>
#include <cstring>
//<iostream>�� <cstring>�� ������ ���� �ҽ��� Ȯ���ϵ��� ����

using namespace std;
//ǥ���̸����� ��� ����

//������ �޾� �ּҰ��� ����ϴ� GetMin
int GetMin(int a, int b)
{
	if (a > b)
	{
		return b;
	}

	else
	{
		return a;
	}
}

//�Ǽ��� �޾� �ּҰ��� ����ϴ� GetMin
double GetMin(double a, double b)
{
	if (a > b)
	{
		return b;
	}

	else
	{
		return a;
	}
}

//���ڿ��� �޾� �ּҰ��� ����ϴ� GetMin
char* GetMin(char* a, char* b)
{
	if (strcmp(a, b) > 0)
	{
		return b;
	}

	else
	{
		return a;
	}
}

//�迭�� �޾� �ּҰ��� ����ϴ� GetMin
int GetMin(int a[], int size)
{
	int Min = a[0];

	for (int i = 1; i < size; i++)
	{
		if (Min > a[i])
		{
			Min = a[i];
		}
	}

	return Min;
}

//���α׷��� �����Լ�
int main(void)
{
	int intX, intY;
	double doubleX, doubleY;
	char charX[100], charY[100];
	int arr[10];

	//����ڷκ��� ������ �Է¹޾� �ּҰ� ���
	cout << "�� ���� ������ �Է��ϼ��� : ";
	cin >> intX >> intY;
	cout << "�ּҰ��� " << GetMin(intX, intY) << "�Դϴ�.\n";

	//����ڷκ��� �Ǽ��� �Է¹޾� �ּҰ� ���
	cout << "�� ���� �Ǽ��� �Է��ϼ��� : ";
	cin >> doubleX >> doubleY;
	cout << "�ּҰ��� " << GetMin(doubleX, doubleY) << "�Դϴ�.\n";

	//����ڷκ��� ���ڿ� �Է¹޾� �ּҰ� ���
	cout << "�� ���� ���ڿ��� �Է��ϼ��� : ";
	cin >> charX >> charY;
	cout << "�ּҰ��� " << GetMin(charX, charY) << "�Դϴ�.\n";

	//����ڷκ��� �迭�� �Է¹޾� �ּҰ� ���
	cout << "�迭�� ����(10�� �Է�) : ";
	for (int j = 0; j < 10; j++)
	{
		cin >> arr[j];
	}
	cout << "�ּҰ��� " << GetMin(arr, 10) << "�Դϴ�.\n";

	return 0;	//0 ��ȯ
}