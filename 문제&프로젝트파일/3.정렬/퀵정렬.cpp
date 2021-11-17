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

//����Լ��� ����� ��!!
//low�� high�� �ڸ��� ���� �ٲ������ pivot�� ���� high�� ���� ����
//low�� high�� �ڸ��� ���� �ٲ��� �ʾҴٸ� low�� high�� ���� ����

//��������
void Ascending(int arr[], int start, int end)//��ŸƮ�� �迭�� ù��°(0) end�� �迭�� ������(���ο��� ������ ����-1 �Ұ�)
{
	int temp;
	int low = start;
	int high = end - 1; //�迭�� �� ���� �Ǻ������� ����
	int pivot = arr[end];//�迭 �� �������� ���� �Ǻ�����

	if (start >= end)//�迭�� ũ�Ⱑ 1�ϰ�� ����
	{
		return;
	}

	while (low <= high)//���� ��ġ�� �ٲ��� ���� ����
	{
		while (arr[low] <= pivot && low < end)
		{
			low++;
		}
		while (arr[high] >= pivot && high >= start)
		{
			high--;
		}
		//���࿡ low���� high�� ���� �۴ٸ� == ������ �Ǿ��ٴ� ��
		if (low < high)//�ƴ϶�� low�� high��ü
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[low];
	arr[low] = pivot;
	arr[end] = temp;
	//�ο��� ���� �Ǻ��� ���� �ٲ�����
	//����
	Ascending(arr, start, low-1);
	//������
	Ascending(arr, low+1, end);
}

//��������
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
	//�ο��� ���� �Ǻ��� ���� �ٲ�����
	//����
	Descending(arr, start, low - 1);
	//������
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
		case 1: //�����
			CreateNum(arr, length);
			PrintNum(arr, length);
			system("pause");
			break;
		case 2: //����
			Ascending(arr, 0, length-1);
			PrintNum(arr, length);
			system("pause");
			break;
		case 3: //����
			Descending(arr, 0, length-1);
			PrintNum(arr, length);
			system("pause");
			break;
		case 4: //����
			return;
		}
	}

}