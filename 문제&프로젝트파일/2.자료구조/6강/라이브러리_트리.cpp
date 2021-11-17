#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <map> 

typedef struct Student
{
	char name[10]; //�̸�
	int age; //����
	char address[30]; //�ּ�
	//������ ����
	int korean;
	int math;
	int english;
	//f��ũ
	int max;
	float average;
	char rank;
}Student;

void Menu()
{
	printf("< < < = = = = �޴� = = = = > > >\n");
	printf("1.�л� ���\n");
	printf("2.�л� �˻�\n");
	printf("3.�л� ���\n");
	printf("4.�л� ����\n");
	printf("5.�л� ����\n");
	printf("6.����\n");
	printf("====================\n");
	printf("���� : ");
}
//�л� ��ũ ���
Student Student_Rank(Student Node)
{
	Node.max = Node.korean + Node.english + Node.math; //�հ�����
	Node.average = (float)Node.max / 3;
	if (Node.average >= 90)
	{
		Node.rank = 'A';
	}
	else if (Node.average >= 80)
	{
		Node.rank = 'B';
	}
	else if (Node.average >= 70)
	{
		Node.rank = 'C';
	}
	else if (Node.average >= 60)
	{
		Node.rank = 'D';
	}
	else
	{
		Node.rank = 'F';
	}
	return(Node);
}
//�л��߰�
Student Student_Add()
{
	//�� �����Ҵ��ϰ� �ּ�����
	Student add;
	//�л������Է�
	printf("�л� �̸� �Է� : ");
	scanf("%s", add.name);
	printf("%s �л� ���� �Է� : ", add.name);
	scanf("%d", &add.age);
	printf("%s �л� �ּ� �Է� : ", add.name);
	scanf("%s", add.address);
	printf("%s �л� ���� ���� : ", add.name);
	scanf("%d", &add.korean);
	printf("%s �л� ���� ���� : ", add.name);
	scanf("%d", &add.english);
	printf("%s �л� ���� ���� : ", add.name);
	scanf("%d", &add.math);
	printf("�л� ���� �Է� �Ϸ�\n");
	return 	Student_Rank(add);//����ü�� ������
}
//�л��������
void Student_Information(std::map<int, Student>::iterator iter, std::map<int, Student>* iMap)
{
	if (iter == iMap->end())
	{
		printf("�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
		return;
	}

	printf("�л� ���� �˻� �Ϸ�\n");
	printf("< < = = = = = Information = = = = = > >\n");
	printf("�л� �й� : %d\n", iter->first);
	printf("�л� �̸� : %s\n", iter->second.name);
	printf("�л� ���� : %d ��\n", iter->second.age);
	printf("�л� �ּ� : %s\n", iter->second.address);
	printf("���� ���� : %d ��\n", iter->second.korean);
	printf("���� ���� : %d ��\n", iter->second.english);
	printf("���� ���� : %d ��\n", iter->second.math);
	printf("�հ� ���� : %d ��\n", iter->second.max);
	printf("��� ���� : %.2f ��\n", iter->second.average);
	printf("�л� ��� : %c ���\n", iter->second.rank);

}
//�л���ü���
void All_Student_Print(std::map<int, Student> iMap)
{
	for (std::map<int, Student>::iterator iter = iMap.begin(); iter != iMap.end(); iter++)
	{
		printf("\t  %s", iter->second.name);
		printf("\t%d", iter->second.age);
		printf("\t\t%s\n", iter->second.address);
	}
}
//�л�����
void Student_Retouch(std::map<int, Student>* iMap, std::map<int, Student>::iterator iter)
{
	int select = 0;
	int data;
	char change[30];

	if (iter == iMap->end())//�ش��л��� ���ٴ� ���̴� ����
	{
		printf("ã�� �л��� �����ϴ�.\n");
		return;
	}

	while (select != 5)
	{
		system("cls");
		Student_Information(iter, iMap);// �л� ������ ���
		printf("\n");
		printf("������ �׸��� ���� �Ͻÿ�\n");
		printf("1.�̸� 2.���� 3.�ּ� 4.���� 5.��������\n");
		printf("���� : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("���� �̸� : %s\n", iter->second.name);
			printf("������ �̸� : ");
			scanf("%s", &change);
			printf("%s -> %s �� �̸� ���� �Ϸ�\n", iter->second.name, change);
			strcpy(iter->second.name, change); //���ڿ��� ������ �ȵǴ� strcpy ���
			system("pause");
			break;
		case 2:
			printf("���� ���� : %d ��\n", iter->second.age);
			printf("������ ���� :    ��");
			printf("\b\b\b\b\b\b");
			scanf("%d", &data);
			printf("%d �� -> %d �� �� ���� ���� �Ϸ�\n", iter->second.age, data);
			iter->second.age = data;
			system("pause");
			break;
		case 3:
			printf("���� �ּ� : %s \n", iter->second.address);
			printf("������ �ּ� : ");
			scanf("%s", &change);
			printf("%s -> %s �� �ּ� ���� �Ϸ�\n", iter->second.address, change);
			strcpy(iter->second.address, change); //���ڿ�
			system("pause");
			break;
		case 4:
			printf("���� ����\n");
			printf("���� : %d ���� : %d ���� : %d\n", iter->second.korean, iter->second.english, iter->second.math);
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->second.korean = data;
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->second.english = data;
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->second.math = data;
			printf("���� ���� �Ϸ�\n");
			//��ũ����
			iter->second = Student_Rank(iter->second);
			system("pause");
			break;
		case 5:
			printf("������ �����մϴ�.\n");
			system("pause");
			break;
		}
	}

}

//�л� ����
void Student_Delete(std::map<int, Student>::iterator iter, std::map<int, Student>* iMap)
{
	if (iter == iMap->end())
	{
		printf("�ش��л� ����\n");
		system("pause");
		return;
	}
	iMap->erase(iter);
	printf("���� �Ϸ�\n");
	system("pause");
}

void main()
{
	std::map<int, Student> studentMap;
	std::map<int, Student>::iterator iter;
	int studentNum = 20210001;

	int select;
	int num;

	while (1)
	{
		system("cls");
		Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1: //�л����
			system("cls");
			printf("�й� : %d\n", studentNum);
			studentMap[studentNum++] = Student_Add();
			system("pause");
			break;
		case 2: //�л��˻�
			system("cls");
			printf("�˻��� �й� �Է� : ");
			scanf("%d", &num);
			Student_Information(studentMap.find(num), &studentMap);
			system("pause");
			break;
		case 3: //�л����
			system("cls");
			printf("< < = = = = = Information = = = = = > >\n");
			printf("\n");
			printf("\t�л��̸�\t�л�����\t�л��ּ�\n");
			All_Student_Print(studentMap);
			printf("<�л� �������� ������ �˻��� �̿��ϼ���!!>\n");
			system("pause");
			break;
		case 4: //�л�����
			system("cls");
			printf("������ �л� �й���? ");
			scanf("%d", &num);
			Student_Retouch(&studentMap, studentMap.find(num));
			break;
		case 5: //�л�����
			system("cls");
			if (studentMap.empty())
			{
				printf("�ƹ��� �����Ͱ� �����ϴ�.\n");
				system("pause");
				break;
			}
			printf("������ �л� �й�: ");
			scanf("%d", &num);
		    Student_Delete(studentMap.find(num), &studentMap);
			break;
		case 6: //���� - ���̺귯���� �˾Ƽ� �Ҵ����� ����
			printf("�Ҵ� ���� �Ϸ�");
			return;
		}
	}
}