#include<stdio.h>
//if_3번_문제
void main()
{
	int num;
	printf("구매할 도시락 갯수를 입력하시오 : ");
	scanf("%d", &num);
	if (num > 10)
		printf("도시락 %d개 가격 : %d원", num , 25000+(num-10)*2400);
	else
		printf("도시락 %d개 가격 : %d원", num, num*2500);

}