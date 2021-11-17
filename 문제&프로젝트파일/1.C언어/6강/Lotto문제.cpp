#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값 사용하는 헤더파일

#define LOTTO_NUM 6
#define LOTTO_NUM_MAX 45

#define PASS 1;
#define NONPASS 0;

int Overlap(int Lotto[], int i, int RNum);

void main()
{
	int RNum;
	int Lotto[LOTTO_NUM] = { 0 };
	srand((unsigned)time(NULL));

	while (1)
	{
		system("cls");
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			//do while을 썼으면 더 좋았을 것
			RNum = (rand() % LOTTO_NUM_MAX) + 1;
			while (!Overlap(Lotto, i, RNum))
			{
				RNum = (rand() % LOTTO_NUM_MAX) + 1;
			}
			//중복 체크 성공했을때 여기로
			Lotto[i] = RNum;
		}

		//여기는 출력
		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d,", Lotto[i]);
		printf("\b ");
		system("pause");
	}
}

int Overlap(int Lotto[], int i, int RNum)
{
	//새 숫자가 들어왔을때 기존에 뽑아둔 숫자들 중에서 같은 숫자가 있는지 체크
	//있을경우 새로운 랜덤값을 넣어야함 없을 경우 통과
	for (int count = 0; count < i; count++)
	{
		//값 체크는 지금까지 들어온 만큼 
		if (Lotto[count] == RNum)
		{
			return NONPASS;
		}
	}
	return PASS;
}