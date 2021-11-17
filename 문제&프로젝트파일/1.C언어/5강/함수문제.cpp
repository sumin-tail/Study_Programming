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
	
	printf("1. 두 수를 입력 하시오 : ");
	scanf("%d %d", &one, &two);
	printf("%d와 %d중 큰수는 %d 입니다.", one ,two, One(one,two));

	printf("2. 정수 하나를 입력하시오 : ");
	scanf("%d", &one);
	switch (Two(one))
	{
	case 1:
		printf("%d는 홀수입니다.", one);
		break;
	case 2:
		printf("%d는 짝수입니다.", one);
		break;
	default:
		break;
	}

	printf("3. 정수 하나를 입력하시오 : ");
	scanf("%d", &one);
	printf("%d의 절대값 : %d", one , Three(one));

	printf("4. 정수 하나를 입력하시오 : ");
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

	printf("5. 정수 하나를 입력하시오 : ");
	scanf("%d", &one);
	printf("%d의 거꾸로 수 : %d", one, Five(one));

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
	//3의배수 
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
		reverse *= 10; //처음에 0 *10은 0이니 자동예외처리 
		if (one / 10 == 0) 
		{
			reverse += one % 10;
			break;
		}
		reverse += one % 10; //일의 자리 넣어줌
		one = one / 10;
	}
	return reverse;
}