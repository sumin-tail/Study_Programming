#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");//������� ��
	int Num;
	fprintf(f, "1 2 3 4"); //���Ͽ� �ڷ��߰���
	fclose(f); //����(�ݿ�)

	f = fopen("Test.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		while (!feof(f))
		{
			fscanf(f, "%d", &Num);
			printf("%d", Num);
		}
		fclose(f);
	}

}
