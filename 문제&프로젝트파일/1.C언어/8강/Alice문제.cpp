#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

int Strcmp(char check[], char* findword, int count)
{
	for (int i = 0; check[i] != NULL; i++)
	{
		for (int j = 0, c = i; check[c] == findword[j]; c++, j++)
		{
			if (findword[j + 1] == NULL)
			{
				count++;
			}
		}
	}
	return count;
}

// in
// @@@i not

int WordCheck(char* findword)
{
	int count = 0;// ã����
	char check[256]; //�����¿�

	FILE* f = fopen("Alice.txt", "r");

	while (!feof(f))//������ ���� �����Ҷ����� ����
	{
		fgets(check, sizeof(check), f); //������ ����(���ͱ������� �ڸ�)
		count = Strcmp(check, findword, count);  //���� ������ ã�� �ܾ�(����)�� �Բ� Strcmp�� ����
	}

	fclose(f);
	return count;
}


void main()
{
	char findword[30];

	//�б���� ���� ������
	FILE* f = fopen("Alice.txt", "r");
	char buf[256];
	if (f == NULL)
	{
		printf("�ش� �̸��� ������ �����ϴ�.");
	}
	else
	{
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f); //���پ� ������! 
			//�ѹ��� ��ü�� �������⿡�� buf�� �뷮�� �ſ� Ŀ����....
			printf("%s", buf);
		}
	}
	//������� ���� ��ü���
	fclose(f);

	printf("Check Word Input : ");
	scanf("%s", findword); //ã�� �ܾ� �Է�
	printf("KPM Check %s Count : %d\n", findword, WordCheck(findword));
	system("pause");
}
