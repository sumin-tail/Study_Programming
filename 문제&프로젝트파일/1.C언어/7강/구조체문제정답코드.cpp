#include<stdio.h>
#include<Windows.h>
#define MAX 5
typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

void SetPeople(People* P, int i) //그 주소를 받고 그 값에 접근하겠다
{
	printf("======%d======\n", i + 1);
	printf("이름 입력 : ");
	scanf("%s", P->Name); // 원래는 (*P).Name 이지만 이걸 줄여써서 P->Name
	printf("나이 입력 : ");
	scanf("%d", &P->Age);
	printf("키 입력 : ");
	scanf("%f", &P->Height);
	printf("==============\n");
}

void ShowPeople(People P, int i)
{
	printf("======%d======\n", i + 1);
	printf("이름 : %s\n", P.Name);
	printf("나이 : %d\n", P.Age);
	printf("키 : %.2f\n", P.Height);
	printf("==============\n");
}

void Sort_Arr(People* P)
{
	People tmp;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (P[i].Age < P[j].Age || (P[i].Age == P[j].Age && P[i].Height < P[j].Height)) //조건식을 하나로 만들어서 코드의 줄을 줄임
			{
				tmp = P[i];
				P[i] = P[j];
				P[j] = tmp;
			}
		}
	}
}

void main()
{
	People P_List[MAX];
	for (int i = 0; i < MAX; i++)
		SetPeople(&P_List[i], i); //해당 배열의 n번째 값이 들어있는 주소를 넘겨줌
	system("cls");
	printf("정렬 전 정보 \n");
	for (int i = 0; i < MAX; i++)
		ShowPeople(P_List[i], i);
	system("pause");
	Sort_Arr(P_List);
	system("cls");
	for (int i = 0; i < MAX; i++)
		ShowPeople(P_List[i], i);
}
