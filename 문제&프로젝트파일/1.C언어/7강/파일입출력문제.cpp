#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define MAX 50

typedef struct student
{
	char Name[10]; //�̸�
	int Age; //����
	int Class; //�г�
	int Number; //��ȣ
	char Gender[10]; //����
}Student;

//�л� ���
void ShowStudent(Student* St)
{
	printf("\t======%s�л�(%d��)======\n", St->Name, St->Number);
	printf("\t���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("\t========================\n");
}

//�л� ���
void SetStudent(Student* St, int* StudentCount)
{
	system("cls");
	St->Number = ++(*StudentCount);//��ġ=���ϰ� ���� �ش� �л��� ��ȣ�� ����(����) 
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է� : ");
	scanf("%s", St->Name); // (*P).Name �� P->Name �� ����
	printf("���� �Է� : ");
	scanf("%d", &St->Age);
	printf("���� �Է� : ");
	scanf("%s", St->Gender);
	printf("�г� �Է�<1~3> : ");
	scanf("%d", &St->Class); //�г��� �г��� �߸��Է��������� �Ʒ����� ����
	while (St->Class < 1 || St->Class > 3) //1���ϰų� 3�̻��϶� 
	{
		printf("�г� �߸� �Է�<���� 1~3�г�>");
		system("pause");
		printf("�г� �Է�<1~3> : ");
		scanf("%d", &St->Class);
	}

}

//�л���� �г��
void ShowClass(Student* St[], int StudentCount, int Class)
{
	//�г��� �Է¹ް� ���г��̶� ���� �г⸸ ���!!
	//��ü ����� ���ο��� 1���� 3�г���� ���� 
	printf("����������������������������������%d �г⦡��������������������������������\n", Class);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == Class)
		{
			ShowStudent(St[i]);
		}
	}
	printf("��������������������������������������������������������������������������\n");
}

//�̸� �˻�
void NameSearch(Student* St[], int StudentCount)
{
	char nameCheck[10];
	printf("�˻��� �̸� �Է� : ");

	//���ڿ� �� �Լ� > �� ���ڿ��� ������ 0�� �����!!
	//strcmp(Name1, Name2);
	scanf("%s", nameCheck);
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St[i]->Name, nameCheck) == 0)
		{
			ShowStudent(St[i]);
		}
	}
}

void LoadStudent() 
{

}

