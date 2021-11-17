#include "StudentManager.h"

StudentManager::StudentManager()//������
{
}

void StudentManager::AddStudent()//�л� �߰�
{
	if (m_StudentList.size() < STUDENT_MAX)//�л��� �ִ�ġ�� �ƴ϶��
	{
		Student tmp;
		tmp.SetStudent(m_StudentList.size()+1);
		m_StudentList.push_back(tmp);
	}
	else 
	{
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
	}
}

void StudentManager::ShowStudentList() //��ü�л����(��ȣ��)
{
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//���� �ִ� ��� �л� ���
	{
		iter->ShowStudent();//�ش� �迭�� ��� Ŭ������ ShowStudent�Լ��� �۵���
	}
}

bool StudentManager::ShowClassList(int classNum) //�Էµ� �г� ��ü ���
{
	bool Flag = false;
	cout <<"������������������������ "<< classNum <<"�г⦡���������������������� " << endl;
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//�ش��ϴ� �г� ���
	{
		if (iter->GetClass() == classNum)
		{
			iter->ShowStudent();//�ش� �迭�� ��� Ŭ������ ShowStudent�Լ��� �۵���Ŵ
			Flag = true;
		}
	}
	cout << "������������������������������������������������������������ " << endl;
	return Flag;
}

bool StudentManager::FindStudentName(string Name)//�л� �̸� ã��
{
	bool Flag = false;
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//�ش��ϴ� �г� ���
	{
		if (iter->GetName() == Name)
		{
			iter->ShowStudent();//�ش� �迭�� ��� Ŭ������ ShowStudent�Լ��� �۵���Ŵ
			Flag = true;
		}
	}
	return Flag;
}

void StudentManager::Delete() //������ �л� ����
{
	if (m_StudentList.empty())
	{
		cout << "������ �л��� �����ϴ�." << endl;
	}
	else 
	{
		m_StudentList.back().ShowStudent(); //�����ϱ��� �л����� ���
		m_StudentList.pop_back(); //(������ ������)
		cout << "�����Ϸ�" << endl;
	}
}

void StudentManager::Relese() //��ü ����
{
	m_StudentList.clear();
}


StudentManager::~StudentManager()//�Ҹ���
{
}
