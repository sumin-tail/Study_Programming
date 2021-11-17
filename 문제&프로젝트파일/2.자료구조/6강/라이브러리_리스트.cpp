#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <list> 

typedef struct Student
{
	char name[10]; //�̸�
	int age; //����
	char address[30]; //�ּ�
	//������ ����
	int korean;
	int math;
	int english;
	//
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
	//������ �л� �߰� �� Student* Node �� �޾ƿͼ� ����
	//�л� ���� ������ ������ �ٲ�-> ��ũ ���� 
	//iter�� Student* Node���·� �ٲ� ��� ??
	// >�Ķ���͸� std::list<Student>::iterator Node ���·� �ٲ� �л� �߰��� ���ο��� --studentList.end() ������
	// �����߰��� �л��� ���� �������� == studentList.end()�� �ٷ� �� �ּҿ� ���� > ���� (--��ġ) ������
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
	return Node;
}
//�л��߰�
Student Student_Add()
{
	//�� �����Ҵ��ϰ� �ּ�����
	Student add;
	//�л������Է�
	system("cls");
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
	return Student_Rank(add);//����ü�� ������
}
//�л� �˻�
std::list<Student>::iterator Student_Search(std::list<Student>* iList, char name[])
{
	for (std::list<Student>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (strcmp(iter->name, name) == 0)//�̸������� üũ
		{
			printf("�л� ���� �˻� �Ϸ�\n");
			return iter; //������ �ּ� ������
		}
	}

	return iList->end(); //������ end ������
}
//�л��������
void Student_Information(std::list<Student>::iterator iter, std::list<Student>* iList)
{
	if (iter == iList->end())
	{
		printf("�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
		return;
	}

	printf("< < = = = = = Information = = = = = > >\n");
	printf("�л� �̸� : %s\n", iter->name);
	printf("�л� ���� : %d ��\n", iter->age);
	printf("�л� �ּ� : %s\n", iter->address);
	printf("���� ���� : %d ��\n", iter->korean);
	printf("���� ���� : %d ��\n", iter->english);
	printf("���� ���� : %d ��\n", iter->math);
	printf("�հ� ���� : %d ��\n", iter->max);
	printf("��� ���� : %.2f ��\n", iter->average);
	printf("�л� ��� : %c ���\n", iter->rank);

}
//�л���ü���
void All_Student_Print(std::list<Student> iList)
{
	for (std::list<Student>::iterator iter = iList.begin(); iter != iList.end(); iter++) //begin()�� ���� �ּ����� end()�� ������ �����ּ��� (������ �ּ� �ƴ�)
	{
		printf("\t  %s", iter->name);
		printf("\t%d", iter->age);
		printf("\t\t%s\n", iter->address);
	}
}
//�л�����
void Student_Retouch(std::list<Student>* iList, char name[])
{
	int select = 0;
	int data;
	char change[30];

	std::list<Student>::iterator iter = Student_Search(iList, name);

	if (iter == iList->end())//�ش��л��� ���ٴ� ���̴� ����
	{
		printf("ã�� �л��� �����ϴ�.\n");
		return;
	}

	while (select != 5)
	{
		system("cls");
		Student_Information(iter, iList);// �л� ������ ���
		printf("\n");
		printf("������ �׸��� ���� �Ͻÿ�\n");
		printf("1.�̸� 2.���� 3.�ּ� 4.���� 5.��������\n");
		printf("���� : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("���� �̸� : %s\n", iter->name);
			printf("������ �̸� : ");
			scanf("%s", &change);
			printf("%s -> %s �� �̸� ���� �Ϸ�\n", iter->name, change);
			strcpy(iter->name, change); //���ڿ��� ������ �ȵǴ� strcpy ���
			system("pause");
			break;
		case 2:
			printf("���� ���� : %d ��\n", iter->age);
			printf("������ ���� :    ��");
			printf("\b\b\b\b\b\b");
			scanf("%d", &data);
			printf("%d �� -> %d �� �� ���� ���� �Ϸ�\n", iter->age, data);
			iter->age = data;
			system("pause");
			break;
		case 3:
			printf("���� �ּ� : %s \n", iter->address);
			printf("������ �ּ� : ");
			scanf("%s", &change);
			printf("%s -> %s �� �ּ� ���� �Ϸ�\n", iter->address, change);
			strcpy(iter->address, change); //���ڿ�
			system("pause");
			break;
		case 4:
			printf("���� ����\n");
			printf("���� : %d ���� : %d ���� : %d\n", iter->korean, iter->english, iter->math);
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->korean = data;
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->english = data;
			printf("������ ���� ���� : ");
			scanf("%d", &data);
			iter->math = data;
			printf("���� ���� �Ϸ�\n");
			//��ũ����
			*iter = Student_Rank(*iter);
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
void Student_Delete(std::list<Student>::iterator iter, std::list<Student>* iList)
{
	iList->erase(iter);
	printf("���� �Ϸ�\n");
	system("pause");
}

void main()
{
	std::list<Student> studentList; //�л� ����ü�� ����Ʈ�� 
	std::list<Student>::iterator iter;
	int select;
	int num;
	char searchname[10];
	while (1)
	{
		system("cls");
		Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1: //�л����
			studentList.push_back(Student_Add());//���ϵ� ����ü�� �޾Ƽ� push_back ��
			system("pause");
			break;
		case 2: //�л��˻�
			system("cls");
			printf("�˻��� �̸� �Է� : ");
			scanf("%s", searchname);
			Student_Information(Student_Search(&studentList, searchname), &studentList);
			system("pause");
			break;
		case 3: //�л����
			system("cls");
			printf("< < = = = = = Information = = = = = > >\n");
			printf("\n");
			printf("\t�л��̸�\t�л�����\t�л��ּ�\n");
			All_Student_Print(studentList);
			printf("<�л� �������� ������ �˻��� �̿��ϼ���!!>\n");
			system("pause");
			break;
		case 4: //�л�����
			system("cls");
			printf("������ �л� �̸���? ");
			scanf("%s", searchname);
			Student_Retouch(&studentList, searchname);
			break;
		case 5: //�л�����
			system("cls");
			if (studentList.empty())
			{
				printf("�ƹ��� �����Ͱ� �����ϴ�.\n");
				system("pause");
				break;
			}
			printf("������ �л� �̸�: ");
			scanf("%s", searchname);
			iter = Student_Search(&studentList, searchname);
			if (iter != studentList.end())
			{
				Student_Delete(iter, &studentList);
			}
			break;
		case 6: //���� - ���̺귯���� �˾Ƽ� �Ҵ����� ����
			printf("�Ҵ� ���� �Ϸ�");
			return;
		}
	}
}