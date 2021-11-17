#pragma once //�ߺ� ��Ŭ��带 ������ ������ ������
#include"Student.h" //�л� ����� �޾ƿ�
#include <list>

#define STUDENT_MAX 10 //�л��ִ���� 10��

class StudentManager 
{
private: //�Ʒ� �Ѵ� �����ڸ��� �ʱ�ȭ��
	list<Student> m_StudentList; //�л� ����Ʈ
	list<Student>::iterator iter;//����Ʈ ������
public:
	void AddStudent();//�л� �߰�
	void ShowStudentList();//�л� ����Ʈ
	bool ShowClassList(int classNum);//�г� ����Ʈ
	void Relese();//�Ҵ�����
	void Delete();
	inline int GetStudentCount()//�л��� ����-�ζ���
	{
		return m_StudentList.size();
	}
	bool FindStudentName(string Name);//�л��̸� ã��
	StudentManager();//������
	~StudentManager();//�Ҹ���
};

