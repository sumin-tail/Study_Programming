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
	int count = 0;// 찾은수
	char check[256]; //문장담는용

	FILE* f = fopen("Alice.txt", "r");

	while (!feof(f))//파일의 끝에 도달할때까지 돌림
	{
		fgets(check, sizeof(check), f); //문장을 담음(엔터기준으로 자름)
		count = Strcmp(check, findword, count);  //담은 문장을 찾을 단어(문장)와 함께 Strcmp에 전송
	}

	fclose(f);
	return count;
}


void main()
{
	char findword[30];

	//읽기모드로 파일 가져옴
	FILE* f = fopen("Alice.txt", "r");
	char buf[256];
	if (f == NULL)
	{
		printf("해당 이름의 파일이 없습니다.");
	}
	else
	{
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f); //한줄씩 프린터! 
			//한번에 전체를 가져오기에는 buf의 용량이 매우 커야함....
			printf("%s", buf);
		}
	}
	//여기까지 파일 전체출력
	fclose(f);

	printf("Check Word Input : ");
	scanf("%s", findword); //찾을 단어 입력
	printf("KPM Check %s Count : %d\n", findword, WordCheck(findword));
	system("pause");
}
