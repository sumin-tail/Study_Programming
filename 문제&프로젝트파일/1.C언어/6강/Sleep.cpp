#include<stdio.h>
#include<Windows.h>

void Draw(int Map[][10]);
void Update(int Map[][10]);

void main()
{
	//맵 배열을 0 으로 초기화
	int Map[10][10] = { 0 };
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//각 줄 맨 끝칸에는 1을 넣어줌
			if (x == 9) 
			{
				Map[y][x] = 1;
			}
		}
	}
	while (1)
	{
		Draw(Map);
		//0.5 초 대기
		Sleep(500);
		Update(Map);
	}
}

void Draw(int Map[][10])
{
	//화면 정리
	system("cls");
	//배열 돌면서 값이 1 인경우에 별 출력 0인 경우에는 빈공간 출력
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1)
			{
				printf("☆");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void Update(int Map[][10])
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//만약 돌다가 값이 1인 구간을 마추치면
			if (Map[y][x] == 1)
			{
				//그칸의 값을 0으로 바꿔줌
				Map[y][x] = 0;
				//그리고 X번째 칸의 값 -1 이 0 보다 작을경우 
				//해당 줄의 맨 끝칸에 다시보냄(별이 땅에 떨어짐)  
				if (x - 1 < 0) 
				{
					Map[y][9] = 1;
				}
				else//아닐경우 별의 위치를 한칸앞으로 
				{
					Map[y][x-1] = 1;
				}
				break;
			}

		}
	}
}

//그외 것

//16진수 1자리 = 2진수 4자리
//2 4 8 16
//16진수 2자리= 1바이트
//메모리는 16진수 8자리 == 4바이트