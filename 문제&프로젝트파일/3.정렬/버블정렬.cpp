#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Menu()
{
	printf("1.번호 생성\n");
	printf("2.오름차순 정렬\n");
	printf("3.내림차순 정렬\n");
	printf("4.종료\n");
	printf("선택 : ");
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
		printf("%d 번 수 : %d\n", i, arr[i]);
	}
}

//오름차순
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

//내림차순
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
		case 1: //값등록
			CreateNum(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 2: //오름
			Ascending(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 3: //내림
			Descending(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 4: //종료
			return;
		}
	}

}