#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")
//���ǹ�
void main()
{
	int Select;
	char name[10];
	int Kor, Eng, Math;
	float Avg;

	//Ȯ�ο�
	bool nameflag=0;
	bool pointflag=0;
	while (1)
	{
		system("cls");
		printf("================\n");
		printf("�л� ��������\n");
		printf("================\n");
		printf("1.�л� �̸����\n");
		printf("2.3���� �������\n");
		printf("3.���� Ȯ��\n");
		printf("4.����\n");
		printf("================\n");
		printf("�Է� : ");
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			system("cls");
			printf("�̸� �Է� : ");
			scanf("%s", name);
			nameflag = 1;
			break;
		case 2:
			system("cls");
			printf("�������� ������ �Է��Ͻÿ�\n");
			printf("���� : ");
			scanf("%d", &Kor);
			printf("���� : ");
			scanf("%d", &Math);
			printf("���� : ");
			scanf("%d", &Eng);
			pointflag = 1;
			break;
		case 3:
			if (pointflag&&nameflag)
			{
				system("cls");
				printf("================\n");
				printf("%s���� ����\n", name);
				printf("���� ���� : %d\n���� ���� : %d\n���� ���� : %d\n", Kor, Math, Eng);
				printf("���� ���� : %d\n", Kor + Math + Eng);
				Avg = (float)(Eng + Kor + Math) / 3.0f;
				printf("��� ���� : %.2f\n", Avg);
				printf("================\n");
				system("pause");
				break;
			}
			else if (nameflag) 
			{
				system("cls");
				printf("������ �Է��ϼ���\n");
				system("pause");
				break;
			}
			else if (pointflag) 
			{
				system("cls");
				printf("�̸��� �Է��ϼ���\n");
				system("pause");
				break;
			}
			else
			{
				system("cls");
				printf("������ �Է��ϼ���\n");
				printf("�̸��� �Է��ϼ���\n");
				system("pause");
				break;
			}
		case 4:
			return;
		}
	}
}
