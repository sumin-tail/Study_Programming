#include<stdio.h>
//if_4��_����
void main()
{
	int num;
	printf("������ ���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num);
	if (num >= 100)
		printf("��ũ %d�� ���� : %d��", num, (int)((num * 5000)*0.88));
	else if (num >= 10)
		printf("��ũ %d�� ���� : %d��", num, (int)((num*5000) * 0.9));
	else
		printf("��ũ %d�� ���� : %d��", num, num * 5000);
}