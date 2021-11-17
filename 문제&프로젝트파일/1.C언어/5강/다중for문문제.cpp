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
		printf("====%d단====\t", i);
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

//삼각형 그리기
void Two() 
{
	int hight = 0; 
	printf("높이 입력 : ");
	scanf("%d", &hight);
	for (int i = 1; i <= hight; i++)
	{
		for (int j = 1; j <= i ; j++)
		{
			printf("★");
		}
		printf("\n");
	}
}

void Three()
{
	int width=0; //가로
	int hight=0; //세로

	printf("가로와 세로를 입력하시오 : ");

	scanf("%d %d", &width, &hight);
	//별을 출력해야 하는 순간
	//첫째줄과 마지막줄은 별을 가로의 크기만큼 출력해야함
	//나머지줄은 맨 첫번째와 맨 마지막에만 출력

	for (int i = 1; i <= hight; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i == 1 || i == hight || j == 1 || j == width)
			{
				printf("★");
			}
			else
			{
				printf("  ");
			}			
		}
		printf("\n");
	}
}