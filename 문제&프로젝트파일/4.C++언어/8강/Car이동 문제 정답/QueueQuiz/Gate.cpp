#include "Gate.h"



Gate::Gate()
{
	m_pFront = NULL;
	m_pRear = NULL; //초기화
	m_iCreateTimer = clock(); //만들어진 시간 저장
	CreateCar(); //시작과 동시에 차 하나를 만듬
}

void Gate::Update()
{
	Input();
	Enqueue();
	if (m_pFront != NULL && m_pFront->DeququqCheck())// 만약 m_pFront이 NULL이 아니고 m_pFront의 자동차가 끝에 닿았다면
	{
		m_pFront->EraseCar(); //차를 지우고
		Dequeue();
	}
	Car* Temp = m_pFront;
	if(Temp != NULL)
		Temp->Move();
}


void Gate::Input()
{
	if (kbhit())//키 입력이 들어왔는지
	{
		char ch = getch(); //들어왔고 그게 스페이스바라면
		if (ch == SPACE)
		{
			Car* Temp = m_pFront;
			if (Temp != NULL)
				Temp->ChangeSpeed();//스피드 바꿈
		}
	}
}

void Gate::CreateCar()
{
	Car* temp = new Car;
	if (m_pFront == NULL)//만약m_pFront가 NULl일경우
	{
		m_pFront = temp; //새로만든 차 주소 전방화 후방에 저장해줌
		m_pRear = temp;
	}
	else //아니라면
	{
		m_pRear->SetNext(temp);//m_pRear에 있는 카의 Next에 새로 만든 차 주소 넣어주고
		m_pRear = temp; //m_pRear갱신
	}
	m_iCreateTimer = clock(); //m_iCreateTimer 갱신
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
		m_pFront = m_pFront->GetNext();//다음차 받음
		if (m_pFront == NULL) //다음차가 없으면
			m_pRear = NULL; //m_pRear도 NULL처리
	}
}

Gate::~Gate()
{
}
