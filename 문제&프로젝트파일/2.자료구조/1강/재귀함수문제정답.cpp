#include<stdio.h>


int Sum(int Num)
{
	if (Num == 0)
		return Num;
	return Sum(Num - 1) + Num;
}

void Bin(int Num, int* BinNum)
{
	if (Num == 1)
	{
		(*BinNum) *= 10;
		(*BinNum) += Num;
		return;
	}
	Bin(Num / 2, BinNum);
	(*BinNum) *= 10;
	(*BinNum) += Num % 2;
}

void main()
{
	int Num;
	printf("1.정수 입력 : ");
	scanf("%d", &Num);
	printf("1 ~ %d : %d\n", Num, Sum(Num));

	printf("2.정수 입력 : ");
	scanf("%d", &Num);
	int BinNum = 0;
	Bin(Num, &BinNum);
	printf("%d -> %d\n", Num, BinNum);
	return;
}
