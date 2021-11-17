#include<stdio.h>

void Add(FILE *f)
{
	for (int i = 2; i <= 9; i++)
	{
		fprintf(f,"=======%d단=======\n", i);
		for (int j = 1; j <= 9; j++)
		{
			fprintf(f,"%d x %d = %d\t", i, j, i * j);
			fprintf(f,"\n");
		}
		fprintf(f, "=================\n\n");
	}

}

// fprintf : 파일의 내용 출력 > 파일에 쓰는 것(저장)
// fscanf : 파일의 내용 입력 > 파일의 내용을 들고오는 것(읽기)

void main()
{
	FILE* f = fopen("GoGoDan.txt", "w");  // 파일이 없으면 새로 만들고 이미있는 경우에는 싹다지움
	Add(f);
	fclose(f); //파일을 닫는것을 잊지말자
}

