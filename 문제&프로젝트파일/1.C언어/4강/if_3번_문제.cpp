#include<stdio.h>
//if_3��_����
void main()
{
	int num;
	printf("������ ���ö� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num);
	if (num > 10)
		printf("���ö� %d�� ���� : %d��", num , 25000+(num-10)*2400);
	else
		printf("���ö� %d�� ���� : %d��", num, num*2500);

}