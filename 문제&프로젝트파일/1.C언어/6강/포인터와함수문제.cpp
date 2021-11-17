#include<stdio.h>

#define LENGHT 8

void One(char* str);
void Two(int* num1, int* num2, int* high);
void Three(int* num1, int* max);
void Four(int* arr);


void main()
{
	char str[100];
	int num1;
	int num2;
	int high;
	int max=0;
	int arr[LENGHT];

	printf("1. 문자열을 입력하시오 : ");
	scanf("%s", str);
	printf("함수 호출 전 = %s\n",str);
	One(str);
	printf("함수 호출 후 = %s\n",str);

	printf("\n");

	printf("2. 두 정수를 입력하시오 : ");
	scanf("%d", &num1);
	scanf("%d", &num2);
	Two(&num1, &num2, &high);
	printf("%d와(과) %d중 큰 수는 %d", num1, num2, high);

	printf("\n");

	printf("3. 정수를 입력하시오 : ");
	scanf("%d", &num1);
	Three(&num1, &max);
	printf("1 ~ %d 의 총 합 : %d", num1, max);

	printf("\n");

	printf("4. 오름차순 정렬\n");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("[%d]번째 정수 입력 : ", i);
		scanf("%d", &arr[i]);
	}
	printf("정렬 전 : ");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("%d ", arr[i]);
	}
	Four(arr);
	printf("\n정렬 후 : ");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("%d ", arr[i]);
	}
}

void One(char* str)
{
	//문자열의 마지막에는 NULL이 있음
	for (int i = 0; str[i] != NULL; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

void Two(int *num1, int *num2, int *high)
{
	if (*num1 > *num2)
	{
		*high = *num1;
	}
	else
	{
		*high = *num2;
	}
}

void Three(int* num1, int* max)
{
	for (int i = 1; i <= *num1; i++)
	{
		*max += i;
	}
}

void Four(int *arr) 
{
	int tmp;
	for (int i = 0; i < LENGHT; i++)
	{
		for (int j = i+1; j < LENGHT; j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}