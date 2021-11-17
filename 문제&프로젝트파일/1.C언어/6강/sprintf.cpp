#include<stdio.h>

void main()
{
	char buf[40];
	int age = 20;
	char Name[10] = "최정호";
	//buf(배열)에다 문자열을 저장 
	sprintf(buf, "%s님의 나이는 %d살 입니다.", Name, age); //이건 그 자체로 출력하지는 않음
	printf("%s", buf);
}
