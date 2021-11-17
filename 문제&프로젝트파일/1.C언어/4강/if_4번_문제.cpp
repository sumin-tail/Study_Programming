#include<stdio.h>
//if_4번_문제
void main()
{
	int num;
	printf("구매할 디스켓 갯수를 입력하시오 : ");
	scanf("%d", &num);
	if (num >= 100)
		printf("디스크 %d개 가격 : %d원", num, (int)((num * 5000)*0.88));
	else if (num >= 10)
		printf("디스크 %d개 가격 : %d원", num, (int)((num*5000) * 0.9));
	else
		printf("디스크 %d개 가격 : %d원", num, num * 5000);
}