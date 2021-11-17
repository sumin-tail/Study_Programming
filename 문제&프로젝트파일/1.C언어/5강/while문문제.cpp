#include<stdio.h>
#include<conio.h>//콘솔입출력 헤더파일(getch()getch(),putch())
#define ENTER 13

void main()
{
	int i = 0;
	int max = 0;
	printf("6. 입력된 정수의 각자리 수 합계\n");
	printf("정수 입력 : ");
	scanf("%d", &i);
	while (i != 0)
	{
		max += i % 10;
		i = i / 10; 
	}

	printf("최종 합계 : %d", max);

}

void One() 
{
	int i = 0, j = 0, sum = 0;
	while (1)
	{
		printf("1. 1 ~ 20 사이 정수 입력 : ");
		scanf("%d", &i);
		if (i >= 1 && i <= 20)
		{
			break;
		}
		printf("잘못 입력\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1 ~ %d 누적합계 : %d", i, sum);

}

void Two() 
{
	int i = 0;
	printf("2. Hello 출력\n");
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
	printf("3. 정수 반복 입력(0입력 시 종료)\n");
	while (1)
	{
		printf("정수 입력 : ");
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
	printf("최종 합계 : %d\n", max);
}

void Four() 
{
	int i = 2;
	int num = 0;
	printf("4. 소수 판별\n");
	printf("정수 입력 : ");
	scanf("%d", &num);

	//1은 예외처리
	if (num == 1)
	{
		printf("%d은(는) 소수 입니다.\n", num);
	}

	while (i <= num)
	{
		if (i == num) //i 가 자기자신과 같을 경우 내보냄 
		{
			printf("%d은(는) 소수 입니다.\n", num);
			break;
		}
		else if (num % i == 0) //나며지가 0일때
		{
			printf("%d은(는) 소수가 아닙니다.\n", num);
			break;
		}
		i++;
	}
}

void Five() 
{
	int i = 0;
	printf("5. 입력된 정수 거꾸로 출력\n");
	printf("정수 입력 : ");
	scanf("%d", &i);

	while (i != 0)
	{
		printf("%d", i % 10); //가장 낮은자리 출력
		i = i / 10; //가장 낮은자리 없애버림
	}
}

void Six() 
{
	int i = 0;
	int max = 0;
	printf("6. 입력된 정수의 각자리 수 합계\n");
	printf("정수 입력 : ");
	scanf("%d", &i);
	while (i != 0)
	{
		max += i % 10;
		i = i / 10;
	}

	printf("최종 합계 : %d", max);
}