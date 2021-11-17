#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<string.h>

int KMPCheck(char buf[], char Check[], int Size)
{
	//Size / 2�� > i������ Size-i��°�� ���ÿ� ����ϱ� ������(�ѹ��� 2����)
	for (int i = 0; i <= Size / 2; i++)//i
	{ 
		//���� buf[i]��  Check[i]�� ���� �ʰų�(||) buf[Size - i]�� Check[Size - i]�� ���� ���� ��� ���� ���� �ʴ�
		if (buf[i] != Check[i] || buf[Size - i] != Check[Size - i]) // �� ó���� �� �� �κ��� ���ÿ� ���Ѵ�. > ó��+1 �� ��-1 �� ���ÿ� �� 
			return 0;
	}
	return 1;
}

void KMPSearch(char buf[], char Check[], int Size)
{
	//ã�� ����
	int count = 0;

	for (int i = 0; buf[i] != NULL; i++) //NULL�� ���ö����� ���� > å�� ���� ������
	{
		//���� ã�ƾ� �ϴ� �ܾ� 0 ��°�� buf�� i��° ���۴ܾ ���� (&&) ã�ƾ� �ϴ� �ܾ� �������� buf[i + Size - 1]�� ������ �ܾ ������� 
		if (Check[0] == buf[i] && Check[Size - 1] == buf[i + Size - 1])
		{
			//ù���� �ܾ�� üũ������ �ٷ� �ι�° �ܾ���� &buf[i + 1], &Check[1] < ����
			//Size���� 3�� ���� ������ > ù��°�ܾ�(-1)�� ������ �ܾ�(-1)�� ������ �ʿ䰡 ����. 
			//���� -1 ��? 
			//�ڼ��� ���� >>
			//���� �迭�� ����� 5��� 0 1 2 3 4 , 0 �� 4�� ���� > 1 2 3 �κ��� üũ�ؾ� ��
			//KMPCheck �Լ��� �ѱ涧 &Check[1] �� ���·� �ѱ� > KMPCheck �Լ������� Check[i](i=0) ���� ����  
            // >�� 0 ���� �����ϴ°�? i����(ó��)�� Size-i(������)��°�� ���ÿ� ���ϱ� ������ ��ŸƮ�� 0�̿��߸� ��
			//�׷��ٸ� ���������� KMPCheck �Լ������� 0 1 2 < �κ��� üũ�ؾ��� (�迭�� �ε����� �������� -1�̴�)  > �׷��� ���� -3
			if (KMPCheck(&buf[i + 1], &Check[1], Size - 3) == 1)  
			{
				count++;
				i += (Size - 1);// üũ�� ���� �ܾ��� ������-1 ��ŭ �ε��� �ѱ�
			}
		}
	}
	printf("KMP Check %s Count : %d\n", Check, count);
}


void main()
{
	char buf[300000] = { 0 };
	FILE* f = fopen("Alice.txt", "r");
	if (f == NULL)
	{
		printf("�ش� �̸��� ������ �����ϴ�.\n");
		return;
	}
	else
	{
		fread(buf, sizeof(buf), 1, f);
		fclose(f);
	}
	printf("%s", buf); //buf�� å������ �� ����
	char Check[256];
	printf("Check Word Input : ");
	scanf("%s", Check);
	KMPSearch(buf, Check, strlen(Check));
}