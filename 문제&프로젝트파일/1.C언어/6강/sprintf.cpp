#include<stdio.h>

void main()
{
	char buf[40];
	int age = 20;
	char Name[10] = "����ȣ";
	//buf(�迭)���� ���ڿ��� ���� 
	sprintf(buf, "%s���� ���̴� %d�� �Դϴ�.", Name, age); //�̰� �� ��ü�� ��������� ����
	printf("%s", buf);
}
