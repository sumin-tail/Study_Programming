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

	printf("=====1������=====\n");
	printf("���Ϲ��ڸ� �Է��Ͻÿ� : ");
	scanf("%c", &ch);
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num);
	printf("%c + %d = %c\n", ch, num, ch + num);

	printf("=====2������=====\n");
	printf("�Ҽ������� �Է��Ͻÿ� : ");
	scanf("%f", &fnum);
	printf("�Ҽ����� : %.2f\n", fnum);

	printf("=====3������=====\n");
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &k);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &m);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &e);
	printf("�������� : %d\n", k);
	printf("�������� : %d\n", m);
	printf("�������� : %d\n", e);
	printf("�԰����� : %d  ������� : %.2f\n", k+m+e, (float)(k + m + e)/3);

	printf("=====4������=====\n");
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", str);
	printf("%s���� ���̸� �Է��Ͻÿ� : ", str);
	scanf("%d", &age);
	printf("%s���� ���̴� %d���Դϴ�." , str, age);
}
