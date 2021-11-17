#include<stdio.h>

#define MAX_SIZE 8
#define ASENDING 1
#define DESENDING 2

void Swap(int* n1, int* n2) //������ �Լ��� ����
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
		if (low <= high) Swap(&Array[low], &Array[high]);//���� low�� high�� ��ġ�� ���� �������� �ʾ��� ��� ���� ���� �ٲ�
	}
	Swap(&Array[right], &Array[low]);//�ƴ϶�� ���� ������ �̷�����ٴ� ���̴� �Ǻ��� �ο��� ��ġ�� �ٲ�
	return low; //�ο��� ���� ��ȯ�� => ������ �޷�� �ڸ���
}

void QuizSort(int Array[], int left, int right, int Type)
{
	if (left <= right)
	{
		int pivot = Patition(Array, left, right, Type);//������ �Ϸ�� �Ǻ�(�ڸ�)�� �޾ƿ�
		QuizSort(Array, left, pivot - 1, Type);//���� - �Ǻ��� �������� -1
		QuizSort(Array, pivot + 1, right, Type);//������ - �Ǻ��� �������� +1
	}
}

void ShowArray(int Array[], int Size)//�迭 ��� �Լ�
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