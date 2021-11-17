#include<stdio.h>
#include<Windows.h>

#define LENGTH 5

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

void SetPeople(People *P, int i)
{
	printf("======%d======\n",i+1);
	printf("이름입력 : ");
	scanf("%s", &(P + i)->Name); 
	printf("나이입력 : ");
	scanf("%d", &(P + i)->Age);
	printf("키입력 : ");
	scanf("%f", &(P + i)->Height);
	printf("============\n");
}

void SortPeople(People P[])
{
	People Ptmp;

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = i+1; j < LENGTH; j++)
		{
			if ( P[i].Age == P[j].Age && P[i].Height < P[j].Height)
			{
				Ptmp = P[i];
				P[i] = P[j];
				P[j] = Ptmp;
			}
			else if(P[i].Age < P[j].Age)
			{
				Ptmp = P[i];
				P[i] = P[j];
				P[j] = Ptmp;
			}
		}
	}

}

void main()
{
	// 나이순 > 만약 같은경우 키순으로 한번더
	People P[5];

	for (int i = 0; i < LENGTH; i++)
	{
		SetPeople(P, i);
	}
	system("pause");
	system("cls");
	printf("정렬 전 정보\n");

	for (int i = 0; i < LENGTH; i++)
	{
		ShowPeople(P[i]);
	}
	system("pause");

	SortPeople(P);

	system("cls");
	//정렬 후
	for (int i = 0; i < LENGTH; i++)
	{
		ShowPeople(P[i]);
	}
	system("pause");
	
}
