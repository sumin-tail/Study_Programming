#include "Gate.h"



Gate::Gate()
{
	m_pFront = NULL;
	m_pRear = NULL; //�ʱ�ȭ
	m_iCreateTimer = clock(); //������� �ð� ����
	CreateCar(); //���۰� ���ÿ� �� �ϳ��� ����
}

void Gate::Update()
{
	Input();
	Enqueue();
	if (m_pFront != NULL && m_pFront->DeququqCheck())// ���� m_pFront�� NULL�� �ƴϰ� m_pFront�� �ڵ����� ���� ��Ҵٸ�
	{
		m_pFront->EraseCar(); //���� �����
		Dequeue();
	}
	Car* Temp = m_pFront;
	if(Temp != NULL)
		Temp->Move();
}


void Gate::Input()
{
	if (kbhit())//Ű �Է��� ���Դ���
	{
		char ch = getch(); //���԰� �װ� �����̽��ٶ��
		if (ch == SPACE)
		{
			Car* Temp = m_pFront;
			if (Temp != NULL)
				Temp->ChangeSpeed();//���ǵ� �ٲ�
		}
	}
}

void Gate::CreateCar()
{
	Car* temp = new Car;
	if (m_pFront == NULL)//����m_pFront�� NULl�ϰ��
	{
		m_pFront = temp; //���θ��� �� �ּ� ����ȭ �Ĺ濡 ��������
		m_pRear = temp;
	}
	else //�ƴ϶��
	{
		m_pRear->SetNext(temp);//m_pRear�� �ִ� ī�� Next�� ���� ���� �� �ּ� �־��ְ�
		m_pRear = temp; //m_pRear����
	}
	m_iCreateTimer = clock(); //m_iCreateTimer ����
}

void Gate::Enqueue()
{
	char ch;
	if (clock() - m_iCreateTimer >= CREATE_TIME)
	{
		CreateCar();
	}
}

void Gate::Dequeue()
{
	if (m_pFront != NULL)
	{
		Car* temp = m_pFront;
		m_pFront = m_pFront->GetNext();//������ ����
		if (m_pFront == NULL) //�������� ������
			m_pRear = NULL; //m_pRear�� NULLó��
	}
}

Gate::~Gate()
{
}
