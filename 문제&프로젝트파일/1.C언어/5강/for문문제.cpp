#include<stdio.h>

void One();
void Two();
void Three();
void Four();

void main()
{
	Two();
}


void One() 
{
	printf("1������\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i%2==0)
			continue;
		printf("%d.Hello\n", i);
	}

	printf("2������\n");
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("%c", ch);
		if (ch == ('A'+'Z')/2 || ch =='Z')
		{
			printf("\n");
			continue;
		}
		printf(",");
	}

	printf("3������\n");
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		if (i%3 == 0)
		{
			printf("%d", i);
			sum += i;
			printf("+");
		}
		if (i == 10)
		{
			printf("\b=");
		}
	}
	printf("%d", sum);
}

void Two() 
{
	int money = 1;
	int save = 1;
	for (int i = 0; i < 29; i++) // 1���� ù���� �־����� �Ϸ� ��
	{
		save = save*2;
		money += save;
	}
	printf("2�� ����\n");
	printf("30�� ���� ������ �ݾ� : %d\n", money);
}

void Three()
{
	printf("3�� ����\n");
	int max = 0;
	for (int i = 1; i <= 1000; i++) // 1���� ����
	{
		if (i%3 == 0 && i%5 !=0)
		{
			continue;
		}
		max += i;
	}
	printf("<3�� ����� �����ϸ� 3�� 5�� ������� �������� �ʴ´�> \n");
	printf("1 ~ 1000 ������ �� : %d\n", max);
}

void Four() 
{
	int max = 0;
	printf("4�� ����\n");
	for (int i = 1; max + i < 10000; i += 2) // 1���� ����
	{
		max += i;
	}
	printf("10000�� �ѱ� ������ �� : %d\n", max);
}