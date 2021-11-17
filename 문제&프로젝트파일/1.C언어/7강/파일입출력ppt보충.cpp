#include<stdio.h>

void Wite() 
{
	FILE* f = fopen("Test.txt", "w"); //fopen() > ������ ���� �Լ� Ȯ���ڱ���
	int Num = 123;
	fprintf(f, "���� ���� ���  %d", Num); //������Ͽ� �����Ұ�����
	fclose(f); //�������� �ݾ��ֱ� ������ �ȴ����� �ݿ��̾ȵ�
}

void Add() 
{
	FILE* f = fopen("Test.txt", "a");
	int Num = 123;
	fprintf(f, "�߰� ���  %d", Num);
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
	FILE* f = fopen("Test.txt", "w");//������� ��
	int Num;
	fprintf(f, "1 2 3 4"); //���Ͽ� �ڷ��߰���
	fclose(f); //����(�ݿ�)

	f = fopen("Test.txt", "r");
	if (f == NULL)//����ó�� ��������
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		while (!feof(f)) //feof�� ���Ͽ������ >������ ���� ���������� ���� ��ȯ�ϴ� �Լ�
		{
			fscanf(f, "%d", &Num);//������ �����ϴ� ����� ����� ���� ������  > �׷��� 1... 2... 3... 4.. �ϳ��� ������
			//�׷��� ����� 1234�� ����
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
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		fscanf(f, "%s", P1.Name); //fscanf�� ���� �Ǵ� ���� ������ ������ ������
		fscanf(f, "%d", &P1.Age);
		fscanf(f, "%s", P1.PhonNumber);
		printf("�̸� : %s \n���� : %d \n", P1.Name, P1.Age);
		printf("�޴�����ȣ : %s\n", P1.PhonNumber);
		fclose(f);
	}
}

void Read3()
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256];
	fprintf(f, "�̸� : %s���� : %d\n", P1.Name, P1.Age);
	fprintf(f, "�޴��� ��ȣ : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f); //fgets �� ���� ������ ������ ������ 
			//��� �����Ұų� /��ŭ �����Ҽ��ֳ�(������) / ��𿡼� �����ð��̳� 
			printf("%s\n", buf);
		}
		fclose(f);
	}
}
// fprintf : ������ ���� ��� > ���Ͽ� ���� ��(����)
// fscanf : ������ ���� �Է� > ������ ������ ������ ��(�б�)

void main()
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256] = {0}; //2.������ ���ڿ��� üũ�ϰ� �Ǹ������� ���� �ִ°��� �ʹ� ������.
	//�׷��� �̸� �η� �ʱ�ȭ�� ����
	fprintf(f, "�̸� : %s���� : %d\n", P1.Name, P1.Age);
	fprintf(f, "�޴��� ��ȣ : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		fread(buf, sizeof(buf), 1, f); //1.fread �����ϰ� NULL�� �ȳ־��� 2���� �����ʰ� �׳� ��������� ��� ���ڸ���ŭ �����Ⱚ�� ����� ��
		printf("%s\n", buf);
	}
	fclose(f);
}

