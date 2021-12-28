#pragma once
#include "Mecro.h"

class News : public Subject 
{
	static News* m_Instance;
	string m_Time; //��¥����
	string m_News; //��������
	vector <Observer*> m_ObserverList;//������ vector ����
	News() { }
public:
	~News() { }
	static News* get_instance()
	{
		if (NULL == m_Instance) m_Instance = new News;
		return m_Instance;
	}
	void Add(Observer* observer); //������ �߰��Լ�(����)
	void Update(); //������ ���� ������Ʈ �Լ�(����)
	void NewsUpdate(); //News ���� ������Ʈ �Լ�
	void Print(); //�������� ���� ��� �Լ�
	string CurrentDateTime(); //���� �ð� �޴� �Լ�.
};

