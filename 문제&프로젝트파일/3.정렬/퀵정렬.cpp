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

//재귀함수를 사용할 것!!
//low와 high의 자리가 서로 바뀌었을때 pivot의 값과 high의 값을 스왑
//low와 high의 자리가 서로 바뀌지 않았다면 low와 high의 값을 스왑

//오름차순
void Ascending(int arr[], int start, int end)//스타트는 배열의 첫번째(0) end는 배열의 마지막(메인에서 보낼때 길이-1 할것)
{
	int temp;
	int low = start;
	int high = end - 1; //배열의 끝 값은 피봇값으로 쓸것
	int pivot = arr[end];//배열 맨 오른쪽의 값이 피봇값임

	if (start >= end)//배열의 크기가 1일경우 리턴
	{
		return;
	}

	while (low <= high)//둘의 위치가 바뀌지 않을 동안
	{
		while (arr[low] <= pivot && low < end)
		{
			low++;
		}
		while (arr[high] >= pivot && high >= start)
		{
			high--;
		}
		//만약에 low보다 high의 값이 작다면 == 스왑이 되었다는 뜻
		if (low < high)//아니라면 low와 high교체
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[low];
	arr[low] = pivot;
	arr[end] = temp;
	//로우의 값과 피봇의 값을 바꿨으니
	//왼쪽
	Ascending(arr, start, low-1);
	//오른쪽
	Ascending(arr, low+1, end);
}

//내림차순
void Descending(int arr[], int start, int end)
{
	int temp;
	int low = start;
	int high = end - 1;
	int pivot = arr[end];

	if (start >= end)
	{
		return;
	}

	while (low < high)
	{
		while (arr[low] >= pivot && low < end)
		{
			low++;
		}
		while (arr[high] <= pivot && high >= start)
		{
			high--;
		}

		if (low > high)
		{
			temp = arr[low];
			arr[low] = arr[end];
			arr[end] = temp;
		}
		else
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	//로우의 값과 피봇의 값을 바꿨으니
	//왼쪽
	Descending(arr, start, low - 1);
	//오른쪽
	Descending(arr, low + 1, end);
}

void main()
{
	srand(time(NULL));

	int select;
	int num;
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
			Ascending(arr, 0, length-1);
			PrintNum(arr, length);
			system("pause");
			break;
		case 3: //내림
			Descending(arr, 0, length-1);
			PrintNum(arr, length);
			system("pause");
			break;
		case 4: //종료
			return;
		}
	}

}