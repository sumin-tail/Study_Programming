#include<stdio.h>
#include<string.h>


void Strcat(char* str1, char* str2)
{
	int i; //나중에 널문자 넣어주는 용이라서 for밖에

	for (i = 0; str1[i] != 0; i++); //str1문자열의 널문자를 찾을떄까지 

	for (int j = 0; str2[j] != 0; i++,j++)
	{
		str1[i] = str2[j]; //찾은 널문자가있는 위치부터 넣을 문자열을 추가 
		//하나넣었으면 둘다 다음으로 건너가야하므로 증감식은 i와j 둘다 
	}

	str1[i] = NULL; //마지막에 널문자 안넣어주면 쓰레기값나옴
}

void main()
{
	char str1[20], str2[20];
	printf("(최대 19글자)문자열 입력 : ");
	scanf("%s", str1);
	printf("(최대 19글자)추가 문자열 입력 : ");
	scanf("%s", str2);
	Strcat(str1, str2);
	printf("%s\n", str1);
}
