#include<stdio.h>


void One();
void Two();
void Three();

void main()
{
	//One();
	//Two();
	Three();
}


void One() 
{
	for (int i = 2; i <= 9; i++)
	{
		printf("====%d��====\t", i);
	}
	for (int i = 1; i <= 9; i++)
	{
		printf("\n");
		for (int j = 2; j <= 9; j++)
		{
			printf("%d x %d = %d\t", j,i, i*j);
		}
		printf("\n");

	}
}

//�ﰢ�� �׸���
void Two() 
{
	int hight = 0; 
	printf("���� �Է� : ");
	scanf("%d", &hight);
	for (int i = 1; i <= hight; i++)
	{
		for (int j = 1; j <= i ; j++)
		{
			printf("��");
		}
		printf("\n");
	}
}

void Three()
{
	int width=0; //����
	int hight=0; //����

	printf("���ο� ���θ� �Է��Ͻÿ� : ");

	scanf("%d %d", &width, &hight);
	//���� ����ؾ� �ϴ� ����
	//ù°�ٰ� ���������� ���� ������ ũ�⸸ŭ ����ؾ���
	//���������� �� ù��°�� �� ���������� ���

	for (int i = 1; i <= hight; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i == 1 || i == hight || j == 1 || j == width)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}			
		}
		printf("\n");
	}
}