#include <stdio.h>
void main() {
	// 배열 초기화
	int arr[5] = { 2, 7, 1, 3, 4 };
	int len = sizeof(arr) / sizeof(int);
	// Bubble Sort는 데이터의 개수-1 만큼 바깥쪽 반복문이 반복한다.(현재는 4번)
	for (int i = 0; i < len - 1; i++) {
		// j는 len - i - 1까지 반복한다.(4번 >> 3번 >> 2번 >> 1번)
		for (int j = 0; j < len - i - 1; j++) {
			// j의 오른쪽 자리와 값을 비교를 하여 오른쪽 자리의 값이 작으면 교환한다.
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}