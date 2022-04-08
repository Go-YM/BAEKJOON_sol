#include <iostream>
#include <cstring>
//<iostream>과 <cstring>을 컴파일전에 소스에 확장하도록 지시

using namespace std;
//std 이름 공간 사용 지시

//Subject 구조체
struct Subject {
	char SubName[30];	//과목 이름
	int Hakjum;			//과목 학점
	char Grade[10];		//과목 등급
	float GPA;			//과목 평점
};

//Student 구조체
struct Student {
	char StdName[30] = "";	//학생 이름
	int Hakbun = 0;			//학번
	Subject* Sub;		//과목
	int SubNum;			//과목수
	float AveGPA;		//교과목 평균 평점
};

//받은 Grade값을 float 형으로 변환시켜주는 함수
float ChangeGrade(char a[])
{
	if (strcmp(a, "A+") == 0)	//성적이 A+일때
	{
		return 4.5;
	}

	else if ((strcmp(a, "A0") == 0) || (strcmp(a, "A") == 0))	//성적이 A일때
	{
		return 4.0;
	}

	else if (strcmp(a, "B+") == 0)	//성적이 B+일때
	{
		return 3.5;
	}

	else if ((strcmp(a, "B0") == 0) || (strcmp(a, "B") == 0))	//성적이 B일때
	{
		return 3.0;
	}

	else if (strcmp(a, "C+") == 0)	//성적이 C+일때
	{
		return 2.5;
	}

	else if ((strcmp(a, "C0") == 0) || (strcmp(a, "C") == 0))	//성적이 C일때
	{
		return 2.0;
	}

	else if (strcmp(a, "D+") == 0)	//성적이 D+일때
	{
		return 1.5;
	}

	else if ((strcmp(a, "D0") == 0) || (strcmp(a, "D") == 0))	//성적이 D일때
	{
		return 1.0;
	}

	else if (strcmp(a, "F") == 0)	//성적이 F일때
	{
		return 0.0;
	}

	else	//성적을 잘못 입력한경우
	{
		cout << "등급을 정확히 입력해주세요.\n";
		return 0;
	}
}

//메뉴출력 함수 inline읋 선언
inline void PrintMenu()
{
	cout << "\n================메뉴================\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
}

//교과목의 평점 계산 함수
void CalcGPA(Subject& Sub)
{
	float FloatGrade = ChangeGrade(Sub.Grade);	//문자형 Grade를 실수로 변환해서 FloatGrade에 초기화
	Sub.GPA = Sub.Hakjum * FloatGrade;			//GPA에 평점 초기화
}

//개인 학생의 평균 평점 계산 함수
float CalcAveGPA(Subject* Sub, int num)
{
	float SumGPA = 0;							//SumGPA 선언
	for (int i = 0; i < num; i++)
	{
		SumGPA += Sub[i].GPA;					//GPA의 합을 SumGPA에 초기화
	}

	return SumGPA / num;						//AveGPA값 반환
}

//전체 학생 신상/성적 정보 출력 함수
void PrintAllData(const Student* pSt, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\n";
		cout.width(30);
		cout << "전체 학생 성적 보기\n";
		cout << "====================================================================================================================\n";

		cout << "이름 : " << pSt[i].StdName << "  학번 : " << pSt[i].Hakbun;
		cout << "\n====================================================================================================================\n";
		cout.width(50);
		cout << " 과목명  과목 학점  과목등급  과목평점\n";
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
		cout << "평균평점";
		cout.width(10);
		cout.precision(2);	//소수점 2자리까지 출력 지시
		cout << pSt[i].AveGPA;
		cout << "\n\n";
	}
}

