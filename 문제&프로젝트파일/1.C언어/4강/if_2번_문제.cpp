#include<stdio.h>
//if_2번_문제
void main()
{
	int time;
	printf("승마 이용시간을 입력하시오 : ");
	scanf("%d", &time);
	if(time<=30)
		printf("%d분 탑승요금 : %d원", time ,3000);
	else if(time%10 == 0)
		printf("%d분 탑승요금 : %d원", time, ((time-30)/10)*500+3000 );
	else
		printf("%d분 탑승요금 : %d원", time, ((time - 30) / 10 * 500) + 3500);

}