#include<stdio.h>

void main()
{
	int Num1;
	int Num2;
	int Num3;

	float fnum;

	printf("1.������ �Է��Ͻÿ� : ");
	scanf("%d" , &Num1); 
	(Num1%5) ? printf("%d �� 5�� ����� �ƴմϴ�\n", Num1) : printf("%d �� 5�� ����Դϴ�\n", Num1);

	printf("2.�� ������ ������ �Է��Ͻÿ�\n");
	printf("���� ���� : ");
	scanf("%d", &Num1);
	printf("���� ���� : ");
	scanf("%d", &Num2);
	printf("���� ���� : ");
	scanf("%d", &Num3);
	fnum = (float)(Num1 + Num2 + Num3)/3;
	(fnum >=60) ? printf("��� %.2f �հ�\n", fnum) : printf("��� %.2f ���հ�\n", fnum);
	printf("3.�� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &Num1, &Num2);
	(Num1 > Num2) ? printf("ū �� : %d\n", Num1) : printf("ū �� : %d\n", Num2);

	printf("4.������ �Է��Ͻÿ� : ");
	scanf("%d" , &Num1);
	(Num1%3==0 && Num1%2==0) ? printf("%d �� 3�� ����̸� ¦���Դϴ�.\n", Num1) : printf("���� ����\n", Num1);

	printf("5.������ �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	(Num1%5 ==0 || Num1 % 7 ==0) ? printf("%d �� 5�� ����ų� 7�� ����Դϴ�.\n", Num1) : printf("���� ����\n", Num1);
}
