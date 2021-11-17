#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("======%s�л�(%d��)======\n", St->Name, St->Number);
	printf("���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}

void SetStudent(Student* St, int* StudentCount)
{
	St->Number = ++(*StudentCount);//��ġ=���ϰ� ���� �ش� �л��� ��ȣ�� ����(����) 
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է� : ");
	scanf("%s", St->Name); // (*P).Name �� P->Name �� ����
	printf("���� �Է� : ");
	scanf("%d", &St->Age); 
	printf("���� �Է� : ");
	scanf("%s", St->Gender);
	printf("�г� �Է� : ");
	scanf("%d", &St->Class);
}

void main()
{
	Student* Student_List[MAX]; //�л� ����ü�� "�ּҸ� ����" ������ �迭 50���� ���� Student_List�� ����Ʈ ���� 4x50�� 200��
	//����ü Student�� ũ��� ���� 36 ����Ʈ���� Student_List�� ĭ�� 4����Ʈ(�ּҸ� ������ 4����Ʈ ����)
	int Select;
	int StudentCount = 0; //���ο�

	while (1)
	{
		system("cls");
		printf("=====�л��������α׷�=====(�� �ο� : %d)\n", StudentCount);
		printf("1.�л� ���\n");
		printf("2.�л� ���\n");
		printf("3.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);

		switch (Select)
		{
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
		case 2:
			for (int i = 0; i < StudentCount; i++)//���� �л� �� ��ŭ ���
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			for (int i = 0; i < StudentCount; i++)//���� �Ҵ��ߴ� �ּҸ� �ϳ��� Ǯ����
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}