#include<stdio.h>
void main()
{
	int point[10];
	int high = 0;
	int max = 0;
	float mid;

	for (int i = 0; i < 10; i++) 
	{
		printf("[%d]번째 정수 입력 : ", i+1);
		scanf("%d", &point[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		if (high < point[i])
		{
			high = point[i];
		}

		max += point[i];
	}

	mid = (float)(max/10);
	printf("최대값 = %d  총합 = %d  평균 = %.2f", high , max, mid);

}
