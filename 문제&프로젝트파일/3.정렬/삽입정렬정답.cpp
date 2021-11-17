#include<stdio.h>

void main() {
	/*
	삽입정렬(insert sort)
	값이 있어야할 위치를 찾아가면서 정렬하는 방식
	*/
	int arr[5] = { 4,8,2,7,6 };
	int tmp;
	int len = sizeof(arr) / sizeof(int);
	/*
	i변수가 arr[1]에서 시작 j변수는 arr[0]부터 시작
	j가 i앞까지 증가하면서 비교
	i앞의 요소들과 i와 비교를 해서 앞의 요소가 더 크면 swap
	*/
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}