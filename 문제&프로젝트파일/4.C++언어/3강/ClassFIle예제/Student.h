#pragma once
#include<iostream>
#include<string>
using namespace std;

enum GENDER //������-����
{
	GENDER_MAN,
	GENDER_WOMAN
};

enum CLASS //������-�г�
{
	CLASS_START = 1,
	CLASS_1 = 1,
	CLASS_2,
	CLASS_3,
	CLASS_END
};

class Student
{
private:
	string m_strName; //�̸�
	int m_iAge; //����
	GENDER m_eGender;//����
	CLASS m_eClass;//�г�
	int m_iNumber; //��ȣ
public:
	void SetStudent(int Number); //�л������Է�
	void ShowStudent();//�л����
	inline string GetName() //�л��̸� ����-�ζ���
	{
		return m_strName;
	}
	inline CLASS GetClass()//�л��г� ����-�ζ���
	{
		return m_eClass;
	}
	Student(); //������
	~Student(); //�Ҹ���
};


