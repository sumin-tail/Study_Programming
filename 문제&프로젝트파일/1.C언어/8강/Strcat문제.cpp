#include<stdio.h>
#include<string.h>


void Strcat(char* str1, char* str2)
{
	int i; //���߿� �ι��� �־��ִ� ���̶� for�ۿ�

	for (i = 0; str1[i] != 0; i++); //str1���ڿ��� �ι��ڸ� ã�������� 

	for (int j = 0; str2[j] != 0; i++,j++)
	{
		str1[i] = str2[j]; //ã�� �ι��ڰ��ִ� ��ġ���� ���� ���ڿ��� �߰� 
		//�ϳ��־����� �Ѵ� �������� �ǳʰ����ϹǷ� �������� i��j �Ѵ� 
	}

	str1[i] = NULL; //�������� �ι��� �ȳ־��ָ� �����Ⱚ����
}

void main()
{
	char str1[20], str2[20];
	printf("(�ִ� 19����)���ڿ� �Է� : ");
	scanf("%s", str1);
	printf("(�ִ� 19����)�߰� ���ڿ� �Է� : ");
	scanf("%s", str2);
	Strcat(str1, str2);
	printf("%s\n", str1);
}
