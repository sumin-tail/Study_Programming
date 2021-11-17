#include "StudentManager.h"

StudentManager::StudentManager()//생성자
{
}

void StudentManager::AddStudent()//학생 추가
{
	if (m_iStudentCount < STUDENT_MAX)//학생이 최대치가 아니라면
	{
		m_StudentList[m_iStudentCount].SetStudent(m_iStudentCount + 1);//m_iStudentCount+1 해서 보내줌으로써 0번학생인아닌 1번 학생부터 만듬
		m_iStudentCount++;//학생 추가 후 m_iStudentCount+1 해줌
	}
	else
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
}

void StudentManager::ShowStudentList() //전체학생출력
{
	for (int i = 0; i < m_iStudentCount; i++)//현재 있는 모든 학생 출력
		m_StudentList[i].ShowStudent();//해당 배열에 담긴 클래스의 ShowStudent함수가 작동함
}

bool StudentManager::FindStudentName(string Name)//학생 이름 찾기
{
	bool Flag = false;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i].GetName() == Name)//찾으면
		{
			m_StudentList[i].ShowStudent();//출력
			Flag = true;
		}
	}
	return Flag;
}

StudentManager::~StudentManager()//소멸자
{
}
