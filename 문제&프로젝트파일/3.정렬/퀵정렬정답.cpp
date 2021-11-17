#include<stdio.h>

#define MAX_SIZE 8
#define ASENDING 1
#define DESENDING 2

void Swap(int* n1, int* n2) //스왑을 함수로 만듬
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int Patition(int Array[], int left, int right, int Type)
{
	int pivot = Array[right];
	int low = left;
	int high = right - 1;
	while (low <= high)
	{
		switch (Type)
		{
		case ASENDING:
			while (Array[low] <= pivot && low <= right - 1) low++;
			while (Array[high] >= pivot && high >= left) high--;
			break;
		case DESENDING:
			while (Array[low] >= pivot && low <= right - 1) low++;
			while (Array[high] <= pivot && high >= left) high--;
			break;
		}
		if (low <= high) Swap(&Array[low], &Array[high]);//만약 low와 high의 위치가 서로 교차되지 않았을 경우 둘의 값을 바꿈
	}
	Swap(&Array[right], &Array[low]);//아니라면 둘의 교차가 이루어졌다는 뜻이니 피봇과 로우의 위치를 바꿈
	return low; //로우의 값을 반환함 => 정렬이 왼료된 자리임
}

void QuizSort(int Array[], int left, int right, int Type)
{
	if (left <= right)
	{
		int pivot = Patition(Array, left, right, Type);//정렬이 완료된 피봇(자리)을 받아옴
		QuizSort(Array, left, pivot - 1, Type);//왼쪽 - 피봇을 기준으로 -1
		QuizSort(Array, pivot + 1, right, Type);//오른쪽 - 피봇을 기준으로 +1
	}
}

void ShowArray(int Array[], int Size)//배열 출력 함수
{
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d,", Array[i]);
	printf("\b \n");
}

void main()
{
	int Array[MAX_SIZE] = { 9,10,2,11,5,3,12,8 };
	QuizSort(Array, 0, MAX_SIZE - 1, DESENDING);
	ShowArray(Array, MAX_SIZE);
}