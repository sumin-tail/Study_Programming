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

	printf("1. ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", str);
	printf("�Լ� ȣ�� �� = %s\n",str);
	One(str);
	printf("�Լ� ȣ�� �� = %s\n",str);

	printf("\n");

	printf("2. �� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num1);
	scanf("%d", &num2);
	Two(&num1, &num2, &high);
	printf("%d��(��) %d�� ū ���� %d", num1, num2, high);

	printf("\n");

	printf("3. ������ �Է��Ͻÿ� : ");
	scanf("%d", &num1);
	Three(&num1, &max);
	printf("1 ~ %d �� �� �� : %d", num1, max);

	printf("\n");

	printf("4. �������� ����\n");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("[%d]��° ���� �Է� : ", i);
		scanf("%d", &arr[i]);
	}
	printf("���� �� : ");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("%d ", arr[i]);
	}
	Four(arr);
	printf("\n���� �� : ");
	for (int i = 0; i < LENGHT; i++)
	{
		printf("%d ", arr[i]);
	}
}

void One(char* str)
{
	//���ڿ��� ���������� NULL�� ����
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