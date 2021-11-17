#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <map> 

typedef struct Student
{
	char name[10]; //이름
	int age; //나이
	char address[30]; //주소
	//국영수 점수
	int korean;
	int math;
	int english;
	//f랭크
	int max;
	float average;
	char rank;
}Student;

void Menu()
{
	printf("< < < = = = = 메뉴 = = = = > > >\n");
	printf("1.학생 등록\n");
	printf("2.학생 검색\n");
	printf("3.학생 목록\n");
	printf("4.학생 수정\n");
	printf("5.학생 삭제\n");
	printf("6.종료\n");
	printf("====================\n");
	printf("선택 : ");
}
//학생 랭크 계산
Student Student_Rank(Student Node)
{
	Node.max = Node.korean + Node.english + Node.math; //합계점수
	Node.average = (float)Node.max / 3;
	if (Node.average >= 90)
	{
		Node.rank = 'A';
	}
	else if (Node.average >= 80)
	{
		Node.rank = 'B';
	}
	else if (Node.average >= 70)
	{
		Node.rank = 'C';
	}
	else if (Node.average >= 60)
	{
		Node.rank = 'D';
	}
	else
	{
		Node.rank = 'F';
	}
	return(Node);
}
//학생추가
Student Student_Add()
{
	//새 동적할당하고 주소저장
	Student add;
	//학생정보입력
	printf("학생 이름 입력 : ");
	scanf("%s", add.name);
	printf("%s 학생 나이 입력 : ", add.name);
	scanf("%d", &add.age);
	printf("%s 학생 주소 입력 : ", add.name);
	scanf("%s", add.address);
	printf("%s 학생 국어 점수 : ", add.name);
	scanf("%d", &add.korean);
	printf("%s 학생 영어 점수 : ", add.name);
	scanf("%d", &add.english);
	printf("%s 학생 수학 점수 : ", add.name);
	scanf("%d", &add.math);
	printf("학생 정보 입력 완료\n");
	return 	Student_Rank(add);//구조체를 리턴함
}
//학생정보출력
void Student_Information(std::map<int, Student>::iterator iter, std::map<int, Student>* iMap)
{
	if (iter == iMap->end())
	{
		printf("검색하고자 하는 학생이 존재하지 않습니다.\n");
		return;
	}

	printf("학생 정보 검색 완료\n");
	printf("< < = = = = = Information = = = = = > >\n");
	printf("학생 학번 : %d\n", iter->first);
	printf("학생 이름 : %s\n", iter->second.name);
	printf("학생 나이 : %d 세\n", iter->second.age);
	printf("학생 주소 : %s\n", iter->second.address);
	printf("국어 점수 : %d 점\n", iter->second.korean);
	printf("영어 점수 : %d 점\n", iter->second.english);
	printf("수학 점수 : %d 점\n", iter->second.math);
	printf("합계 점수 : %d 점\n", iter->second.max);
	printf("평균 점수 : %.2f 점\n", iter->second.average);
	printf("학생 등급 : %c 등급\n", iter->second.rank);

}
//학생전체출력
void All_Student_Print(std::map<int, Student> iMap)
{
	for (std::map<int, Student>::iterator iter = iMap.begin(); iter != iMap.end(); iter++)
	{
		printf("\t  %s", iter->second.name);
		printf("\t%d", iter->second.age);
		printf("\t\t%s\n", iter->second.address);
	}
}
//학생수정
void Student_Retouch(std::map<int, Student>* iMap, std::map<int, Student>::iterator iter)
{
	int select = 0;
	int data;
	char change[30];

	if (iter == iMap->end())//해당학생이 없다는 뜻이니 리턴
	{
		printf("찾는 학생이 없습니다.\n");
		return;
	}

	while (select != 5)
	{
		system("cls");
		Student_Information(iter, iMap);// 학생 정보를 출력
		printf("\n");
		printf("수정할 항목을 선택 하시오\n");
		printf("1.이름 2.나이 3.주소 4.점수 5.수정종료\n");
		printf("선택 : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("현재 이름 : %s\n", iter->second.name);
			printf("수정할 이름 : ");
			scanf("%s", &change);
			printf("%s -> %s 로 이름 수정 완료\n", iter->second.name, change);
			strcpy(iter->second.name, change); //문자열은 대입이 안되니 strcpy 사용
			system("pause");
			break;
		case 2:
			printf("현재 나이 : %d 세\n", iter->second.age);
			printf("수정할 나이 :    세");
			printf("\b\b\b\b\b\b");
			scanf("%d", &data);
			printf("%d 세 -> %d 세 로 나이 수정 완료\n", iter->second.age, data);
			iter->second.age = data;
			system("pause");
			break;
		case 3:
			printf("현재 주소 : %s \n", iter->second.address);
			printf("수정할 주소 : ");
			scanf("%s", &change);
			printf("%s -> %s 로 주소 수정 완료\n", iter->second.address, change);
			strcpy(iter->second.address, change); //문자열
			system("pause");
			break;
		case 4:
			printf("현재 점수\n");
			printf("국어 : %d 영어 : %d 수학 : %d\n", iter->second.korean, iter->second.english, iter->second.math);
			printf("수정할 국어 점수 : ");
			scanf("%d", &data);
			iter->second.korean = data;
			printf("수정할 영어 점수 : ");
			scanf("%d", &data);
			iter->second.english = data;
			printf("수정할 수학 점수 : ");
			scanf("%d", &data);
			iter->second.math = data;
			printf("점수 수정 완료\n");
			//랭크갱신
			iter->second = Student_Rank(iter->second);
			system("pause");
			break;
		case 5:
			printf("수정을 종료합니다.\n");
			system("pause");
			break;
		}
	}

}

//학생 삭제
void Student_Delete(std::map<int, Student>::iterator iter, std::map<int, Student>* iMap)
{
	if (iter == iMap->end())
	{
		printf("해당학생 없음\n");
		system("pause");
		return;
	}
	iMap->erase(iter);
	printf("삭제 완료\n");
	system("pause");
}

void main()
{
	std::map<int, Student> studentMap;
	std::map<int, Student>::iterator iter;
	int studentNum = 20210001;

	int select;
	int num;

	while (1)
	{
		system("cls");
		Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1: //학생등록
			system("cls");
			printf("학번 : %d\n", studentNum);
			studentMap[studentNum++] = Student_Add();
			system("pause");
			break;
		case 2: //학생검색
			system("cls");
			printf("검색할 학번 입력 : ");
			scanf("%d", &num);
			Student_Information(studentMap.find(num), &studentMap);
			system("pause");
			break;
		case 3: //학생목록
			system("cls");
			printf("< < = = = = = Information = = = = = > >\n");
			printf("\n");
			printf("\t학생이름\t학생나이\t학생주소\n");
			All_Student_Print(studentMap);
			printf("<학생 개개인의 점수는 검색을 이용하세요!!>\n");
			system("pause");
			break;
		case 4: //학생수정
			system("cls");
			printf("수정할 학생 학번은? ");
			scanf("%d", &num);
			Student_Retouch(&studentMap, studentMap.find(num));
			break;
		case 5: //학생삭제
			system("cls");
			if (studentMap.empty())
			{
				printf("아무런 데이터가 없습니다.\n");
				system("pause");
				break;
			}
			printf("삭제할 학생 학번: ");
			scanf("%d", &num);
		    Student_Delete(studentMap.find(num), &studentMap);
			break;
		case 6: //종료 - 라이브러리는 알아서 할당해제 해줌
			printf("할당 해제 완료");
			return;
		}
	}
}