#include<stdio.h>

void main()
{
	int Kor, Eng, Math;
	float Avg;
	printf("1번 문제\n");
	printf("세과목의 점수를 입력하시오\n");
	printf("국어 점수 : ");
	scanf("%d", &Kor);
	printf("수학 점수 : ");
	scanf("%d", &Math);
	printf("영어 점수 : \n");
	scanf("%d", &Eng);
	Avg = (float)(Eng + Kor + Math) / 3.0;

	printf("\n국어 점수 : %d\t수학 점수 : %d\t\t영어 점수 : %d\n", Kor ,Math, Eng);
	printf("총합 점수 : %d\t", Kor+Math+Eng);
	printf("평균 점수 : %.2f\t", Avg);

	if (Avg >= 90)
		printf("등급 : A");
	else if (Avg >= 80)
		printf("등급 : B");
	else if (Avg >= 70)
		printf("등급 : C");
	else if (Avg >= 60)
		printf("등급 : D");
	else
		printf("등급 : F");

}
