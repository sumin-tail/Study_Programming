#include <stdio.h>

int One(int n)
{
	if (n <= 0)
		return 0;
	else
		n += One(n - 1);

	return n;
}

void Two(int n)
{
	if (n == 1)
	{
		printf("%d", n % 2);
		return;
	}
	else 
	{
		Two(n / 2);
	}
	printf("%d", n%2);
}

void main()
{
	int num;
	printf("숫자 입력 : ");
	scanf("%d", &num);
	printf("1부터의 합계 : %d", One(num));
	printf("\n\n");

	printf("숫자 입력 : ");
	scanf("%d", &num);
	printf("2진수 변경 : ");
	Two(num);

	return;
}
