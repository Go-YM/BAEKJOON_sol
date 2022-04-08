#include <iostream>
#include <cstring>
//<iostream>과 <cstring>을 컴파일 전에 소스에 확장하도록 지시

using namespace std;
//표준이름공간 사용 지시

//정수를 받아 최소값을 출력하는 GetMin
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

//실수를 받아 최소값을 출력하는 GetMin
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

//문자열을 받아 최소값을 출력하는 GetMin
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

//배열을 받아 최소값을 출력하는 GetMin
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

//프로그램의 메인함수
int main(void)
{
	int intX, intY;
	double doubleX, doubleY;
	char charX[100], charY[100];
	int arr[10];

	//사용자로부터 정수를 입력받아 최소값 출력
	cout << "두 개의 정수를 입력하세요 : ";
	cin >> intX >> intY;
	cout << "최소값은 " << GetMin(intX, intY) << "입니다.\n";

	//사용자로부터 실수를 입력받아 최소값 출력
	cout << "두 개의 실수를 입력하세요 : ";
	cin >> doubleX >> doubleY;
	cout << "최소값은 " << GetMin(doubleX, doubleY) << "입니다.\n";

	//사용자로부터 문자열 입력받아 최소값 출력
	cout << "두 개의 문자열을 입력하세요 : ";
	cin >> charX >> charY;
	cout << "최소값은 " << GetMin(charX, charY) << "입니다.\n";

	//사용자로부터 배열을 입력받아 최소값 출력
	cout << "배열의 원소(10개 입력) : ";
	for (int j = 0; j < 10; j++)
	{
		cin >> arr[j];
	}
	cout << "최소값은 " << GetMin(arr, 10) << "입니다.\n";

	return 0;	//0 반환
}