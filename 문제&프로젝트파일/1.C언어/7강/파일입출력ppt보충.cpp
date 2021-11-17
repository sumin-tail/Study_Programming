#include<stdio.h>

void Wite() 
{
	FILE* f = fopen("Test.txt", "w"); //fopen() > 파일을 여는 함수 확장자까지
	int Num = 123;
	fprintf(f, "덮어 쓰기 모드  %d", Num); //어느파일에 저장할것인지
	fclose(f); //열린파일 닫아주기 파일을 안닫으면 반영이안됨
}

void Add() 
{
	FILE* f = fopen("Test.txt", "a");
	int Num = 123;
	fprintf(f, "추가 모드  %d", Num);
	fclose(f);
}

typedef struct people
{
	char Name[10];
	int Age;
	char PhonNumber[20];
}People;

void Read() 
{
	FILE* f = fopen("Test.txt", "w");//쓰기모드로 염
	int Num;
	fprintf(f, "1 2 3 4"); //파일에 자료추가함
	fclose(f); //닫음(반영)

	f = fopen("Test.txt", "r");
	if (f == NULL)//예외처리 잊지말기
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f)) //feof는 파일엔드오브 >파일의 끝에 도착했을때 참을 반환하는 함수
		{
			fscanf(f, "%d", &Num);//정보를 구분하는 방식이 띄어쓰기와 엔터 단위임  > 그래서 1... 2... 3... 4.. 하나씩 가져옴
			//그래서 출력이 1234로 나옴
			printf("%d", Num);
		}
		fclose(f);
	}
}

void Read2() 
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	fprintf(f, "%s %d %s", P1.Name, P1.Age, P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fscanf(f, "%s", P1.Name); //fscanf는 띄어쓰기 또는 엔터 단위로 정보를 가져옴
		fscanf(f, "%d", &P1.Age);
		fscanf(f, "%s", P1.PhonNumber);
		printf("이름 : %s \n나이 : %d \n", P1.Name, P1.Age);
		printf("휴대폰번호 : %s\n", P1.PhonNumber);
		fclose(f);
	}
}

void Read3()
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256];
	fprintf(f, "이름 : %s나이 : %d\n", P1.Name, P1.Age);
	fprintf(f, "휴대폰 번호 : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f); //fgets 는 엔터 단위로 정보를 가져옴 
			//어디에 저장할거냐 /얼만큼 저장할수있냐(사이즈) / 어디에서 가져올것이냐 
			printf("%s\n", buf);
		}
		fclose(f);
	}
}
// fprintf : 파일의 내용 출력 > 파일에 쓰는 것(저장)
// fscanf : 파일의 내용 입력 > 파일의 내용을 들고오는 것(읽기)

void main()
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256] = {0}; //2.일일이 문자열을 체크하고 맨마지막에 널을 넣는것은 너무 복잡함.
	//그러니 미리 널로 초기화를 하자
	fprintf(f, "이름 : %s나이 : %d\n", P1.Name, P1.Age);
	fprintf(f, "휴대폰 번호 : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fread(buf, sizeof(buf), 1, f); //1.fread 유일하게 NULL을 안넣어줌 2번을 하지않고 그냥 실행시켰을 경우 빈자리만큼 쓰레기값이 출력이 됨
		printf("%s\n", buf);
	}
	fclose(f);
}

