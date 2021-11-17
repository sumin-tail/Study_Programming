#include "StudentManager.h"

StudentManager::StudentManager()//생성자
{
}

void StudentManager::AddStudent()//학생 추가
{
	if (m_StudentList.size() < STUDENT_MAX)//학생이 최대치가 아니라면
	{
		Student tmp;
		tmp.SetStudent(m_StudentList.size()+1);
		m_StudentList.push_back(tmp);
	}
	else 
	{
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
	}
}

void StudentManager::ShowStudentList() //전체학생출력(번호순)
{
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//현재 있는 모든 학생 출력
	{
		iter->ShowStudent();//해당 배열에 담긴 클래스의 ShowStudent함수가 작동함
	}
}

bool StudentManager::ShowClassList(int classNum) //입력된 학년 전체 출력
{
	bool Flag = false;
	cout <<"┌─────────── "<< classNum <<"학년───────────┐ " << endl;
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//해당하는 학년 출력
	{
		if (iter->GetClass() == classNum)
		{
			iter->ShowStudent();//해당 배열에 담긴 클래스의 ShowStudent함수를 작동시킴
			Flag = true;
		}
	}
	cout << "└────────────────────────────┘ " << endl;
	return Flag;
}

bool StudentManager::FindStudentName(string Name)//학생 이름 찾기
{
	bool Flag = false;
	for (iter = m_StudentList.begin(); iter != m_StudentList.end(); iter++)//해당하는 학년 출력
	{
		if (iter->GetName() == Name)
		{
			iter->ShowStudent();//해당 배열에 담긴 클래스의 ShowStudent함수를 작동시킴
			Flag = true;
		}
	}
	return Flag;
}

void StudentManager::Delete() //마지막 학생 삭제
{
	if (m_StudentList.empty())
	{
		cout << "삭제할 학생이 없습니다." << endl;
	}
	else 
	{
		m_StudentList.back().ShowStudent(); //삭제하기전 학생정보 출력
		m_StudentList.pop_back(); //(데이터 지워줌)
		cout << "삭제완료" << endl;
	}
}

void StudentManager::Relese() //전체 삭제
{
	m_StudentList.clear();
}


StudentManager::~StudentManager()//소멸자
{
}
