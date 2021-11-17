#include "Student.h"//학생 헤더 받아옴

Student::Student() //생성자
{
}

//학생추가
void Student::SetStudent(int Number) //학생정보입력
{
	int Tmp;
	bool State = true;
	m_iNumber = Number;
	cout << m_iNumber << "번 학생 정보" << endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;
	State = true;
	while (State)//상태가 true일때 계속 돔 > 학년 체크
	{
		cout << "학년 : ";
		cin >> Tmp;
		m_eClass = (CLASS)Tmp;
		switch (m_eClass)
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			State = false;//들어온 숫자가 1,2,3 일때는 상태를 false로 바꾸고 계속 돔
			break;
		default:
			cout << "잘못 입력하셧습니다.(1~3)" << endl;
			break;
		}
	}
	State = true;//상태를 다시 true로 바꾸고 > 성별체크
	while (State)
	{
		cout << "성별(남자 0,여자 1) : ";
		cin >> Tmp;
		m_eGender = (GENDER)Tmp; //형변환하는 것을 잊지말자

		switch (m_eGender)
		{
		case GENDER_MAN:
		case GENDER_WOMAN:
			State = false;
			break;
		default:
			cout << "잘못 입력하셧습니다.(0,1)" << endl;
			break;
		}
	}
}

//학생출력
void Student::ShowStudent()//학생 정보 출력
{
	cout << "====" << m_iNumber << "번 학생====" << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "나이 : " << m_iAge << endl;
	cout << "성별 : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "남자" << endl;
		break;
	case GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
	cout << "학년 : " << (int)m_eClass << endl << endl;
}

Student::~Student()//소멸자
{
}
