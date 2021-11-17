#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define MAX 50

typedef struct student
{
	char Name[10]; //이름
	int Age; //나이
	int Class; //학년
	int Number; //번호
	char Gender[10]; //성별
}Student;

//학생 출력
void ShowStudent(Student* St)
{
	printf("\t======%s학생(%d번)======\n", St->Name, St->Number);
	printf("\t나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("\t========================\n");
}

//학생 등록
void SetStudent(Student* St, int* StudentCount)
{
	system("cls");
	St->Number = ++(*StudentCount);//전치=더하고 난뒤 해당 학생의 번호에 넣음(대입) 
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name); // (*P).Name 와 P->Name 는 같음
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력<1~3> : ");
	scanf("%d", &St->Class); //학년은 학년을 잘못입력했을때만 아래쪽이 돌게
	while (St->Class < 1 || St->Class > 3) //1이하거나 3이상일때 
	{
		printf("학년 잘못 입력<범위 1~3학년>");
		system("pause");
		printf("학년 입력<1~3> : ");
		scanf("%d", &St->Class);
	}

}

//학생목록 학년순
void ShowClass(Student* St[], int StudentCount, int Class)
{
	//학년을 입력받고 그학년이랑 같은 학년만 출력!!
	//전체 출력은 메인에서 1부터 3학년까지 돌림 
	printf("┌────────────────%d 학년────────────────┐\n", Class);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == Class)
		{
			ShowStudent(St[i]);
		}
	}
	printf("└───────────────────────────────────┘\n");
}

//이름 검색
void NameSearch(Student* St[], int StudentCount)
{
	char nameCheck[10];
	printf("검색할 이름 입력 : ");

	//문자열 비교 함수 > 두 문자열이 같으면 0을 출력함!!
	//strcmp(Name1, Name2);
	scanf("%s", nameCheck);
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St[i]->Name, nameCheck) == 0)
		{
			ShowStudent(St[i]);
		}
	}
}

void LoadStudent() 
{

}

void main()
{
	Student* Student_List[MAX]; //학생 구조체의 "주소를 담을" 포인터 배열 50개를 만듬 Student_List의 바이트 수는 4x50인 200임
	//구조체 Student의 크기는 개당 36 바이트지만 Student_List는 칸당 4바이트(주소를 담으니 4바이트 고정)
	int Select;
	int StudentCount = 0; //총인원
	FILE* f;
	int loadnum;

	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("1.학생 등록\n");
		printf("2.학생 목록(번호순)\n");
		printf("3.학생 목록(학년순)\n");
		printf("4.학년 검색\n");
		printf("5.학생 검색\n");
		printf("6.마지막 학생 삭제\n");
		printf("7.학생 전체 삭제\n");
		printf("8.학생정보 저장\n");
		printf("9.학생정보 불러오기\n");
		printf("10.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
			//학생 등록
		case 1:
			if (StudentCount + 1 >= MAX)
			{
				printf("학생정원(50명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student)); //학생구조체의 사이즈만큼 동적 할당 > 그 주소를 n번째 배열에 넣음
			SetStudent(Student_List[StudentCount], &StudentCount); //Student_List[StudentCount]는 주소를 가지고 있음 / StudentCount는 아니니 & 붙임
			break;
			//학생 목록(번호순) 출력
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)//현재 학생 수 만큼 출력
				ShowStudent(Student_List[i]);
			system("pause");
			break;
			//학생 목록(학년순) 출력
		case 3:
			system("cls");
			for (int i = 1; i <= 3; i++)
			{
				ShowClass(Student_List, StudentCount, i);
			}
			system("pause");
			break;
			//학년 검색
		case 4: //잘못입력되면 퍼즈하고 다시 처음부터 출력 이니 아예 while문 안에 넣어버리기
			system("cls");
			while (1)
			{
				printf("검색할 학년 입력(1~3) : ");
				scanf("%d", &Select);
				if (Select <= 3 && Select >= 1) //3 이상 1이하 일때 바로 출력
				{
					break;
				}
				printf("학년 잘못 입력(범위 1~3학년)\n");
				system("pause");
			}
			ShowClass(Student_List, StudentCount, Select);
			system("pause");
			break;
			//학생 검색
		case 5:
			system("cls");
			NameSearch(Student_List, StudentCount);
			system("pause");
			break;
			//마지막 학생 삭제
		case 6:
			//학생이 0 이 아닐때 맨 마지막에 들어온 학생 정보 삭제
			//동적할당 해제하고 배열에 NULL값 집어넣고 StudentCount를 하나 감소시킴
			if (StudentCount <= 0)
			{
				printf("더 이상 삭제할 학생이 없습니다.\n");
				system("pause");
			}
			else
			{
				//먼저 빼면 아래에서 일일히 StudentCount-1 할 필요가 없음
				StudentCount -= 1;
				free(Student_List[StudentCount]);
				Student_List[StudentCount] = NULL;
			}
			break;
			//학생 전체 삭제
		case 7:
			for (int i = 0; i < StudentCount; i++)//동적 할당했던 주소를 하나씩 풀어줌
			{
				free(Student_List[i]);
				Student_List[i] = NULL;
			}
			StudentCount = 0;
			break;
			//학생정보 저장
		case 8:
			f = fopen("학생정보.txt", "w");
			//학생수 저장
			fprintf(f, "%d\n", StudentCount);
			for (int i = 0; i < StudentCount; i++)
			{
				fprintf(f, "%s %d %d %s\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Class, Student_List[i]->Gender);
			}
			fclose(f);
			printf("저장 완료!!");
			system("pause");
			break;
			// 학생정보 불러오기
		case 9:
			//학생을 순차적으로 하나씩 불러옴
			//데이터 순서는 총 인원수/n 이름 나이 학년 성별 순
			f = fopen("학생정보.txt", "r");
			if (f == NULL)
			{
				printf("저장된 학생정보가 없습니다.");
				system("pause");
				break;
			}

			fscanf(f, "%d", &loadnum); //인원수가 얼마나 있는지부터 뺌

			for (int i = 0; i < loadnum && !feof(f); i++)
			{
				if (StudentCount + 1 > MAX)
				{
					printf("더이상 학생을 불러올 수 없습니다");
					system("pause");
					break;
				}

				Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
				fscanf(f, "%s", Student_List[StudentCount]->Name);
				fscanf(f, "%d", &(Student_List[StudentCount]->Age));
				fscanf(f, "%d", &(Student_List[StudentCount]->Class));
				fscanf(f, "%s", Student_List[StudentCount]->Gender);
				Student_List[StudentCount]->Number = StudentCount + 1;
				StudentCount++;
			}
			fclose(f);
			break;
		case 10://종료할때도 동적할당 해제하는것 잊지않기
			for (int i = 0; i < StudentCount; i++)
			{
				free(Student_List[i]); //Student_List 는 어짜피 지역변수라 프로그램을 끄면 자동으로 사라짐
			}
			return;
		}
	}
}
