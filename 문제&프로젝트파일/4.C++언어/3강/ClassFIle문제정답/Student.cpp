#include "Student.h"

Student::Student()
{
}

//학생 설정(정보 추가)
void Student::SetStudent(int Number)
{
	int Tmp;
	bool State = true;
	m_iNumber = Number;
	cout << Number << "번 학생 정보" << endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;
	State = true;
	while (State) //학년 설정 반복문 효율 좋음 < 기억해둘것
	{
		cout << "학년 : ";
		cin >> Tmp;
		m_eClass = (CLASS)Tmp;
		switch (m_eClass) //스위치 문은 브레이크가 없으면 주르륵 내려가면서 실행한다는걸 잘 알고 잇을것
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			State = false;
			break;
		default:
			cout << "잘못 입력하셧습니다.(1~3)" << endl;
			break;
		}
	}
	State = true;
	while (State)
	{
		cout << "성별(남자 0,여자 1) : ";
		cin >> Tmp;
		m_eGender = (GENDER)Tmp; //항상 형변환 하는 것을 잊지 말자
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

//학생 출력
void Student::ShowStudent()
{
	cout << "    ====" << m_iNumber << "번 학생====" << endl;
	cout << "    이름 : " << m_strName << endl;
	cout << "    나이 : " << m_iAge << endl;
	cout << "    성별 : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "남자" << endl;
		break;
	case GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
	cout << "    학년 : " << (int)m_eClass << endl << endl; //인트 형으로 출력해야하니까 앞에 형변환 함 > 빼도 오류나지 않고 넣은 값에 맞는 숫자가 출력되긴 함
}

Student::~Student()
{
}
