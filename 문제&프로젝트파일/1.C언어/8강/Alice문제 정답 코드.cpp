#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<string.h>

int KMPCheck(char buf[], char Check[], int Size)
{
	//Size / 2함 > i번쨰와 Size-i번째를 동시에 계산하기 때문에(한번에 2개씩)
	for (int i = 0; i <= Size / 2; i++)//i
	{ 
		//만약 buf[i]와  Check[i]가 같지 않거나(||) buf[Size - i]과 Check[Size - i]가 같지 않을 경우 둘은 같지 않다
		if (buf[i] != Check[i] || buf[Size - i] != Check[Size - i]) // 맨 처음과 맨 끝 부분을 동시에 비교한다. > 처음+1 과 끝-1 을 동시에 비교 
			return 0;
	}
	return 1;
}

void KMPSearch(char buf[], char Check[], int Size)
{
	//찾은 갯수
	int count = 0;

	for (int i = 0; buf[i] != NULL; i++) //NULL이 나올때까지 돌림 > 책의 내용 끝까지
	{
		//만약 찾아야 하는 단어 0 번째와 buf의 i번째 시작단어가 같고 (&&) 찾아야 하는 단어 마지막과 buf[i + Size - 1]의 마지막 단어가 같을경우 
		if (Check[0] == buf[i] && Check[Size - 1] == buf[i + Size - 1])
		{
			//첫번쨰 단어는 체크했으니 바로 두번째 단어부터 &buf[i + 1], &Check[1] < 검증
			//Size에서 3을 빼는 이유는 > 첫번째단어(-1)와 마지막 단어(-1)는 검증할 필요가 없음. 
			//남은 -1 은? 
			//자세한 설명 >>
			//만약 배열의 사이즈가 5라면 0 1 2 3 4 , 0 과 4를 제외 > 1 2 3 부분을 체크해야 함
			//KMPCheck 함수에 넘길때 &Check[1] 의 상태로 넘김 > KMPCheck 함수에서는 Check[i](i=0) 부터 시작  
            // >왜 0 부터 시작하는가? i번쨰(처음)와 Size-i(마지막)번째를 동시에 비교하기 때문에 스타트가 0이여야만 함
			//그렇다면 실질적으로 KMPCheck 함수에서는 0 1 2 < 부분을 체크해야함 (배열의 인덱스는 사이즈의 -1이다)  > 그래서 총합 -3
			if (KMPCheck(&buf[i + 1], &Check[1], Size - 3) == 1)  
			{
				count++;
				i += (Size - 1);// 체크가 끝난 단어의 사이즈-1 만큼 인덱스 넘김
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
		printf("해당 이름의 파일이 없습니다.\n");
		return;
	}
	else
	{
		fread(buf, sizeof(buf), 1, f);
		fclose(f);
	}
	printf("%s", buf); //buf에 책내용을 다 담음
	char Check[256];
	printf("Check Word Input : ");
	scanf("%s", Check);
	KMPSearch(buf, Check, strlen(Check));
}