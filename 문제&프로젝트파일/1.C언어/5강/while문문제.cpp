#include<stdio.h>
#include<conio.h>//�ܼ������ �������(getch()getch(),putch())
#define ENTER 13

void main()
{
	int i = 0;
	int max = 0;
	printf("6. �Էµ� ������ ���ڸ� �� �հ�\n");
	printf("���� �Է� : ");
	scanf("%d", &i);
	while (i != 0)
	{
		max += i % 10;
		i = i / 10; 
	}

	printf("���� �հ� : %d", max);

}

void One() 
{
	int i = 0, j = 0, sum = 0;
	while (1)
	{
		printf("1. 1 ~ 20 ���� ���� �Է� : ");
		scanf("%d", &i);
		if (i >= 1 && i <= 20)
		{
			break;
		}
		printf("�߸� �Է�\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1 ~ %d �����հ� : %d", i, sum);

}

void Two() 
{
	int i = 0;
	printf("2. Hello ���\n");
	while (i < 5)
	{
		printf("Hello\n");
		i++;
	}
}

void Three() 
{

	int i = 0;
	int max = 0;
	printf("3. ���� �ݺ� �Է�(0�Է� �� ����)\n");
	while (1)
	{
		printf("���� �Է� : ");
		scanf("%d", &i);

		if (i == 0)
		{
			break;
		}
		else
		{
			max += i;
		}
	}
	printf("���� �հ� : %d\n", max);
}

void Four() 
{
	int i = 2;
	int num = 0;
	printf("4. �Ҽ� �Ǻ�\n");
	printf("���� �Է� : ");
	scanf("%d", &num);

	//1�� ����ó��
	if (num == 1)
	{
		printf("%d��(��) �Ҽ� �Դϴ�.\n", num);
	}

	while (i <= num)
	{
		if (i == num) //i �� �ڱ��ڽŰ� ���� ��� ������ 
		{
			printf("%d��(��) �Ҽ� �Դϴ�.\n", num);
			break;
		}
		else if (num % i == 0) //�������� 0�϶�
		{
			printf("%d��(��) �Ҽ��� �ƴմϴ�.\n", num);
			break;
		}
		i++;
	}
}

void Five() 
{
	int i = 0;
	printf("5. �Էµ� ���� �Ųٷ� ���\n");
	printf("���� �Է� : ");
	scanf("%d", &i);

	while (i != 0)
	{
		printf("%d", i % 10); //���� �����ڸ� ���
		i = i / 10; //���� �����ڸ� ���ֹ���
	}
}

void Six() 
{
	int i = 0;
	int max = 0;
	printf("6. �Էµ� ������ ���ڸ� �� �հ�\n");
	printf("���� �Է� : ");
	scanf("%d", &i);
	while (i != 0)
	{
		max += i % 10;
		i = i / 10;
	}

	printf("���� �հ� : %d", max);
}