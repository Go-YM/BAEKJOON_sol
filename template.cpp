#include <iostream>
//<iostream>을 컴파일 전에 소스에 확장하도록 지시

using namespace std;
//표준이름공간 std를 사용하도록 지시

//a와 b를 Swap 하는 template 함수 생성
template <class T> void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//arr을 정렬하는 template 함수 생성
template <class T>  T Sort(T arr)
{
	for (int x = 0; x < 5; x++)
	{
		int Min = x;

		for (int y = x + 1; y < 5; y++)
		{
			if (arr[y] < arr[Min])
			{
				Min = y;
			}
		}

		Swap(arr[Min], arr[x]);
	}

	return arr;
}

int main(void)
{
	int num;
	int arrInt[5];
	double arrDouble[5];

	//메뉴 출력
	cout << "1. 정수정렬\n";
	cout << "2. 실수정렬\n";
	cout << "3. 종료\n";

	while (1)	//무한 루프문
	{	//사용자로 부터 num을 입력받음
		cout << "메뉴선택 : ";
		cin >> num;
		if (num == 1)	//num이 1일때
		{
			//사용자로부터 5개의 정수를 입력받음
			cout << "5개의 정수를 입력하세요 : ";
			for (int i = 0; i < 5; i++)
			{
				cin >> arrInt[i];
			}

			Sort(arrInt);	//arrInt 정렬

			//정렬한 arrInt 출력
			for (int i = 0; i < 5; i++)
			{
				cout << arrInt[i] << "  ";
			}
			cout << "\n";
		}

		else if (num == 2)	//num이 2일때
		{
			//사용자로부터 5개의 실수를 입력받음
			cout << "5개의 실수를 입력하세요 : ";
			for (int i = 0; i < 5; i++)
			{
				cin >> arrDouble[i];
			}

			Sort(arrDouble);	//arrDouble 정렬

			//정렬한 arrDouble 출력
			for (int i = 0; i < 5; i++)
			{
				cout << arrDouble[i] << "  ";
			}
			cout << "\n";
		}

		else if (num == 3)	//num이 3일때
		{
			cout << "프로그램을 종료합니다.\n";
			break;
		}
	}

	return 0;
}