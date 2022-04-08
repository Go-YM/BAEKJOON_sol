#include <iostream>
#include <cstring>
//<iostream>�� <cstring>�� ���������� �ҽ��� Ȯ���ϵ��� ����

using namespace std;
//std �̸� ���� ��� ����

//Subject ����ü
struct Subject {
	char SubName[30];	//���� �̸�
	int Hakjum;			//���� ����
	char Grade[10];		//���� ���
	float GPA;			//���� ����
};

//Student ����ü
struct Student {
	char StdName[30] = "";	//�л� �̸�
	int Hakbun = 0;			//�й�
	Subject* Sub;		//����
	int SubNum;			//�����
	float AveGPA;		//������ ��� ����
};

//���� Grade���� float ������ ��ȯ�����ִ� �Լ�
float ChangeGrade(char a[])
{
	if (strcmp(a, "A+") == 0)	//������ A+�϶�
	{
		return 4.5;
	}

	else if ((strcmp(a, "A0") == 0) || (strcmp(a, "A") == 0))	//������ A�϶�
	{
		return 4.0;
	}

	else if (strcmp(a, "B+") == 0)	//������ B+�϶�
	{
		return 3.5;
	}

	else if ((strcmp(a, "B0") == 0) || (strcmp(a, "B") == 0))	//������ B�϶�
	{
		return 3.0;
	}

	else if (strcmp(a, "C+") == 0)	//������ C+�϶�
	{
		return 2.5;
	}

	else if ((strcmp(a, "C0") == 0) || (strcmp(a, "C") == 0))	//������ C�϶�
	{
		return 2.0;
	}

	else if (strcmp(a, "D+") == 0)	//������ D+�϶�
	{
		return 1.5;
	}

	else if ((strcmp(a, "D0") == 0) || (strcmp(a, "D") == 0))	//������ D�϶�
	{
		return 1.0;
	}

	else if (strcmp(a, "F") == 0)	//������ F�϶�
	{
		return 0.0;
	}

	else	//������ �߸� �Է��Ѱ��
	{
		cout << "����� ��Ȯ�� �Է����ּ���.\n";
		return 0;
	}
}

//�޴���� �Լ� inline�� ����
inline void PrintMenu()
{
	cout << "\n================�޴�================\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";
}

//�������� ���� ��� �Լ�
void CalcGPA(Subject& Sub)
{
	float FloatGrade = ChangeGrade(Sub.Grade);	//������ Grade�� �Ǽ��� ��ȯ�ؼ� FloatGrade�� �ʱ�ȭ
	Sub.GPA = Sub.Hakjum * FloatGrade;			//GPA�� ���� �ʱ�ȭ
}

//���� �л��� ��� ���� ��� �Լ�
float CalcAveGPA(Subject* Sub, int num)
{
	float SumGPA = 0;							//SumGPA ����
	for (int i = 0; i < num; i++)
	{
		SumGPA += Sub[i].GPA;					//GPA�� ���� SumGPA�� �ʱ�ȭ
	}

	return SumGPA / num;						//AveGPA�� ��ȯ
}

//��ü �л� �Ż�/���� ���� ��� �Լ�
void PrintAllData(const Student* pSt, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\n";
		cout.width(30);
		cout << "��ü �л� ���� ����\n";
		cout << "====================================================================================================================\n";

		cout << "�̸� : " << pSt[i].StdName << "  �й� : " << pSt[i].Hakbun;
		cout << "\n====================================================================================================================\n";
		cout.width(50);
		cout << " �����  ���� ����  ������  ��������\n";
		cout << "====================================================================================================================\n";

		for (int j = 0; j < pSt[i].SubNum; j++)
		{
			cout.width(15);
			cout << pSt[i].Sub[j].SubName;
			cout.width(10);
			cout << pSt[i].Sub[j].Hakjum;
			cout.width(11);
			cout << pSt[i].Sub[j].Grade;
			cout.width(11);
			cout << pSt[i].Sub[j].GPA;
			cout << "\n";
		}

		cout << "====================================================================================================================\n";
		cout.width(50);
		cout << "�������";
		cout.width(10);
		cout.precision(2);	//�Ҽ��� 2�ڸ����� ��� ����
		cout << pSt[i].AveGPA;
		cout << "\n\n";
	}
}

//���� �л� �Ż�/���� ���� ��� �Լ�
void PrintOneData(const Student& rSt)
{
	cout << "�̸� : " << rSt.StdName << "  �й� : " << rSt.Hakbun;
	cout << "\n====================================================================================================================\n";
	cout.width(50);
	cout << " �����  ���� ����  ������  ��������\n";
	cout << "====================================================================================================================\n";

	for (int i = 0; i < rSt.SubNum; i++)
	{
		cout.width(15);
		cout << rSt.Sub[i].SubName;
		cout.width(10);
		cout << rSt.Sub[i].Hakjum;
		cout.width(11);
		cout << rSt.Sub[i].Grade;
		cout.width(11);
		cout << rSt.Sub[i].GPA;
		cout << "\n";
	}
}

