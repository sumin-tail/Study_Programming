#include <iostream>
#include <string>
#include<Windows.h>

using namespace std;
//�л��� �̸�,����,�г�,��ȣ,������ �����ϴ� ����ü�� ���� �� �����Ҵ����� �����Ͻÿ�   
//(�ִ� �л��� 10��) / (90���̻� A, 80���̻� B, 70���̻� C, 60���̻� D, 60���̸� F) / ���� ���� ���� ���� ��� ���� ���� 

//�Լ�ȭ �� #define �ϱ�!!
#define MAX 10

typedef struct Student
{
	string name; //�̸�
	int age; //����
	int grade;//�г�
	//������ ����
	int korean;
	int math;
	int english;
	//��ũ
	int max;
	float average;
	char rank;
}Student;

void Menu(int StudentCount)
{
	cout << "===�л���������===(�л��� : " << StudentCount << "��)" << endl;
	cout << "   1.�л����" << endl;
	cout << "   2.�л����� ����" << endl;
	cout << "   3.�л��˻�" << endl;
	cout << "   4.��޺� ����" << endl;
	cout << "   5.�г⺰ ����" << endl;
	cout << "   6.����" << endl;
	cout << " �Է� : " << endl;
}

void Student_Print(Student newS, int StudentCount)
{
	cout << "    ======" << StudentCount << "��° �л�======" << endl;
	cout << "    �̸� : " << newS.name << endl;
	cout << "    ���� : " << newS.age <<"��"<< endl;
	cout << "    �г� : " << newS.grade <<"�г�" <<endl;
	cout << "    �������� : " << newS.korean << endl;
	cout << "    �������� : " << newS.math << endl;
	cout << "    �������� : " << newS.english << endl;
	cout << "    �հ����� : " << newS.max << "   ������� : " << newS.max << endl;
	cout << "    ��� : [" << newS.rank << "]" << endl << endl;
}

void Student_Print_Rank(Student* newS[], char rank, int StudentCount)
{
	cout <<"����������������������������������"<< rank <<" ��ަ���������������������������������" << endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->rank == rank)
		{
			Student_Print(*newS[i], i);
		}
	}
	cout << "��������������������������������������������������������������������������"<< endl;
}

void Student_Print_Grade(Student* newS[], char grade, int StudentCount)
{
	cout << "����������������������������������" << grade << " �г⦡��������������������������������" << endl;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->grade == grade)
		{
			Student_Print(*newS[i], i);
		}
	}
	cout << "��������������������������������������������������������������������������" << endl;
}

void Student_Rank(Student* Node)
{
	Node->max = Node->korean + Node->english + Node->math; //�հ�����
	Node->average = (float)Node->max / 3;
	if (Node->average >= 90)
	{
		Node->rank = 'A';
	}
	else if (Node->average >= 80)
	{
		Node->rank = 'B';
	}
	else if (Node->average >= 70)
	{
		Node->rank = 'C';
	}
	else if (Node->average >= 60)
	{
		Node->rank = 'D';
	}
	else
	{
		Node->rank = 'F';
	}
}

void Student_Add(Student* newS, int StudentCount)
{
	cout << "======"<< StudentCount <<"��° �л�======" << endl;
	cout << "�̸� : ";
	cin >> newS->name;
	cout << "���� : ";
	cin >> newS->age;
	do
	{
		cout << "�г�<1~3> : ";
		cin >> newS->grade;
		if (newS->grade <= 3 && newS->grade >= 1)
		{
			break;
		}
		cout << "�߸� �Է� �ٽ�" << endl;
	} while (newS->grade > 3 || newS->grade < 1);
	cout << "�������� : ";
	cin >> newS->korean;
	cout << "�������� : ";
	cin >> newS->math;
	cout << "�������� : ";
	cin >> newS->english;
	Student_Rank(newS);
}

void Student_Search(Student* newS[],int StudentCount)
{
	string name;
	cout << "�̸� �Է� : ";
	cin >> name;
	for (int i = 0; i < StudentCount; i++)
	{
		if (newS[i]->name == name)
		{
			Student_Print(*newS[i], i);
			return;
		}
	}
	cout << "�ش� �л��� �����ϴ�."<<endl;
}

void main()
{
	int Select, StudentCount = 0;
	Student *Student_List[MAX];
	while (1)
	{
		system("cls");
		Menu(StudentCount);
		cin >> Select;
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount < MAX) //�л��� ���� �̸��϶�
			{
				Student_List[StudentCount] = new Student; //���� �Ҵ�
				Student_Add(Student_List[StudentCount], StudentCount);//�л� �߰�
				StudentCount++; //�л� ī��Ʈ ����
			}
			system("pause");
			break;
		case 2: //�л� ��� ���
			system("cls");
			for (int i = 0; i < StudentCount; i++)
			{
				Student_Print(*Student_List[i], i);
			}
			system("pause");
			break;
		case 3: //�л� �˻�
			system("cls");
			Student_Search(Student_List, StudentCount);
			system("pause");
			break;
		case 4: //��޺� ����
			system("cls");
			for (char rank = 'A'; rank <= 'F'; rank++)
			{
				Student_Print_Rank(Student_List, rank, StudentCount);
			}
			system("pause");
			break;
		case 5: //�г⺰ ����
			system("cls");
			for (int grade = 1; grade <= 3; grade++)
			{
				Student_Print_Grade(Student_List, grade, StudentCount);
			}
			system("pause");
			break;
		case 6: //����- �Ҵ����� ��ų��
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i + 1 << "�� �л� : " << Student_List[i]->name << endl;
				delete Student_List[i];
				cout << "�Ҵ� ���� �Ϸ�" << endl;
			}
			system("pause");
			return;
		}
	}
}
