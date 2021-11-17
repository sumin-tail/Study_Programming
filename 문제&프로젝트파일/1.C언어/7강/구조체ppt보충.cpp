#include<stdio.h>

typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

void ShowPeople(People P)
{
	printf("===================\n");
	printf("1.이름 : %s\n", P.Name);
	printf("2.나이 : %d\n", P.Age);
	printf("3.키 : %.2f\n", P.Height);
	printf("===================\n");
}

void SetPeople(People* P)
{
	printf("===================\n");
	printf("이름입력 : ");
	scanf("%s", P->Name); // 원래는 (*P).Name 이지만 이걸 줄여써서 P->Name
	printf("나이입력 : ");
	scanf("%d", &P->Age);
	printf("키입력 : ");
	scanf("%f", &P->Height);
	printf("===================\n");
}

void main()
{
	People P1;
	SetPeople(&P1);
	ShowPeople(P1);

}