void main()
{
	Student* Student_List[MAX]; //�л� ����ü�� "�ּҸ� ����" ������ �迭 50���� ���� Student_List�� ����Ʈ ���� 4x50�� 200��
	//����ü Student�� ũ��� ���� 36 ����Ʈ���� Student_List�� ĭ�� 4����Ʈ(�ּҸ� ������ 4����Ʈ ����)
	int Select;
	int StudentCount = 0; //���ο�
	FILE* f;
	int loadnum;

	while (1)
	{
		system("cls");
		printf("=====�л��������α׷�=====(�� �ο� : %d)\n", StudentCount);
		printf("1.�л� ���\n");
		printf("2.�л� ���(��ȣ��)\n");
		printf("3.�л� ���(�г��)\n");
		printf("4.�г� �˻�\n");
		printf("5.�л� �˻�\n");
		printf("6.������ �л� ����\n");
		printf("7.�л� ��ü ����\n");
		printf("8.�л����� ����\n");
		printf("9.�л����� �ҷ�����\n");
		printf("10.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);

		switch (Select)
		{
			//�л� ���
		case 1:
			if (StudentCount + 1 >= MAX)
			{
				printf("�л�����(50��)�� ��� á���ϴ�.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student)); //�л�����ü�� �����ŭ ���� �Ҵ� > �� �ּҸ� n��° �迭�� ����
			SetStudent(Student_List[StudentCount], &StudentCount); //Student_List[StudentCount]�� �ּҸ� ������ ���� / StudentCount�� �ƴϴ� & ����
			break;
			//�л� ���(��ȣ��) ���
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)//���� �л� �� ��ŭ ���
				ShowStudent(Student_List[i]);
			system("pause");
			break;
			//�л� ���(�г��) ���
		case 3:
			system("cls");
			for (int i = 1; i <= 3; i++)
			{
				ShowClass(Student_List, StudentCount, i);
			}
			system("pause");
			break;
			//�г� �˻�
		case 4: //�߸��ԷµǸ� �����ϰ� �ٽ� ó������ ��� �̴� �ƿ� while�� �ȿ� �־������
			system("cls");
			while (1)
			{
				printf("�˻��� �г� �Է�(1~3) : ");
				scanf("%d", &Select);
				if (Select <= 3 && Select >= 1) //3 �̻� 1���� �϶� �ٷ� ���
				{
					break;
				}
				printf("�г� �߸� �Է�(���� 1~3�г�)\n");
				system("pause");
			}
			ShowClass(Student_List, StudentCount, Select);
			system("pause");
			break;
			//�л� �˻�
		case 5:
			system("cls");
			NameSearch(Student_List, StudentCount);
			system("pause");
			break;
			//������ �л� ����
		case 6:
			//�л��� 0 �� �ƴҶ� �� �������� ���� �л� ���� ����
			//�����Ҵ� �����ϰ� �迭�� NULL�� ����ְ� StudentCount�� �ϳ� ���ҽ�Ŵ
			if (StudentCount <= 0)
			{
				printf("�� �̻� ������ �л��� �����ϴ�.\n");
				system("pause");
			}
			else
			{
				//���� ���� �Ʒ����� ������ StudentCount-1 �� �ʿ䰡 ����
				StudentCount -= 1;
				free(Student_List[StudentCount]);
				Student_List[StudentCount] = NULL;
			}
			break;
			//�л� ��ü ����
		case 7:
			for (int i = 0; i < StudentCount; i++)//���� �Ҵ��ߴ� �ּҸ� �ϳ��� Ǯ����
			{
				free(Student_List[i]);
				Student_List[i] = NULL;
			}
			StudentCount = 0;
			break;
			//�л����� ����
		case 8:
			f = fopen("�л�����.txt", "w");
			//�л��� ����
			fprintf(f, "%d\n", StudentCount);
			for (int i = 0; i < StudentCount; i++)
			{
				fprintf(f, "%s %d %d %s\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Class, Student_List[i]->Gender);
			}
			fclose(f);
			printf("���� �Ϸ�!!");
			system("pause");
			break;
			// �л����� �ҷ�����
		case 9:
			//�л��� ���������� �ϳ��� �ҷ���
			//������ ������ �� �ο���/n �̸� ���� �г� ���� ��
			f = fopen("�л�����.txt", "r");
			if (f == NULL)
			{
				printf("����� �л������� �����ϴ�.");
				system("pause");
				break;
			}

			fscanf(f, "%d", &loadnum); //�ο����� �󸶳� �ִ������� ��

			for (int i = 0; i < loadnum && !feof(f); i++)
			{
				if (StudentCount + 1 > MAX)
				{
					printf("���̻� �л��� �ҷ��� �� �����ϴ�");
					system("pause");
					break;
				}

				Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
				fscanf(f, "%s", Student_List[StudentCount]->Name);
				fscanf(f, "%d", &(Student_List[StudentCount]->Age));
				fscanf(f, "%d", &(Student_List[StudentCount]->Class));
				fscanf(f, "%s", Student_List[StudentCount]->Gender);
				Student_List[StudentCount]->Number = StudentCount + 1;
				StudentCount++;
			}
			fclose(f);
			break;
		case 10://�����Ҷ��� �����Ҵ� �����ϴ°� �����ʱ�
			for (int i = 0; i < StudentCount; i++)
			{
				free(Student_List[i]); //Student_List �� ��¥�� ���������� ���α׷��� ���� �ڵ����� �����
			}
			return;
		}
	}
}
