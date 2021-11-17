#include<stdio.h>

void main() {
	/*
	배열을 이용한 정렬
	선택 정렬(Selection sort)
	맨 앞의 데이터부터 순차적으로 정렬하는 방식
	*/
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp; //임시저장변수
	int len = sizeof(arr) / sizeof(int);
	//swap : 데이터교환
	/*
	tmp = arr[0];//tmp변수에 덮어씌어질 데이터를 백업
	arr[0] = arr[2];
	arr[2] = tmp;
	*/
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			//왼쪽인덱스의 데이터가 오른쪽 인덱스의 데이터보다 크면 swap해줘야되
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}