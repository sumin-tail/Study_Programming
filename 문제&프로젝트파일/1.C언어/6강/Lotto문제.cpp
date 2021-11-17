#include<stdio.h>
#include<stdlib.h>
#include<time.h>//�ð� �� ����ϴ� �������

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
			//do while�� ������ �� ������ ��
			RNum = (rand() % LOTTO_NUM_MAX) + 1;
			while (!Overlap(Lotto, i, RNum))
			{
				RNum = (rand() % LOTTO_NUM_MAX) + 1;
			}
			//�ߺ� üũ ���������� �����
			Lotto[i] = RNum;
		}

		//����� ���
		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d,", Lotto[i]);
		printf("\b ");
		system("pause");
	}
}

int Overlap(int Lotto[], int i, int RNum)
{
	//�� ���ڰ� �������� ������ �̾Ƶ� ���ڵ� �߿��� ���� ���ڰ� �ִ��� üũ
	//������� ���ο� �������� �־���� ���� ��� ���
	for (int count = 0; count < i; count++)
	{
		//�� üũ�� ���ݱ��� ���� ��ŭ 
		if (Lotto[count] == RNum)
		{
			return NONPASS;
		}
	}
	return PASS;
}