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
	printf("���� �Է� : ");
	scanf("%d", &num);
	printf("1������ �հ� : %d", One(num));
	printf("\n\n");

	printf("���� �Է� : ");
	scanf("%d", &num);
	printf("2���� ���� : ");
	Two(num);

	return;
}
