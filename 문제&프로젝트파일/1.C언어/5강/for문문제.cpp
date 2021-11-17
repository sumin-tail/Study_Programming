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
	printf("1번문제\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i%2==0)
			continue;
		printf("%d.Hello\n", i);
	}

	printf("2번문제\n");
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

	printf("3번문제\n");
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
	for (int i = 0; i < 29; i++) // 1원을 첫날에 넣었으니 하루 뺌
	{
		save = save*2;
		money += save;
	}
	printf("2번 문제\n");
	printf("30일 동안 저축한 금액 : %d\n", money);
}

void Three()
{
	printf("3번 문제\n");
	int max = 0;
	for (int i = 1; i <= 1000; i++) // 1부터 시작
	{
		if (i%3 == 0 && i%5 !=0)
		{
			continue;
		}
		max += i;
	}
	printf("<3의 배수는 제외하며 3과 5의 공배수는 제외하지 않는다> \n");
	printf("1 ~ 1000 사이의 합 : %d\n", max);
}

void Four() 
{
	int max = 0;
	printf("4번 문제\n");
	for (int i = 1; max + i < 10000; i += 2) // 1부터 시작
	{
		max += i;
	}
	printf("10000을 넘기 직전의 수 : %d\n", max);
}