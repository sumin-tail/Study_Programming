#include<stdio.h>

int One(int one, int two);
int Two(int one);
int Three(int one);
int Four(int one);
int Five(int one);

void main()
{
	int one = 0;
	int two = 0;
	
	printf("1. �� ���� �Է� �Ͻÿ� : ");
	scanf("%d %d", &one, &two);
	printf("%d�� %d�� ū���� %d �Դϴ�.", one ,two, One(one,two));

	printf("2. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &one);
	switch (Two(one))
	{
	case 1:
		printf("%d�� Ȧ���Դϴ�.", one);
		break;
	case 2:
		printf("%d�� ¦���Դϴ�.", one);
		break;
	default:
		break;
	}

	printf("3. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &one);
	printf("%d�� ���밪 : %d", one , Three(one));

	printf("4. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &one);

	for (int i = 0; i <= one; i++)
	{
		if (Four(i) != 0 && i != one) 
		{
			printf("%d", i);
			printf(",");
		}
		if (i == one)
		{
			printf("\b ");
		}
	}

	printf("5. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &one);
	printf("%d�� �Ųٷ� �� : %d", one, Five(one));

}

int One(int one ,int two) 
{
	if (one >= two) 
	{
		return one;
	}
	else if(one <= two)
	{
		return two;
	}
}

int Two(int one)
{
	if (one % 2 !=0) 
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int Three(int one) 
{
	if (one < 0) 
	{
		return -one;
	}
	else
	{
		return one;
	}
}

int Four(int one)
{
	//3�ǹ�� 
	if (one%3 == 0)
	{
		return one;
	}
	else
	{
		return 0;
	}
}

int Five(int one) 
{
	int reverse = 0;

	for(; one > 0;)
	{
		reverse *= 10; //ó���� 0 *10�� 0�̴� �ڵ�����ó�� 
		if (one / 10 == 0) 
		{
			reverse += one % 10;
			break;
		}
		reverse += one % 10; //���� �ڸ� �־���
		one = one / 10;
	}
	return reverse;
}