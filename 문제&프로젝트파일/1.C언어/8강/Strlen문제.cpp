#include<stdio.h>
#include<string.h>


int Strlen(char str[])
{
	//for������ �������� �� ������ ��
	int count = 0;
	while (str[count]!=NULL)
	{
		count++;
	}
	return count;
}

void main()
{
	char str[20];
	printf("(�ִ� 19����)���ڿ� �Է� : ");
	scanf("%s", str);
	printf("%s���ڿ��� ���� : %d", str, Strlen(str));
}