//개인 학생 신상/성적 정보 출력 함수
void PrintOneData(const Student& rSt)
{
	cout << "이름 : " << rSt.StdName << "  학번 : " << rSt.Hakbun;
	cout << "\n====================================================================================================================\n";
	cout.width(50);
	cout << " 과목명  과목 학점  과목등급  과목평점\n";
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

//학생 이름 검색 후 해당 학생 정보 있는 곳 주소 리턴 함수
Student* StdSearch(Student* pSt, int StudentNum)
{
	char SearchName[10];	//검색할 이름 받는 SearchName[10] 선언

	cout << "검색 할 학생 이름 : ";
	cin >> SearchName;

	for (int i = 0; i < StudentNum; i++)
	{		//SearchName[10]이 std[0~StudentNum ]중에 있을때
		if (strcmp(SearchName, pSt[i].StdName) == 0)
		{
			return pSt + i;
		}
	}

	//SearchName[10]이 std[0~StudentNum] 중에 없을때
	return 0;	//0 반환

}

//inline 중복함수 InputValue 함수로 값을 받아줌
inline void InputValue(char* str)
{
	cin >> str;
}

inline void InputValue(int& i)
{
	cin >> i;
}

//사용자로부터 학생 정보를 입력받는 함수
void InputData(Student* pSt, int StudentNum)
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(pSt[i].StdName);
		cout << "학번 : ";
		InputValue(pSt[i].Hakbun);

		cout << "\n수강한 과목의 수를 입력하세요.\n";
		cout << "과목수 : ";
		InputValue(pSt[i].SubNum);
		pSt[i].Sub = new Subject[pSt[i].SubNum];	//사용자로부터 입력받은 과목의 수 만큼 new로 할당

		cout << "\n\n* 수강한 과목" << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (int j = 0; j < pSt[i].SubNum; j++)
		{
			cout << "교과목명 : ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "과목학점수 : ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(pSt[i].Sub[j].Grade);
			cout << "\n";
			CalcGPA(pSt[i].Sub[j]);
		}

		pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);
	}
}

//모든 학생 정보를 출력하는 함수
void PrintAllStdList(Student* pSt, int StudentNum)
{
	cout << "\n=================================================================================\n";
	cout << "\t\t이름\t\t\t학번\n";
	cout << "=================================================================================\n";
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "\t\t" << pSt[i].StdName << "\t\t\t" << pSt[i].Hakbun<<"\n";
	}
	cout << "=================================================================================\n";
}

//학생 검색 후 학생의 이름 또는 학번을 수정하는 함수
void ModifyStdInfo(Student* pSt,int StudentNum)
{
	Student* tempModify = StdSearch(pSt, StudentNum);
	cout << "* <" << tempModify->StdName << ", " << tempModify->Hakbun << "> 의 정보를 수정하세요.\n";
	cout << "이름 : ";
	InputValue(tempModify->StdName);
	cout << "학번 : ";
	InputValue(tempModify->Hakbun);
}

int main(void)
{
	int count = 0;	//1번 입력 전에 2번, 3번 실행을 막기 위한 정수현 변수 선언
	int StudentNum;	//학생수를 받는 변수 선언

	int num;

	while (true)
	{
		cout << "학생수를 입력하세요 : ";
		cin >> StudentNum;

		if (StudentNum <= 0)	//학생수를 0이하로 적을때 다시 실행
		{
			continue;
		}

		break;
	}

	Student* stu = new Student[StudentNum];	//사용자로 부터 받은 StudentNum을만큼 new로 할당

	while (true)	//4 입력전에 끝나지 않는 반복문
	{
		PrintMenu();
		cout << "원하는 기능을 입력하세요 : ";
		cin >> num;
		cout << "\n";

		if (num == 1)	//학생 성적 입력
		{
			InputData(stu, StudentNum);
			count++;
		}

		else if (num == 2)	//전체 학생 성적보기
		{
			if (count == 0)
			{
				cout << "학생 정보를 먼저 입력해주세요!\n";
				continue;
			}

			PrintAllData(stu, StudentNum);
		}

		else if (num == 3)	//학생 이름 검색
		{
			if (count == 0)
			{
				cout << "학생 정보를 먼저 입력해주세요!\n";
				continue;
			}

			Student* tempSearch = StdSearch(stu, StudentNum);	//구조체 배열 temp에 서치한 후 결과 저장

			if (tempSearch != 0)	//검색 학생이 있을시
			{
				PrintOneData(*tempSearch);
			}

			else	//검색 학생이 없을시
			{
				cout << "\n이름을 제대로 확인해 주세요.\n";
			}
		}

		else if (num == 4)	//전체 학생 목록 보기
		{
			if (count == 0)
			{
				cout << "학생 정보를 먼저 입력해주세요!\n";
				continue;
			}

			PrintAllStdList(stu, StudentNum);
		}

		else if (num == 5)
		{
			if (count == 0)
			{
				cout << "학생 정보를 먼저 입력해주세요!\n";
				continue;
			}

			ModifyStdInfo(stu,StudentNum);
		}


		else if (num == 6)	//프로그램 종료
		{
			cout << "프로그램을 종료합니다.\n";
			break;
		}

		else	//메뉴에 없는 숫자를 입력했을 시
		{
			cout << "다시 입력 해주세요\n";
			continue;
		}
	}

	//new로 할당해줬던 구조체 배열 delete
	for (int i = 0; i < StudentNum; i++)
	{
		delete[]stu[i].Sub;
	}

	delete[]stu;

	return 0;	//0 반환
}