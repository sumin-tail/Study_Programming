#include <iostream>
#include <string>
#include<Windows.h>

using namespace std;
//학생의 이름,나이,학년,번호,성적을 저장하는 구조체를 만든 뒤 동적할당으로 관리하시오   
//(최대 학생수 10명) / (90점이상 A, 80점이상 B, 70점이상 C, 60점이상 D, 60점미만 F) / 국어 수학 영어 종합 평균 점수 있음 

//함수화 및 #define 하기!!
#define MAX 10

typedef struct Student
{
	string name; //이름
	int age; //나이
	int grade;//학년
	//국영수 점수
	int korean;
	int math;
	int english;
	//랭크
	int max;
	float average;
	char rank;
}Student;

void Menu(int StudentCount)
{
	cout << "===학생정보관리===(학생수 : " << StudentCount << "명)" << endl;
	cout << "   1.학생등록" << endl;
	cout << "   2.학생정보 보기" << endl;
	cout << "   3.학생검색" << endl;
	cout << "   4.등급별 보기" << endl;
	cout << "   5.학년별 보기" << endl;
	cout << "   6.종료" << endl;
	cout << " 입력 : " << endl;
}

void Student_Print(Student newS, int StudentCount)
{
	cout << "    ======" << StudentCount << "번째 학생======" << endl;
	cout << "    이름 : " << newS.name << endl;
	cout << "    나이 : " << newS.age <<"살"<< endl;
	cout << "    학년 : " << newS.grade <<"학년" <<endl;
	cout << "    국어점수 : " << newS.korean << endl;
	cout << "    수학점수 : " << newS.math << endl;
	cout << "    영어점수 : " << newS.english << endl;
	cout << "    합계점수 : " << newS.max << "   평균점수 : " << newS.max << endl;
	cout << "    등급 : [" << newS.rank << "]" << endl << endl;
}

void Student_Print_Rank(Student* newS[], char rank, int StudentCount)
{
	cout <<"┌────────────────"<< rank <<" 등급────────────────┐" << endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->rank == rank)
		{
			Student_Print(*newS[i], i);
		}
	}
	cout << "└───────────────────────────────────┘"<< endl;
}

void Student_Print_Grade(Student* newS[], char grade, int StudentCount)
{
	cout << "┌────────────────" << grade << " 학년────────────────┐" << endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->grade == grade)
		{
			Student_Print(*newS[i], i);
		}
	}
	cout << "└───────────────────────────────────┘" << endl;
}

void Student_Rank(Student* Node)
{
	Node->max = Node->korean + Node->english + Node->math; //합계점수
	Node->average = (float)Node->max / 3;
	if (Node->average >= 90)
	{
		Node->rank = 'A';
	}
	else if (Node->average >= 80)
	{
		Node->rank = 'B';
	}
	else if (Node->average >= 70)
	{
		Node->rank = 'C';
	}
	else if (Node->average >= 60)
	{
		Node->rank = 'D';
	}
	else
	{
		Node->rank = 'F';
	}
}

void Student_Add(Student* newS, int StudentCount)
{
	cout << "======"<< StudentCount <<"번째 학생======" << endl;
	cout << "이름 : ";
	cin >> newS->name;
	cout << "나이 : ";
	cin >> newS->age;
	do
	{
		cout << "학년<1~3> : ";
		cin >> newS->grade;
		if (newS->grade <= 3 && newS->grade >= 1)
		{
			break;
		}
		cout << "잘못 입력 다시" << endl;
	} while (newS->grade > 3 || newS->grade < 1);
	cout << "국어점수 : ";
	cin >> newS->korean;
	cout << "수학점수 : ";
	cin >> newS->math;
	cout << "영어점수 : ";
	cin >> newS->english;
	Student_Rank(newS);
}

void Student_Search(Student* newS[],int StudentCount)
{
	string name;
	cout << "이름 입력 : ";
	cin >> name;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->name == name)
		{
			Student_Print(*newS[i], i);
			return;
		}
	}
	cout << "해당 학생이 없습니다."<<endl;
}

void main()
{
	int Select, StudentCount = 0;
	Student *Student_List[MAX];
	while (1)
	{
		system("cls");
		Menu(StudentCount);
		cin >> Select;
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount < MAX) //학생이 정원 미만일때
			{
				Student_List[StudentCount] = new Student; //동적 할당
				Student_Add(Student_List[StudentCount], StudentCount);//학생 추가
				StudentCount++; //학생 카운트 해줌
			}
			system("pause");
			break;
		case 2: //학생 모두 출력
			system("cls");
			for (int i = 0; i < StudentCount; i++)
			{
				Student_Print(*Student_List[i], i);
			}
			system("pause");
			break;
		case 3: //학생 검색
			system("cls");
			Student_Search(Student_List, StudentCount);
			system("pause");
			break;
		case 4: //등급별 보기
			system("cls");
			for (char rank = 'A'; rank <= 'F'; rank++)
			{
				Student_Print_Rank(Student_List, rank, StudentCount);
			}
			system("pause");
			break;
		case 5: //학년별 보기
			system("cls");
			for (int grade = 1; grade <= 3; grade++)
			{
				Student_Print_Grade(Student_List, grade, StudentCount);
			}
			system("pause");
			break;
		case 6: //종료- 할당해제 시킬것
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i + 1 << "번 학생 : " << Student_List[i]->name << endl;
				delete Student_List[i];
				cout << "할당 해제 완료" << endl;
			}
			system("pause");
			return;
		}
	}
}
