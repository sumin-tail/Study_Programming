#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Menu()
{
	printf("1.��ȣ ����\n");
	printf("2.�������� ����\n");
	printf("3.�������� ����\n");
	printf("4.����\n");
	printf("���� : ");
}

void CreateNum(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void PrintNum(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d �� �� : %d\n", i, arr[i]);
	}
}

//��������
void Ascending(int arr[], int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//��������
void Descending(int arr[], int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

void main()
{
	srand(time(NULL));

	int select;
	int arr[10];
	int length = sizeof(arr) / sizeof(int);

	while (1)
	{
		system("cls");
		Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1: //�����
			CreateNum(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 2: //����
			Ascending(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 3: //����
			Descending(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 4: //����
			return;
		}
	}

}