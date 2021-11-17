#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");//쓰기모드로 염
	int Num;
	fprintf(f, "1 2 3 4"); //파일에 자료추가함
	fclose(f); //닫음(반영)

	f = fopen("Test.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f))
		{
			fscanf(f, "%d", &Num);
			printf("%d", Num);
		}
		fclose(f);
	}

}
