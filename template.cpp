#include <iostream>
//<iostream>�� ������ ���� �ҽ��� Ȯ���ϵ��� ����

using namespace std;
//ǥ���̸����� std�� ����ϵ��� ����

//a�� b�� Swap �ϴ� template �Լ� ����
template <class T> void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//arr�� �����ϴ� template �Լ� ����
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

	//�޴� ���
	cout << "1. ��������\n";
	cout << "2. �Ǽ�����\n";
	cout << "3. ����\n";

	while (1)	//���� ������
	{	//����ڷ� ���� num�� �Է¹���
		cout << "�޴����� : ";
		cin >> num;
		if (num == 1)	//num�� 1�϶�
		{
			//����ڷκ��� 5���� ������ �Է¹���
			cout << "5���� ������ �Է��ϼ��� : ";
			for (int i = 0; i < 5; i++)
			{
				cin >> arrInt[i];
			}

			Sort(arrInt);	//arrInt ����

			//������ arrInt ���
			for (int i = 0; i < 5; i++)
			{
				cout << arrInt[i] << "  ";
			}
			cout << "\n";
		}

		else if (num == 2)	//num�� 2�϶�
		{
			//����ڷκ��� 5���� �Ǽ��� �Է¹���
			cout << "5���� �Ǽ��� �Է��ϼ��� : ";
			for (int i = 0; i < 5; i++)
			{
				cin >> arrDouble[i];
			}

			Sort(arrDouble);	//arrDouble ����

			//������ arrDouble ���
			for (int i = 0; i < 5; i++)
			{
				cout << arrDouble[i] << "  ";
			}
			cout << "\n";
		}

		else if (num == 3)	//num�� 3�϶�
		{
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	}

	return 0;
}