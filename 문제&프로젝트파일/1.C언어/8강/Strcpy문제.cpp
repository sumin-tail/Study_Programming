#include<stdio.h>
#include<string.h>


void Strcpy(char *str1, char* str2)
{
	int i;
	for (i = 0; str2[i] != 0; i++)
	{
		str1[i] = str2[i];
	}
	str1[i] = NULL; //마지막에널문자 안넣어주면 쓰레기값나옴
}

void main()
{
	char Name[10];
	char My_Name[10] = "JungHo";

	Strcpy(Name, My_Name);
	printf("Name : %s\n", Name);
	printf("My_Name : %s\n", My_Name);
}
