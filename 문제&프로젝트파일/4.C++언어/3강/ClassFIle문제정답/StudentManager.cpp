#include "StudentManager.h"



StudentManager::StudentManager()
{
}

//�л� �߰�
void StudentManager::AddStudent()
{
	if (m_iStudentCount < STUDENT_MAX)
	{
		m_StudentList[m_iStudentCount] = new Student; //�Ҵ��ؼ� ����ְ�
		m_StudentList[m_iStudentCount]->SetStudent(m_iStudentCount + 1); //���� ������
		m_iStudentCount++;
	}
	else
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
}
//��ü �л� ���
void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i]->ShowStudent();
}
//�л��˻�(�̸�)
bool StudentManager::FindStudentName(string Name)
{
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetName() == Name)
		{
			m_StudentList[i]->ShowStudent();
			return true; 
		}
	}
	return false;
}
//�л� �˻�(�г�)
bool StudentManager::ShowStudentClass(CLASS Class)
{
	bool State = false;
	cout << "������������" << (int)Class << " �г⦡����������" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetClass() == Class)
		{
			m_StudentList[i]->ShowStudent();
			State = true;
		}
	}
	cout << "������������������������������" << endl;
	return State;
}

//������ �л� ����
void StudentManager::DeleteStudent()
{
	if (m_iStudentCount < 1)
		cout << "������ �л��� �����ϴ�." << endl;
	else
	{
		m_iStudentCount--; //ī��Ʈ ���̱�
		m_StudentList[m_iStudentCount]->ShowStudent(); //����ϰ�
		free(m_StudentList[m_iStudentCount]); //�Ҵ� ���� ������
		m_StudentList[m_iStudentCount] = NULL; //���� ����ִ� ĭ ���
		cout << "���� �Ϸ�" << endl;
	}
}
void StudentManager::ClearStudent()
{
	for (int i = 0; i < m_iStudentCount; i++)
	{
		free(m_StudentList[i]);
		m_StudentList[i] = NULL;
	}
	m_iStudentCount = 0;
}

StudentManager::~StudentManager()
{
}
