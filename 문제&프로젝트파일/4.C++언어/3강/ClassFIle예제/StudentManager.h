#pragma once //�ߺ� ��Ŭ��带 ������ ������ ������
#include"Student.h" //�л� ����� �޾ƿ�

#define STUDENT_MAX 10 //�л��ִ���� 10��

class StudentManager
{
private: //�Ʒ� �Ѵ� �����ڸ��� �ʱ�ȭ��
	int m_iStudentCount = 0; //�л� ī��Ʈ
	Student m_StudentList[STUDENT_MAX]; //�л� �迭
public:
	void AddStudent();//�л� �߰�
	void ShowStudentList();//�л� ����Ʈ
	inline int GetStudentCount()//�л��� ����-�ζ���
	{
		return m_iStudentCount;
	}
	bool FindStudentName(string Name);//�л��̸� ã��
	StudentManager();//������
	~StudentManager();//�Ҹ���
};

