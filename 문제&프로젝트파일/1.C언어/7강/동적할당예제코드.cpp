#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("======%s학생(%d번)======\n", St->Name, St->Number);
	printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}

void SetStudent(Student* St, int* StudentCount)
{
	St->Number = ++(*StudentCount);//전치=더하고 난뒤 해당 학생의 번호에 넣음(대입) 
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name); // (*P).Name 와 P->Name 는 같음
	printf("나이 입력 : ");
	scanf("%d", &St->Age); 
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력 : ");
	scanf("%d", &St->Class);
}

void main()
{
	Student* Student_List[MAX]; //학생 구조체의 "주소를 담을" 포인터 배열 50개를 만듬 Student_List의 바이트 수는 4x50인 200임
	//구조체 Student의 크기는 개당 36 바이트지만 Student_List는 칸당 4바이트(주소를 담으니 4바이트 고정)
	int Select;
	int StudentCount = 0; //총인원

	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("1.학생 등록\n");
		printf("2.학생 목록\n");
		printf("3.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
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
		case 2:
			for (int i = 0; i < StudentCount; i++)//현재 학생 수 만큼 출력
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			for (int i = 0; i < StudentCount; i++)//동적 할당했던 주소를 하나씩 풀어줌
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}