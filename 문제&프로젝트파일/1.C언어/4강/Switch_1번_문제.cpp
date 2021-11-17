#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")
//조건문
void main()
{
	int Select;
	char name[10];
	int Kor, Eng, Math;
	float Avg;

	//확인용
	bool nameflag=0;
	bool pointflag=0;
	while (1)
	{
		system("cls");
		printf("================\n");
		printf("학생 성적관리\n");
		printf("================\n");
		printf("1.학생 이름등록\n");
		printf("2.3과목 점수등록\n");
		printf("3.점수 확인\n");
		printf("4.종료\n");
		printf("================\n");
		printf("입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			system("cls");
			printf("이름 입력 : ");
			scanf("%s", name);
			nameflag = 1;
			break;
		case 2:
			system("cls");
			printf("세과목의 성적를 입력하시오\n");
			printf("국어 : ");
			scanf("%d", &Kor);
			printf("수학 : ");
			scanf("%d", &Math);
			printf("영어 : ");
			scanf("%d", &Eng);
			pointflag = 1;
			break;
		case 3:
			if (pointflag&&nameflag)
			{
				system("cls");
				printf("================\n");
				printf("%s님의 점수\n", name);
				printf("국어 점수 : %d\n수학 점수 : %d\n영어 점수 : %d\n", Kor, Math, Eng);
				printf("총합 점수 : %d\n", Kor + Math + Eng);
				Avg = (float)(Eng + Kor + Math) / 3.0f;
				printf("평균 점수 : %.2f\n", Avg);
				printf("================\n");
				system("pause");
				break;
			}
			else if (nameflag) 
			{
				system("cls");
				printf("점수를 입력하세요\n");
				system("pause");
				break;
			}
			else if (pointflag) 
			{
				system("cls");
				printf("이름을 입력하세요\n");
				system("pause");
				break;
			}
			else
			{
				system("cls");
				printf("점수를 입력하세요\n");
				printf("이름을 입력하세요\n");
				system("pause");
				break;
			}
		case 4:
			return;
		}
	}
}
