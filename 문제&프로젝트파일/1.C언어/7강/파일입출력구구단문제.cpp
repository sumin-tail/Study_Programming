#include<stdio.h>

void Add(FILE *f)
{
	for (int i = 2; i <= 9; i++)
	{
		fprintf(f,"=======%d��=======\n", i);
		for (int j = 1; j <= 9; j++)
		{
			fprintf(f,"%d x %d = %d\t", i, j, i * j);
			fprintf(f,"\n");
		}
		fprintf(f, "=================\n\n");
	}

}

// fprintf : ������ ���� ��� > ���Ͽ� ���� ��(����)
// fscanf : ������ ���� �Է� > ������ ������ ������ ��(�б�)

void main()
{
	FILE* f = fopen("GoGoDan.txt", "w");  // ������ ������ ���� ����� �̹��ִ� ��쿡�� �ϴ�����
	Add(f);
	fclose(f); //������ �ݴ°��� ��������
}