//�л� �̸� �˻� �� �ش� �л� ���� �ִ� �� �ּ� ���� �Լ�
Student* StdSearch(Student* pSt, int StudentNum)
{
	char SearchName[10];	//�˻��� �̸� �޴� SearchName[10] ����

	cout << "�˻� �� �л� �̸� : ";
	cin >> SearchName;

	for (int i = 0; i < StudentNum; i++)
	{		//SearchName[10]�� std[0~StudentNum ]�߿� ������
		if (strcmp(SearchName, pSt[i].StdName) == 0)
		{
			return pSt + i;
		}
	}

	//SearchName[10]�� std[0~StudentNum] �߿� ������
	return 0;	//0 ��ȯ

}

//inline �ߺ��Լ� InputValue �Լ��� ���� �޾���
inline void InputValue(char* str)
{
	cin >> str;
}

inline void InputValue(int& i)
{
	cin >> i;
}

//����ڷκ��� �л� ������ �Է¹޴� �Լ�
void InputData(Student* pSt, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\n* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[i].StdName);
		cout << "�й� : ";
		InputValue(pSt[i].Hakbun);

		cout << "\n������ ������ ���� �Է��ϼ���.\n";
		cout << "����� : ";
		InputValue(pSt[i].SubNum);
		pSt[i].Sub = new Subject[pSt[i].SubNum];	//����ڷκ��� �Է¹��� ������ �� ��ŭ new�� �Ҵ�

		cout << "\n\n* ������ ����" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (int j = 0; j < pSt[i].SubNum; j++)
		{
			cout << "������� : ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "���������� : ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "������(A+ ~ F) : ";
			InputValue(pSt[i].Sub[j].Grade);
			cout << "\n";
			CalcGPA(pSt[i].Sub[j]);
		}

		pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);
	}
}

//��� �л� ������ ����ϴ� �Լ�
void PrintAllStdList(Student* pSt, int StudentNum)
{
	cout << "\n=================================================================================\n";
	cout << "\t\t�̸�\t\t\t�й�\n";
	cout << "=================================================================================\n";
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\t\t" << pSt[i].StdName << "\t\t\t" << pSt[i].Hakbun<<"\n";
	}
	cout << "=================================================================================\n";
}

//�л� �˻� �� �л��� �̸� �Ǵ� �й��� �����ϴ� �Լ�
void ModifyStdInfo(Student* pSt,int StudentNum)
{
	Student* tempModify = StdSearch(pSt, StudentNum);
	cout << "* <" << tempModify->StdName << ", " << tempModify->Hakbun << "> �� ������ �����ϼ���.\n";
	cout << "�̸� : ";
	InputValue(tempModify->StdName);
	cout << "�й� : ";
	InputValue(tempModify->Hakbun);
}

int main(void)
{
	int count = 0;	//1�� �Է� ���� 2��, 3�� ������ ���� ���� ������ ���� ����
	int StudentNum;	//�л����� �޴� ���� ����

	int num;

	while (true)
	{
		cout << "�л����� �Է��ϼ��� : ";
		cin >> StudentNum;

		if (StudentNum <= 0)	//�л����� 0���Ϸ� ������ �ٽ� ����
		{
			continue;
		}

		break;
	}

	Student* stu = new Student[StudentNum];	//����ڷ� ���� ���� StudentNum����ŭ new�� �Ҵ�

	while (true)	//4 �Է����� ������ �ʴ� �ݺ���
	{
		PrintMenu();
		cout << "���ϴ� ����� �Է��ϼ��� : ";
		cin >> num;
		cout << "\n";

		if (num == 1)	//�л� ���� �Է�
		{
			InputData(stu, StudentNum);
			count++;
		}

		else if (num == 2)	//��ü �л� ��������
		{
			if (count == 0)
			{
				cout << "�л� ������ ���� �Է����ּ���!\n";
				continue;
			}

			PrintAllData(stu, StudentNum);
		}

		else if (num == 3)	//�л� �̸� �˻�
		{
			if (count == 0)
			{
				cout << "�л� ������ ���� �Է����ּ���!\n";
				continue;
			}

			Student* tempSearch = StdSearch(stu, StudentNum);	//����ü �迭 temp�� ��ġ�� �� ��� ����

			if (tempSearch != 0)	//�˻� �л��� ������
			{
				PrintOneData(*tempSearch);
			}

			else	//�˻� �л��� ������
			{
				cout << "\n�̸��� ����� Ȯ���� �ּ���.\n";
			}
		}

		else if (num == 4)	//��ü �л� ��� ����
		{
			if (count == 0)
			{
				cout << "�л� ������ ���� �Է����ּ���!\n";
				continue;
			}

			PrintAllStdList(stu, StudentNum);
		}

		else if (num == 5)
		{
			if (count == 0)
			{
				cout << "�л� ������ ���� �Է����ּ���!\n";
				continue;
			}

			ModifyStdInfo(stu,StudentNum);
		}


		else if (num == 6)	//���α׷� ����
		{
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}

		else	//�޴��� ���� ���ڸ� �Է����� ��
		{
			cout << "�ٽ� �Է� ���ּ���\n";
			continue;
		}
	}

	//new�� �Ҵ������ ����ü �迭 delete
	for (int i = 0; i < StudentNum; i++)
	{
		delete[]stu[i].Sub;
	}

	delete[]stu;

	return 0;	//0 ��ȯ
}