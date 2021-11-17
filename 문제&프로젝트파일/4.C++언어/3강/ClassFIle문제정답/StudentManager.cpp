#include "StudentManager.h"



StudentManager::StudentManager()
{
}

//학생 추가
void StudentManager::AddStudent()
{
	if (m_iStudentCount < STUDENT_MAX)
	{
		m_StudentList[m_iStudentCount] = new Student; //할당해서 집어넣고
		m_StudentList[m_iStudentCount]->SetStudent(m_iStudentCount + 1); //정보 갱신함
		m_iStudentCount++;
	}
	else
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
}
//전체 학생 출력
void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i]->ShowStudent();
}
//학생검색(이름)
bool StudentManager::FindStudentName(string Name)
{
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetName() == Name)
		{
			m_StudentList[i]->ShowStudent();
			return true; 
		}
	}
	return false;
}
//학생 검색(학년)
bool StudentManager::ShowStudentClass(CLASS Class)
{
	bool State = false;
	cout << "┌─────" << (int)Class << " 학년─────┐" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetClass() == Class)
		{
			m_StudentList[i]->ShowStudent();
			State = true;
		}
	}
	cout << "└─────────────┘" << endl;
	return State;
}

//마지막 학생 삭제
void StudentManager::DeleteStudent()
{
	if (m_iStudentCount < 1)
		cout << "삭제할 학생이 없습니다." << endl;
	else
	{
		m_iStudentCount--; //카운트 줄이기
		m_StudentList[m_iStudentCount]->ShowStudent(); //출력하고
		free(m_StudentList[m_iStudentCount]); //할당 해제 시켜줌
		m_StudentList[m_iStudentCount] = NULL; //값이 들어있던 칸 비움
		cout << "삭제 완료" << endl;
	}
}
void StudentManager::ClearStudent()
{
	for (int i = 0; i < m_iStudentCount; i++)
	{
		free(m_StudentList[i]);
		m_StudentList[i] = NULL;
	}
	m_iStudentCount = 0;
}

StudentManager::~StudentManager()
{
}
