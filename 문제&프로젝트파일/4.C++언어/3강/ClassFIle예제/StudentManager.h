#pragma once //중복 인클루드를 했을때 오류를 막아줌
#include"Student.h" //학생 헤더를 받아옴

#define STUDENT_MAX 10 //학생최대수는 10명

class StudentManager
{
private: //아래 둘다 만들자마자 초기화됨
	int m_iStudentCount = 0; //학생 카운트
	Student m_StudentList[STUDENT_MAX]; //학생 배열
public:
	void AddStudent();//학생 추가
	void ShowStudentList();//학생 리스트
	inline int GetStudentCount()//학생수 리턴-인라인
	{
		return m_iStudentCount;
	}
	bool FindStudentName(string Name);//학생이름 찾기
	StudentManager();//생성자
	~StudentManager();//소멸자
};

