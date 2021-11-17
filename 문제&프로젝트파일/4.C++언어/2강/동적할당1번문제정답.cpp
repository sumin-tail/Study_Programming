#include<iostream>
using namespace std;
#define INTMAX 5

void Asc(int* arr)
{
	int tmp;
	for (int i = 0; i < INTMAX - 1; i++)
	{
		for (int j = i + 1; j < INTMAX; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void main()
{
	int* arr;
	arr = new int[INTMAX];
	for (int i = 0; i < INTMAX; i++)
	{
		cout << i + 1 << "번째 정수 : ";
		cin >> arr[i];
	}
	cout << "오름차순 정렬전" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < INTMAX; i++)
		cout << i + 1 << "번째 정수 : " << arr[i] << endl;
	cout << "====================" << endl << endl;

	Asc(arr);

	cout << "오름차순 정렬후" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < INTMAX; i++)
		cout << i + 1 << "번째 정수 : " << arr[i] << endl;
	cout << "====================" << endl << endl;
	delete[] arr;
}