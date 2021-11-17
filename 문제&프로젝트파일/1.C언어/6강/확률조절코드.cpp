#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define TRUE 1
#define FALSE 0

void Menu();
void Gacha();

void main()
{
	int Exit = FALSE;
	int Select;
	srand(time(NULL)); //시드값 적용 

	while (!Exit)
	{
		Menu();
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			Gacha();
			system("pause");
			break;
		case 2:
			for (int i = 0; i < 11; i++)
				Gacha();
			system("pause");
			break;
		case 3:
			Exit = TRUE;
		}
	}
}

void Menu()
{
	system("cls");
	printf("====뽑기 게임====\n");
	printf("    1.1회 뽑기\n");
	printf("    2.10+1회 뽑기\n");
	printf("    3.종료\n");
}

void Gacha() 
{
	int Num = rand() % 100; //나머지가 0 에서 99까지 나옴
	if (Num >= 0 && Num < 60) //0 ~59 > 60퍼
		printf("N등급..\n");
	else if (Num >= 60 && Num < 80) //60~79 >20퍼
		printf("R등급!\n");
	else if (Num >= 80 && Num < 90) //80 ~89 >10퍼
		printf("SR등급!!\n");
	else if (Num >= 90 && Num < 95) //90~ 94 >5퍼
		printf("☆SSR등급☆\n");
	else if (Num >= 95 && Num < 98) //95~97 >3퍼
		printf("☆★!SSSR등급!★☆\n");
	else //98~99 >2퍼
	{
		printf("☆★☆★☆★☆★☆★☆★\n");
		printf("☆★☆★초 대 박☆★☆★\n");
		printf("☆★☆★  U R  ☆★☆★\n");
		printf("☆★☆★☆★☆★☆★☆★\n");
	}
}

