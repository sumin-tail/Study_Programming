#include <stdio.h>

//반복문을 사용하는 최대 공약수 구하기
int One(int num1, int num2)
{
	//기본적으로 두 수를 나눴을때 나머지가 0이되는 약수를 찾아야함
	for (int i = 2; i <= num1 && i <= num2; i++)
	{
		if (num1%i == 0 && num2 % i == 0) //가장 작은 약수을 찾았으니
		{
			//나눈 값을 넣어서 다시 함수 호출...
			return i * One(num1 / i, num2 / i);
		}		
	}
	//두 수가 서로소가 된다면...
	return 1;
}


//반복문 없이 최대 공약수 구하기
//함수의 매개변수가 두개일 필요는 없다.
int Two(int num1, int num2, int max)
{
	if (max<= num1 && max<=num2)
	{
		if (num1 % max == 0 && num2 % max == 0)
		{
			return max * Two(num1/max, num2/max, max);
		}
		//안나눠진다
		return Two(num1, num2, max + 1);
	}

	return 1;
}

//재귀함수 최대공약수 구하기
//두 자연수의 공통된 약수 중 가장 큰 수
//약수 어떤 수를 나누어 나머지가 없이 떨어지는 수
//두 수가 서로 서로소가 될 떄까지 나눔 > 그 나눈 숫자들(약수)을 전부 곱함
void main()
{
	int num1, num2;
	int max = 2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &num1);

	printf("두번째 숫자 입력 : ");
	scanf("%d", &num2);

	//printf("두 수의 최대공약수 :%d", One(num1, num2));
	printf("두 수의 최대공약수 :%d", Two(num1, num2, max));
}
