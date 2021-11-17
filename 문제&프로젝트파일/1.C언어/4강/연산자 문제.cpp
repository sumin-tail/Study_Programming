#include<stdio.h>

void main()
{
	int Num1;
	int Num2;
	int Num3;

	float fnum;

	printf("1.정수를 입력하시오 : ");
	scanf("%d" , &Num1); 
	(Num1%5) ? printf("%d 는 5의 배수가 아닙니다\n", Num1) : printf("%d 는 5의 배수입니다\n", Num1);

	printf("2.세 과목의 점수를 입력하시오\n");
	printf("국어 점수 : ");
	scanf("%d", &Num1);
	printf("수학 점수 : ");
	scanf("%d", &Num2);
	printf("영어 점수 : ");
	scanf("%d", &Num3);
	fnum = (float)(Num1 + Num2 + Num3)/3;
	(fnum >=60) ? printf("평균 %.2f 합격\n", fnum) : printf("평균 %.2f 불합격\n", fnum);
	printf("3.두 정수를 입력하시오 : ");
	scanf("%d %d", &Num1, &Num2);
	(Num1 > Num2) ? printf("큰 수 : %d\n", Num1) : printf("큰 수 : %d\n", Num2);

	printf("4.정수를 입력하시오 : ");
	scanf("%d" , &Num1);
	(Num1%3==0 && Num1%2==0) ? printf("%d 는 3의 배수이며 짝수입니다.\n", Num1) : printf("조건 실패\n", Num1);

	printf("5.정수를 입력하시오 : ");
	scanf("%d", &Num1);
	(Num1%5 ==0 || Num1 % 7 ==0) ? printf("%d 는 5의 배수거나 7의 배수입니다.\n", Num1) : printf("조건 실패\n", Num1);
}
