#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void Draw(int Map[][10]);
void Update(int Map[][10]);
void Stop(int Map[][10], int y);

void main()
{
	int Mapy = 10;
	//맵 배열을 0 으로 초기화
	int Map[10][10] = { 0 };
	char ch;
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
	printf("별을 보시겠습니까??\n");
	system("pause"); //어떤 키든 누르면 다음으로 패스
	system("cls"); //화면정리
	while (1)
	{
		Update(Map);
		//키입력이 들어온다면 True 가 반환되니 안으로 
		if (kbhit())
		{
			ch = getch();
			//들어온값이 d 또는 D 일경우 Map의 y축 값을-1 하고 스탑함수로 이동
			if (ch == 'd' || ch == 'D')
			{
				Mapy--;
				Stop(Map, Mapy);
			}
		}
		Draw(Map);
		//0.1 초 대기
		Sleep(100);
	}
}

void Draw(int Map[][10])
{
	//화면 정리
	system("cls");
	//배열 돌면서 값이 1또는 2인 경우에 별 출력 아니라면 빈공간 출력
	//1은 멈추지 않은별 2는 멈춘 별 >> Update 함수에서 2는 건드리지 않음
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1|| Map[y][x] == 2)
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
	printf("별 멈추기 = d");
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
					Map[y][x - 1] = 1;
				}
				break;
			}

		}
	}
}

void Stop(int Map[][10], int y)
{
	//이건 X-가로 칸만 돔
	for (int x = 0; x < 10; x++)
	{
		//해당칸의 값이 1일 경우
		if (Map[y][x] == 1)
		{
			//2로 바꿔줌 > 별을 멈춤
			Map[y][x] = 2;
			return;
		}
	}
}