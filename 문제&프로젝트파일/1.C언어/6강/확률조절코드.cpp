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
	srand(time(NULL)); //�õ尪 ���� 

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
	printf("====�̱� ����====\n");
	printf("    1.1ȸ �̱�\n");
	printf("    2.10+1ȸ �̱�\n");
	printf("    3.����\n");
}

void Gacha() 
{
	int Num = rand() % 100; //�������� 0 ���� 99���� ����
	if (Num >= 0 && Num < 60) //0 ~59 > 60��
		printf("N���..\n");
	else if (Num >= 60 && Num < 80) //60~79 >20��
		printf("R���!\n");
	else if (Num >= 80 && Num < 90) //80 ~89 >10��
		printf("SR���!!\n");
	else if (Num >= 90 && Num < 95) //90~ 94 >5��
		printf("��SSR��ޡ�\n");
	else if (Num >= 95 && Num < 98) //95~97 >3��
		printf("�١�!SSSR���!�ڡ�\n");
	else //98~99 >2��
	{
		printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
		printf("�١ڡ١��� �� �ڡ١ڡ١�\n");
		printf("�١ڡ١�  U R  �١ڡ١�\n");
		printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	}
}

