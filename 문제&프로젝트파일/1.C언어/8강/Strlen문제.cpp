#include<stdio.h>
#include<string.h>


int Strlen(char str[])
{
	//for문으로 적었으면 더 좋았을 것
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
	printf("(최대 19글자)문자열 입력 : ");
	scanf("%s", str);
	printf("%s문자열의 길이 : %d", str, Strlen(str));
}
