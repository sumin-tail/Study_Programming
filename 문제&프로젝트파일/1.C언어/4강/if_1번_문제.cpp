#include<stdio.h>

void main()
{
	int Kor, Eng, Math;
	float Avg;
	printf("1�� ����\n");
	printf("�������� ������ �Է��Ͻÿ�\n");
	printf("���� ���� : ");
	scanf("%d", &Kor);
	printf("���� ���� : ");
	scanf("%d", &Math);
	printf("���� ���� : \n");
	scanf("%d", &Eng);
	Avg = (float)(Eng + Kor + Math) / 3.0;

	printf("\n���� ���� : %d\t���� ���� : %d\t\t���� ���� : %d\n", Kor ,Math, Eng);
	printf("���� ���� : %d\t", Kor+Math+Eng);
	printf("��� ���� : %.2f\t", Avg);

	if (Avg >= 90)
		printf("��� : A");
	else if (Avg >= 80)
		printf("��� : B");
	else if (Avg >= 70)
		printf("��� : C");
	else if (Avg >= 60)
		printf("��� : D");
	else
		printf("��� : F");

}
