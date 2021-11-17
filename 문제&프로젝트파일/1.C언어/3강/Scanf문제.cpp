#include<stdio.h>
void main()
{
	char ch;
	int num;

	float fnum;

	int k;
	int m;
	int e;

	char str[20];
	int age;

	printf("=====1번문제=====\n");
	printf("단일문자를 입력하시오 : ");
	scanf("%c", &ch);
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);
	printf("%c + %d = %c\n", ch, num, ch + num);

	printf("=====2번문제=====\n");
	printf("소숫점수를 입력하시오 : ");
	scanf("%f", &fnum);
	printf("소숫점수 : %.2f\n", fnum);

	printf("=====3번문제=====\n");
	printf("국어점수를 입력하시오 : ");
	scanf("%d", &k);
	printf("수학점수를 입력하시오 : ");
	scanf("%d", &m);
	printf("영어점수를 입력하시오 : ");
	scanf("%d", &e);
	printf("국어점수 : %d\n", k);
	printf("수학점수 : %d\n", m);
	printf("영어점수 : %d\n", e);
	printf("함계점수 : %d  평균점수 : %.2f\n", k+m+e, (float)(k + m + e)/3);

	printf("=====4번문제=====\n");
	printf("이름을 입력하시오 : ");
	scanf("%s", str);
	printf("%s님의 나이를 입력하시오 : ", str);
	scanf("%d", &age);
	printf("%s님의 나이는 %d세입니다." , str, age);
}
