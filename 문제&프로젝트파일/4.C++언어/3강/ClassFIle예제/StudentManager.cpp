#include "StudentManager.h"

StudentManager::StudentManager()//������
{
}

void StudentManager::AddStudent()//�л� �߰�
{
	if (m_iStudentCount < STUDENT_MAX)//�л��� �ִ�ġ�� �ƴ϶��
	{
		m_StudentList[m_iStudentCount].SetStudent(m_iStudentCount + 1);//m_iStudentCount+1 �ؼ� ���������ν� 0���л��ξƴ� 1�� �л����� ����
		m_iStudentCount++;//�л� �߰� �� m_iStudentCount+1 ����
	}
	else
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
}

void StudentManager::ShowStudentList() //��ü�л����
{
	for (int i = 0; i < m_iStudentCount; i++)//���� �ִ� ��� �л� ���
		m_StudentList[i].ShowStudent();//�ش� �迭�� ��� Ŭ������ ShowStudent�Լ��� �۵���
}

bool StudentManager::FindStudentName(string Name)//�л� �̸� ã��
{
	bool Flag = false;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetName() == Name)//ã����
		{
			m_StudentList[i].ShowStudent();//���
			Flag = true;
		}
	}
	return Flag;
}

StudentManager::~StudentManager()//�Ҹ���
{
}
