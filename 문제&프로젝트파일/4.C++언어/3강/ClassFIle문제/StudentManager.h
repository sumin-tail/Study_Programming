#pragma once //중복 인클루드를 했을때 오류를 막아줌
#include"Student.h" //학생 헤더를 받아옴
#include <list>

#define STUDENT_MAX 10 //학생최대수는 10명

class StudentManager 
{
private: //아래 둘다 만들자마자 초기화됨
	list<Student> m_StudentList; //학생 리스트
	list<Student>::iterator iter;//리스트 포인터
public:
	void AddStudent();//학생 추가
	void ShowStudentList();//학생 리스트
	bool ShowClassList(int classNum);//학년 리스트
	void Relese();//할당해제
	void Delete();
	inline int GetStudentCount()//학생수 리턴-인라인
	{
		return m_StudentList.size();
	}
	bool FindStudentName(string Name);//학생이름 찾기
	StudentManager();//생성자
	~StudentManager();//소멸자
};

